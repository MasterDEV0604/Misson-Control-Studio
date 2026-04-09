#include "ui/dialogs/AlertRulesDialog.h"
#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
namespace missionx {
AlertRulesDialog::AlertRulesDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Alert Rule Packs");
    auto* layout = new QFormLayout(this);
    combo_ = new QComboBox(this);
    layout->addRow("Rule pack", combo_);
    layout->addWidget(new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this));
}
void AlertRulesDialog::setRulePacks(const QStringList& names) { combo_->clear(); combo_->addItems(names); }
}
