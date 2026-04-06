#include "ui/widgets/EventLogWidget.h"
namespace missionx {
EventLogWidget::EventLogWidget(QWidget* parent) : QPlainTextEdit(parent) { setReadOnly(true); }
void EventLogWidget::setEntries(const QVector<JournalEntry>& entries) {
    clear();
    for (const auto& entry : entries) {
        appendPlainText(QString("%1 [%2] %3").arg(entry.timestamp.toString(Qt::ISODate), entry.category, entry.message));
    }
}
}
