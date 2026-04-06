#pragma once
#include <QStringList>
#include "domain/Scenario.h"

namespace missionx {
class ScenarioValidator {
public:
    QStringList validate(const Scenario& scenario) const;
};
}
