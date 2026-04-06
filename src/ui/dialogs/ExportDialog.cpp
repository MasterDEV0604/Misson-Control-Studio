#include "ui/dialogs/ExportDialog.h"
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QLineEdit>
#include <QVBoxLayout>
namespace missionx {
ExportDialog::ExportDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Export Debrief");
    auto* layout = new QVBoxLayout(this);
    auto* form = new QFormLayout();
    path_ = new QLineEdit("artifacts/example_reports/debrief.md", this);
    form->addRow("Output path", path_);
    layout->addLayout(form);
    auto* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    layout->addWidget(buttons);
}
QString ExportDialog::outputPath() const { return path_->text(); }
}
