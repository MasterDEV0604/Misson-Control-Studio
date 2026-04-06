#include "services/WorkspaceRepository.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

namespace missionx {
bool WorkspaceRepository::save(const QString& path, const WorkspaceState& state) const {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
    QJsonObject obj;
    obj["lastScenarioPath"] = state.lastScenarioPath;
    obj["activeOverlayProfile"] = state.activeOverlayProfile;
    obj["playbackRate"] = state.playbackRate;
    obj["followSelection"] = state.followSelection;
    obj["showThreatRings"] = state.showThreatRings;
    obj["windowGeometry"] = QString::fromLatin1(state.windowGeometry.toBase64());
    obj["windowState"] = QString::fromLatin1(state.windowState.toBase64());
    file.write(QJsonDocument(obj).toJson(QJsonDocument::Indented));
    return true;
}

bool WorkspaceRepository::load(const QString& path, WorkspaceState& state) const {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    const auto doc = QJsonDocument::fromJson(file.readAll());
    const auto obj = doc.object();
    state.lastScenarioPath = obj.value("lastScenarioPath").toString();
    state.activeOverlayProfile = obj.value("activeOverlayProfile").toString("dark-ops");
    state.playbackRate = obj.value("playbackRate").toDouble(1.0);
    state.followSelection = obj.value("followSelection").toBool(true);
    state.showThreatRings = obj.value("showThreatRings").toBool(true);
    state.windowGeometry = QByteArray::fromBase64(obj.value("windowGeometry").toString().toLatin1());
    state.windowState = QByteArray::fromBase64(obj.value("windowState").toString().toLatin1());
    return true;
}
}
