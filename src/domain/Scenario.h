#pragma once
#include <QString>
#include <QVector>
#include "domain/Mission.h"
#include "domain/TrackState.h"

namespace missionx {
struct Scenario {
    QString id;
    QString name;
    QString summary;
    QVector<Mission> missions;
    QVector<TrackState> initialTracks;
};
}
