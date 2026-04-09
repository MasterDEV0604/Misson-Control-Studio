#pragma once
#include <QDialog>
class QListWidget;

namespace missionx {
class SessionManagerDialog : public QDialog {
    Q_OBJECT
public:
    explicit SessionManagerDialog(QWidget* parent = nullptr);
    void setRecentSessions(const QStringList& sessions);
private:
    QListWidget* list_ = nullptr;
};
}
