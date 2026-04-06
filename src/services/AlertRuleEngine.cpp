#include "services/AlertRuleEngine.h"

namespace missionx {
QVector<Alert> AlertRuleEngine::evaluate(const Scenario& scenario) const {
    QVector<Alert> alerts;
    for (const auto& track : scenario.initialTracks) {
        if (track.health == "red") {
            alerts.push_back({"critical", track.displayName, "Platform health is red. Immediate operator review required."});
        } else if (track.confidence < 0.75) {
            alerts.push_back({"warning", track.displayName, "Track confidence is below nominal threshold."});
        } else if (track.status == "delayed" || track.status == "watch") {
            alerts.push_back({"info", track.displayName, "Track status requires continued monitoring."});
        }
    }
    return alerts;
}
}
