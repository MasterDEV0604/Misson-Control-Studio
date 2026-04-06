#include "simulation/ThreatModel.h"
namespace missionx {
QString ThreatModel::classifyDistance(double distanceMeters) const {
    if (distanceMeters < 80.0) return "critical";
    if (distanceMeters < 180.0) return "warning";
    return "low";
}
}
