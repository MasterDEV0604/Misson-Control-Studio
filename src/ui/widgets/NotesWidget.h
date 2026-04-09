#pragma once
#include <QTextEdit>

namespace missionx {
class NotesWidget : public QTextEdit {
    Q_OBJECT
public:
    explicit NotesWidget(QWidget* parent = nullptr);
};
}
