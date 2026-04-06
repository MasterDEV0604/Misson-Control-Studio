#include "simulation/SimulationEngine.h"

namespace missionx {
SimulationEngine::SimulationEngine(EventJournal& journal) : journal_(journal) {}

void SimulationEngine::loadScenario(const Scenario& scenario) {
    scenario_ = &scenario;
    tracks_ = scenario.initialTracks;
    tick_ = 0;
    running_ = false;
    journal_.append("scenario", QString("Loaded scenario '%1'").arg(scenario.name));
}

void SimulationEngine::start() {
    running_ = true;
    journal_.append("timeline", "Playback started");
}

void SimulationEngine::pause() {
    running_ = false;
    journal_.append("timeline", "Playback paused");
}

void SimulationEngine::step() {
    if (!scenario_) return;
    ++tick_;
    for (auto& track : tracks_) {
        track.position += track.velocity * scheduler_.rate();
        track.confidence = qMax(0.55, track.confidence - 0.001);
    }
    journal_.append("tick", QString("Advanced simulation to tick %1").arg(tick_));
}
}
