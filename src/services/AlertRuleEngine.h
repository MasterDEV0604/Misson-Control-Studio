#pragma once
#include <QVector>
#include "domain/Alert.h"
#include "domain/Scenario.h"

namespace missionx {
class AlertRuleEngine {
public:
    QVector<Alert> evaluate(const Scenario& scenario) const;
};
}
