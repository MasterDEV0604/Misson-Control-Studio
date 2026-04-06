#pragma once
#include <QString>
#include <QPointF>
#include <QVector>

namespace missionx {
struct RoutePoint {
    QPointF position;
    double etaSeconds = 0.0;
};

struct Route {
    QString entityId;
    QString label;
    QVector<RoutePoint> points;
};
}
