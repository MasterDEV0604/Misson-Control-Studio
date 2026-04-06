#include "services/EventJournal.h"

namespace missionx {
void EventJournal::append(const QString& category, const QString& message) {
    entries_.push_back({QDateTime::currentDateTime(), category, message});
}
const QVector<JournalEntry>& EventJournal::entries() const { return entries_; }
void EventJournal::clear() { entries_.clear(); }
}
