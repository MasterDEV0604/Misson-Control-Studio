#pragma once
#include <QStringList>

namespace missionx {
class RecentSessionStore {
public:
    QStringList loadRecent() const;
    void saveRecent(const QStringList& paths) const;
};
}
