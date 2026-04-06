#include "services/ScenarioRepository.h"
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace missionx {
namespace {
Route parseRoute(const QJsonObject& obj) {
    Route route;
    route.entityId = obj.value("entityId").toString();
    route.label = obj.value("label").toString();
    for (const auto& pointValue : obj.value("points").toArray()) {
        const auto pointObj = pointValue.toObject();
        RoutePoint point;
        point.position = QPointF(pointObj.value("x").toDouble(), pointObj.value("y").toDouble());
        point.etaSeconds = pointObj.value("etaSeconds").toDouble();
        route.points.push_back(point);
    }
    return route;
}

Mission parseMission(const QJsonObject& obj) {
    Mission mission;
    mission.id = obj.value("id").toString();
    mission.title = obj.value("title").toString();
    mission.objective = obj.value("objective").toString();
    mission.areaName = obj.value("areaName").toString();
    for (const auto& routeValue : obj.value("routes").toArray()) {
        mission.routes.push_back(parseRoute(routeValue.toObject()));
    }
    return mission;
}

TrackState parseTrack(const QJsonObject& obj) {
    TrackState track;
    track.id = obj.value("id").toString();
    track.displayName = obj.value("displayName").toString();
    track.type = obj.value("type").toString();
    track.position = QPointF(obj.value("x").toDouble(), obj.value("y").toDouble());
    track.velocity = QPointF(obj.value("vx").toDouble(), obj.value("vy").toDouble());
    track.headingDeg = obj.value("headingDeg").toDouble();
    track.confidence = obj.value("confidence").toDouble(1.0);
    track.status = obj.value("status").toString("nominal");
    track.health = obj.value("health").toString("green");
    return track;
}
}

Scenario ScenarioRepository::load(const QString& path) const {
    QFile file(path);
    Scenario scenario;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        scenario.name = "Failed to load scenario";
        scenario.summary = path;
        return scenario;
    }

    const auto doc = QJsonDocument::fromJson(file.readAll());
    const auto obj = doc.object();
    scenario.id = obj.value("id").toString();
    scenario.name = obj.value("name").toString();
    scenario.summary = obj.value("summary").toString();
    for (const auto& missionValue : obj.value("missions").toArray()) {
        scenario.missions.push_back(parseMission(missionValue.toObject()));
    }
    for (const auto& trackValue : obj.value("tracks").toArray()) {
        scenario.initialTracks.push_back(parseTrack(trackValue.toObject()));
    }
    return scenario;
}

QStringList ScenarioRepository::discoverScenarioFiles(const QString& directoryPath) const {
    QDir dir(directoryPath);
    return dir.entryList({"*.json"}, QDir::Files, QDir::Name);
}
}
