#include "services/RulePackRepository.h"
#include <QDir>
#include <QFile>
#include <QJsonDocument>

namespace missionx {
QStringList RulePackRepository::discoverRulePacks(const QString& directoryPath) const {
    QDir dir(directoryPath);
    return dir.entryList({"*.json"}, QDir::Files, QDir::Name);
}
QVariantMap RulePackRepository::load(const QString& path) const {
    QFile f(path);
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return {};
    return QJsonDocument::fromJson(f.readAll()).object().toVariantMap();
}
}
