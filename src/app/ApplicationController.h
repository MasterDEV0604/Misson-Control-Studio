#pragma once
#include <QString>
#include <QStringList>
#include <QVector>
#include "app/WorkspaceState.h"
#include "domain/Alert.h"
#include "domain/Scenario.h"
#include "services/AlertRuleEngine.h"
#include "services/EventJournal.h"
#include "services/ReportExporter.h"
#include "services/ScenarioRepository.h"
#include "services/ScenarioValidator.h"
#include "services/WorkspaceRepository.h"
#include "simulation/SimulationEngine.h"

namespace missionx {
class ApplicationController {
public:
    ApplicationController();

    QStringList discoverScenarioFiles(const QString& directory) const;
    bool openScenario(const QString& path);
    bool saveWorkspace(const QString& path);
    bool loadWorkspace(const QString& path);
    bool exportDebrief(const QString& outputPath);

    void start();
    void pause();
    void step();
    void setPlaybackRate(double rate);

    Scenario& scenario();
    const Scenario& scenario() const;
    const WorkspaceState& workspace() const;
    WorkspaceState& workspace();
    SimulationEngine& engine();
    const QVector<Alert>& alerts() const;
    EventJournal& journal();
    QStringList validationErrors() const;

private:
    void refreshAlerts();

    WorkspaceState workspace_;
    ScenarioRepository scenarioRepository_;
    WorkspaceRepository workspaceRepository_;
    ScenarioValidator validator_;
    AlertRuleEngine alertRuleEngine_;
    ReportExporter exporter_;
    Scenario scenario_;
    EventJournal journal_;
    SimulationEngine engine_;
    QVector<Alert> alerts_;
    QStringList validationErrors_;
};
}
