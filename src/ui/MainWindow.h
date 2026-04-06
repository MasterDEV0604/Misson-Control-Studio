#pragma once
#include <QMainWindow>
#include "app/ApplicationController.h"

namespace missionx {
class AlertsWidget;
class EventLogWidget;
class HealthPanelWidget;
class InspectorWidget;
class LayerControlWidget;
class MapCanvas;
class PlannerWidget;
class ScenarioBrowserWidget;
class TimelineWidget;
class TrackTableWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget* parent = nullptr);
protected:
    void closeEvent(QCloseEvent* event) override;
private:
    void buildMenus();
    void buildToolbar();
    void buildDocks();
    void connectSignals();
    void openScenario(const QString& path);
    void refreshUi();
    void saveWorkspaceState();
    void restoreWorkspaceState();

    ApplicationController controller_;
    MapCanvas* mapCanvas_ = nullptr;
    ScenarioBrowserWidget* scenarioBrowser_ = nullptr;
    TrackTableWidget* trackTable_ = nullptr;
    PlannerWidget* planner_ = nullptr;
    InspectorWidget* inspector_ = nullptr;
    EventLogWidget* eventLog_ = nullptr;
    TimelineWidget* timeline_ = nullptr;
    AlertsWidget* alerts_ = nullptr;
    HealthPanelWidget* health_ = nullptr;
    LayerControlWidget* layers_ = nullptr;
};
}
