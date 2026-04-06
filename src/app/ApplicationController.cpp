#include "app/ApplicationController.h"

namespace missionx {
ApplicationController::ApplicationController() : engine_(journal_) {}

QStringList ApplicationController::discoverScenarioFiles(const QString& directory) const {
    return scenarioRepository_.discoverScenarioFiles(directory);
}

bool ApplicationController::openScenario(const QString& path) {
    scenario_ = scenarioRepository_.load(path);
    validationErrors_ = validator_.validate(scenario_);
    workspace_.lastScenarioPath = path;
    engine_.loadScenario(scenario_);
    journal_.append("scenario", QString("Opened scenario from %1").arg(path));
    for (const auto& error : validationErrors_) {
        journal_.append("validation", error);
    }
    refreshAlerts();
    return true;
}

bool ApplicationController::saveWorkspace(const QString& path) {
    return workspaceRepository_.save(path, workspace_);
}

bool ApplicationController::loadWorkspace(const QString& path) {
    const bool ok = workspaceRepository_.load(path, workspace_);
    if (ok) journal_.append("workspace", QString("Loaded workspace %1").arg(path));
    return ok;
}

bool ApplicationController::exportDebrief(const QString& outputPath) {
    return exporter_.exportDebrief(scenario_, alerts_, journal_.entries(), outputPath);
}

void ApplicationController::start() { engine_.start(); }
void ApplicationController::pause() { engine_.pause(); }
void ApplicationController::step() { engine_.step(); refreshAlerts(); }
void ApplicationController::setPlaybackRate(double rate) { workspace_.playbackRate = rate; engine_.scheduler().setRate(rate); }
Scenario& ApplicationController::scenario() { return scenario_; }
const Scenario& ApplicationController::scenario() const { return scenario_; }
const WorkspaceState& ApplicationController::workspace() const { return workspace_; }
WorkspaceState& ApplicationController::workspace() { return workspace_; }
SimulationEngine& ApplicationController::engine() { return engine_; }
const QVector<Alert>& ApplicationController::alerts() const { return alerts_; }
EventJournal& ApplicationController::journal() { return journal_; }
QStringList ApplicationController::validationErrors() const { return validationErrors_; }

void ApplicationController::refreshAlerts() {
    alerts_ = alertRuleEngine_.evaluate(scenario_);
}
}
