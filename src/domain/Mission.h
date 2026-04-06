#pragma once
#include <QString>
#include <QVector>
#include "domain/Route.h"

namespace missionx {
struct Mission {
    QString id;
    QString title;
    QString objective;
    QString areaName;
    QVector<Route> routes;
};
}
