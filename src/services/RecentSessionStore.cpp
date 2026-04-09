#include "services/RecentSessionStore.h"
#include <QFile>
#include <QTextStream>

namespace missionx {
QStringList RecentSessionStore::loadRecent() const {
    QFile f("assets/workspaces/recent_sessions.txt");
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) return {};
    QStringList result;
    QTextStream in(&f);
    while (!in.atEnd()) result << in.readLine();
    return result;
}
void RecentSessionStore::saveRecent(const QStringList& paths) const {
    QFile f("assets/workspaces/recent_sessions.txt");
    if (!f.open(QIODevice::WriteOnly | QIODevice::Text)) return;
    QTextStream out(&f);
    for (const auto& p : paths) out << p << "
";
}
}
