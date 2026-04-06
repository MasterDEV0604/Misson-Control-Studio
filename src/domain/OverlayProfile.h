#pragma once
#include <QString>

namespace missionx {
struct OverlayProfile {
    QString name;
    bool showLabels = true;
    bool showThreatRings = true;
    bool showRoutes = true;
    bool showBreadcrumbs = true;
};
}
