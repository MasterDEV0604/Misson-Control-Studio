#pragma once
#include <QString>
#include <QStringList>
#include <QVariantMap>

namespace missionx {
class RulePackRepository {
public:
    QStringList discoverRulePacks(const QString& directoryPath) const;
    QVariantMap load(const QString& path) const;
};
}
