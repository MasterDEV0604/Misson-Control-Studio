#include "ui/dialogs/ScenarioEditorDialog.h"
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
namespace missionx {
ScenarioEditorDialog::ScenarioEditorDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Scenario Editor");
    auto* layout = new QVBoxLayout(this);
    auto* form = new QFormLayout();
    name_ = new QLineEdit(this);
    summary_ = new QTextEdit(this);
    form->addRow("Scenario name", name_);
    form->addRow("Summary", summary_);
    layout->addLayout(form);
    auto* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    layout->addWidget(buttons);
}
void ScenarioEditorDialog::setScenario(const Scenario& scenario) {
    name_->setText(scenario.name);
    summary_->setPlainText(scenario.summary);
}
}
