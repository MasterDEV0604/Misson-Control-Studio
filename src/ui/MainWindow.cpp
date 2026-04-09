#include "ui/MainWindow.h"
#include <QCloseEvent>
#include <QDockWidget>
#include <QFileDialog>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include "ui/dialogs/ExportDialog.h"
#include "ui/dialogs/ScenarioEditorDialog.h"
#include "ui/dialogs/SettingsDialog.h"
#include "ui/dialogs/AlertRulesDialog.h"
#include "ui/dialogs/SessionManagerDialog.h"
#include "ui/dialogs/WorkspaceLayoutDialog.h"
#include "ui/widgets/AlertsWidget.h"
#include "ui/widgets/EventLogWidget.h"
#include "ui/widgets/HealthPanelWidget.h"
#include "ui/widgets/InspectorWidget.h"
#include "ui/widgets/LayerControlWidget.h"
#include "ui/widgets/MapCanvas.h"
#include "ui/widgets/NotesWidget.h"
#include "ui/widgets/BookmarkWidget.h"
#include "ui/widgets/SummaryStripWidget.h"
#include "ui/widgets/ValidationPanelWidget.h"
#include "ui/widgets/PlannerWidget.h"
#include "ui/widgets/ScenarioBrowserWidget.h"
#include "ui/widgets/TimelineWidget.h"
#include "ui/widgets/TrackTableWidget.h"

namespace missionx {
MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
    setWindowTitle("Mission Control Studio Ultimate");
    mapCanvas_ = new MapCanvas(this);
    setCentralWidget(mapCanvas_);
    summaryStrip_ = new SummaryStripWidget(this);
    buildMenus();
    buildToolbar();
    buildDocks();
    connectSignals();
    restoreWorkspaceState();
    scenarioBrowser_->setScenarioFiles(controller_.discoverScenarioFiles("assets/scenarios"));
    openScenario("assets/scenarios/convoy_guard.json");
    summaryStrip_->setSummary("Ready | No incident selected | Rule pack: balanced_ops");
    statusBar()->showMessage("Ready");
}

void MainWindow::buildMenus() {
    auto* fileMenu = menuBar()->addMenu("&File");
    auto* open = fileMenu->addAction("Open Scenario...");
    connect(open, &QAction::triggered, this, [this]() {
        const auto path = QFileDialog::getOpenFileName(this, "Open Scenario", "assets/scenarios", "JSON (*.json)");
        if (!path.isEmpty()) openScenario(path);
    });
    auto* exportAction = fileMenu->addAction("Export Debrief...");
    connect(exportAction, &QAction::triggered, this, [this]() {
        ExportDialog dlg(this);
        if (dlg.exec() == QDialog::Accepted) {
            if (controller_.exportDebrief(dlg.outputPath())) statusBar()->showMessage("Debrief exported", 3000);
        }
    });
    fileMenu->addSeparator();
    fileMenu->addAction("Exit", this, &QWidget::close);

    auto* sessionMenu = menuBar()->addMenu("&Session");
    auto* sessions = sessionMenu->addAction("Recent Sessions...");
    connect(sessions, &QAction::triggered, this, &MainWindow::openSessionManager);
    auto* layoutAction = sessionMenu->addAction("Workspace Layout...");
    connect(layoutAction, &QAction::triggered, this, [this]() { WorkspaceLayoutDialog dlg(this); dlg.exec(); });

    auto* toolsMenu = menuBar()->addMenu("&Tools");
    auto* settings = toolsMenu->addAction("Settings");
    connect(settings, &QAction::triggered, this, [this]() {
        SettingsDialog dlg(this);
        if (dlg.exec() == QDialog::Accepted) {
            controller_.workspace().followSelection = dlg.followSelection();
            controller_.workspace().showThreatRings = dlg.showThreatRings();
            controller_.setPlaybackRate(dlg.playbackRate());
            refreshUi();
        }
    });
    auto* rulesAction = toolsMenu->addAction("Alert Rule Packs");
    connect(rulesAction, &QAction::triggered, this, [this]() { AlertRulesDialog dlg(this); dlg.setRulePacks({"balanced_ops.json", "aggressive_monitoring.json"}); dlg.exec(); });
    auto* editor = toolsMenu->addAction("Scenario Editor");
    connect(editor, &QAction::triggered, this, [this]() {
        ScenarioEditorDialog dlg(this);
        dlg.setScenario(controller_.scenario());
        dlg.exec();
    });
}

void MainWindow::buildToolbar() {
    auto* tb = addToolBar("Primary");
    auto* start = tb->addAction("Start");
    auto* pause = tb->addAction("Pause");
    auto* step = tb->addAction("Step");
    connect(start, &QAction::triggered, this, [this]() { controller_.start(); });
    connect(pause, &QAction::triggered, this, [this]() { controller_.pause(); });
    connect(step, &QAction::triggered, this, [this]() { controller_.step(); refreshUi(); });
}

void MainWindow::buildDocks() {
    auto addDock = [this](const QString& title, QWidget* child, Qt::DockWidgetArea area) {
        auto* dock = new QDockWidget(title, this);
        dock->setObjectName(title);
        dock->setWidget(child);
        addDockWidget(area, dock);
        return dock;
    };

    scenarioBrowser_ = new ScenarioBrowserWidget(this);
    trackTable_ = new TrackTableWidget(this);
    planner_ = new PlannerWidget(this);
    inspector_ = new InspectorWidget(this);
    notes_ = new NotesWidget(this);
    validation_ = new ValidationPanelWidget(this);
    bookmarks_ = new BookmarkWidget(this);
    eventLog_ = new EventLogWidget(this);
    timeline_ = new TimelineWidget(this);
    alerts_ = new AlertsWidget(this);
    health_ = new HealthPanelWidget(this);
    layers_ = new LayerControlWidget(this);

    addDock("Scenario Browser", scenarioBrowser_, Qt::LeftDockWidgetArea);
    addDock("Track Monitor", trackTable_, Qt::LeftDockWidgetArea);
    addDock("Mission Planner", planner_, Qt::LeftDockWidgetArea);
    addDock("Inspector", inspector_, Qt::RightDockWidgetArea);
    addDock("Health", health_, Qt::RightDockWidgetArea);
    addDock("Validation", validation_, Qt::RightDockWidgetArea);
    addDock("Layers", layers_, Qt::RightDockWidgetArea);
    addDock("Alerts", alerts_, Qt::BottomDockWidgetArea);
    addDock("Notes", notes_, Qt::BottomDockWidgetArea);
    addDock("Bookmarks", bookmarks_, Qt::BottomDockWidgetArea);
    addDock("Event Log", eventLog_, Qt::BottomDockWidgetArea);
    addDock("Timeline", timeline_, Qt::BottomDockWidgetArea);
}

void MainWindow::connectSignals() {
    connect(scenarioBrowser_, &ScenarioBrowserWidget::scenarioRequested, this, [this](const QString& path) { openScenario(path); });
    connect(timeline_, &TimelineWidget::startRequested, this, [this]() { controller_.start(); });
    connect(timeline_, &TimelineWidget::pauseRequested, this, [this]() { controller_.pause(); });
    connect(timeline_, &TimelineWidget::stepRequested, this, [this]() { controller_.step(); refreshUi(); });
    connect(timeline_, &TimelineWidget::playbackRateChanged, this, [this](double rate) { controller_.setPlaybackRate(rate); });
    connect(layers_, &LayerControlWidget::labelsToggled, mapCanvas_, &MapCanvas::setShowLabels);
    connect(layers_, &LayerControlWidget::threatRingsToggled, mapCanvas_, &MapCanvas::setShowThreatRings);
}

void MainWindow::openScenario(const QString& path) {
    controller_.openScenario(path);
    if (!controller_.validationErrors().isEmpty()) {
        statusBar()->showMessage(QString("Scenario loaded with %1 validation warnings").arg(controller_.validationErrors().size()), 5000);
    } else {
        statusBar()->showMessage("Scenario loaded", 3000);
    }
    refreshUi();
}

void MainWindow::refreshUi() {
    QVector<Route> routes;
    if (!controller_.scenario().missions.isEmpty()) routes = controller_.scenario().missions.first().routes;
    mapCanvas_->setTracks(controller_.engine().tracks());
    mapCanvas_->setRoutes(routes);
    trackTable_->setTracks(controller_.engine().tracks());
    inspector_->setScenario(controller_.scenario());
    alerts_->setAlerts(controller_.alerts());
    health_->setTracks(controller_.engine().tracks());
    eventLog_->setEntries(controller_.journal().entries());

    QStringList routeRows;
    for (const auto& route : routes) {
        for (int i = 0; i < route.points.size(); ++i) {
            routeRows << QString("%1:%2|%3").arg(route.label).arg(i).arg(route.points[i].etaSeconds, 0, 'f', 0);
        }
    }
    planner_->setRouteSummary(routeRows);
    validation_->setMessages(controller_.validationErrors());
    bookmarks_->setBookmarks({{45, "warning", "Route review", "Possible overlap"}, {95, "note", "Pause and inspect", "Manual review marker"}});
    summaryStrip_->setSummary(QString("Scenario: %1 | Tracks: %2 | Alerts: %3").arg(controller_.scenario().name).arg(controller_.engine().tracks().size()).arg(controller_.alerts().size()));
}

void MainWindow::saveWorkspaceState() {
    controller_.workspace().windowGeometry = saveGeometry();
    controller_.workspace().windowState = saveState();
    controller_.saveWorkspace("assets/workspaces/default_workspace.json");
}

void MainWindow::restoreWorkspaceState() {
    controller_.loadWorkspace("assets/workspaces/default_workspace.json");
    if (!controller_.workspace().windowGeometry.isEmpty()) restoreGeometry(controller_.workspace().windowGeometry);
    if (!controller_.workspace().windowState.isEmpty()) restoreState(controller_.workspace().windowState);
}

void MainWindow::closeEvent(QCloseEvent* event) {
    saveWorkspaceState();
    QMainWindow::closeEvent(event);
}
}

void MainWindow::openSessionManager() {
    SessionManagerDialog dlg(this);
    dlg.setRecentSessions({"assets/scenarios/convoy_guard.json", "assets/scenarios/border_relay.json", "assets/scenarios/urban_response.json"});
    dlg.exec();
}
