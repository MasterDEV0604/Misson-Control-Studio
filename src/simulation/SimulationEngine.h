#pragma once
#include <QVector>
#include "domain/TrackState.h"
#include "domain/Scenario.h"
#include "services/EventJournal.h"
#include "simulation/TimelineScheduler.h"

namespace missionx {
class SimulationEngine {
public:
    explicit SimulationEngine(EventJournal& journal);

    void loadScenario(const Scenario& scenario);
    void start();
    void pause();
    void step();
    bool isRunning() const { return running_; }
    const QVector<TrackState>& tracks() const { return tracks_; }
    TimelineScheduler& scheduler() { return scheduler_; }

private:
    EventJournal& journal_;
    const Scenario* scenario_ = nullptr;
    QVector<TrackState> tracks_;
    TimelineScheduler scheduler_;
    bool running_ = false;
    int tick_ = 0;
};
}
