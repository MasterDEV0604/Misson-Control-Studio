#pragma once
#include <QString>
#include <QStringList>
#include <QByteArray>

namespace missionx {
struct WorkspaceState {
    QString lastScenarioPath;
    QString activeOverlayProfile = "dark-ops";
    QStringList hiddenPanels;
    double playbackRate = 1.0;
    bool followSelection = true;
    bool showThreatRings = true;
    QByteArray windowGeometry;
    QByteArray windowState;
};
}
