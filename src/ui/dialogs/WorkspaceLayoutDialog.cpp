#include "ui/dialogs/WorkspaceLayoutDialog.h"
#include <QDialogButtonBox>
#include <QLabel>
#include <QVBoxLayout>
namespace missionx {
WorkspaceLayoutDialog::WorkspaceLayoutDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Workspace Layout");
    auto* layout = new QVBoxLayout(this);
    layout->addWidget(new QLabel("Save/restore dock presets and layout profiles.", this));
    layout->addWidget(new QDialogButtonBox(QDialogButtonBox::Ok, this));
}
}
