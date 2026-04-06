#pragma once
#include <QPlainTextEdit>
#include <QVector>
#include "services/EventJournal.h"

namespace missionx {
class EventLogWidget : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit EventLogWidget(QWidget* parent = nullptr);
    void setEntries(const QVector<JournalEntry>& entries);
};
}
