#pragma once
#include <QString>
#include <QVariantMap>

namespace missionx {
class MissionSessionRepository {
public:
    QVariantMap loadTemplate(const QString& path) const;
};
}
