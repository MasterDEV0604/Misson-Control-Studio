#include "ui/widgets/NotesWidget.h"
namespace missionx {
NotesWidget::NotesWidget(QWidget* parent) : QTextEdit(parent) {
    setPlaceholderText("Operator notes and debrief comments...");
}
}
