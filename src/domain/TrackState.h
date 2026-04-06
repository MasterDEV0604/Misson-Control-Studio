#pragma once
#include <QString>
#include <QPointF>

namespace missionx {
struct TrackState {
    QString id;
    QString displayName;
    QString type;
    QPointF position;
    QPointF velocity;
    double headingDeg = 0.0;
    double confidence = 1.0;
    QString status = "nominal";
    QString health = "green";
};
}
