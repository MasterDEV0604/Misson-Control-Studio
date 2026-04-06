#pragma once
#include <QString>
#include <QStringList>
#include "domain/Scenario.h"

namespace missionx {
class ScenarioRepository {
public:
    Scenario load(const QString& path) const;
    QStringList discoverScenarioFiles(const QString& directoryPath) const;
};
}
