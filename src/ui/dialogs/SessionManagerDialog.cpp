#include "ui/dialogs/SessionManagerDialog.h"
#include <QDialogButtonBox>
#include <QListWidget>
#include <QVBoxLayout>
namespace missionx {
SessionManagerDialog::SessionManagerDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Session Manager");
    auto* layout = new QVBoxLayout(this);
    list_ = new QListWidget(this);
    layout->addWidget(list_);
    layout->addWidget(new QDialogButtonBox(QDialogButtonBox::Ok, this));
}
void SessionManagerDialog::setRecentSessions(const QStringList& sessions) { list_->clear(); list_->addItems(sessions); }
}
