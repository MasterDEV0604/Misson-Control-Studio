#pragma once
#include <QDateTime>
#include <QString>
#include <QVector>

namespace missionx {
struct JournalEntry {
    QDateTime timestamp;
    QString category;
    QString message;
};

class EventJournal {
public:
    void append(const QString& category, const QString& message);
    const QVector<JournalEntry>& entries() const;
    void clear();
private:
    QVector<JournalEntry> entries_;
};
}
