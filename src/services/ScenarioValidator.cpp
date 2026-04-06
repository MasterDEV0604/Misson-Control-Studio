#include "services/ScenarioValidator.h"

namespace missionx {
QStringList ScenarioValidator::validate(const Scenario& scenario) const {
    QStringList errors;
    if (scenario.name.trimmed().isEmpty()) errors << "Scenario name must not be empty.";
    if (scenario.missions.isEmpty()) errors << "At least one mission must be defined.";
    if (scenario.initialTracks.isEmpty()) errors << "At least one track must be defined.";
    for (const auto& mission : scenario.missions) {
        if (mission.title.trimmed().isEmpty()) errors << "Mission title must not be empty.";
        for (const auto& route : mission.routes) {
            if (route.points.size() < 2) errors << QString("Route '%1' must contain at least two points.").arg(route.label);
        }
    }
    return errors;
}
}
