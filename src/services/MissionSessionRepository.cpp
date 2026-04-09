#include "services/MissionSessionRepository.h"
#include <QFile>
#include <QJsonDocument>

namespace missionx {
QVariantMap MissionSessionRepository::loadTemplate(const QString& path) const {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return {};
    return QJsonDocument::fromJson(f.readAll()).object().toVariantMap();
}
}
