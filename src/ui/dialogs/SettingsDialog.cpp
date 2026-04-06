#include "ui/dialogs/SettingsDialog.h"
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QVBoxLayout>
namespace missionx {
SettingsDialog::SettingsDialog(QWidget* parent) : QDialog(parent) {
    setWindowTitle("Settings");
    auto* layout = new QVBoxLayout(this);
    auto* form = new QFormLayout();
    followSelection_ = new QCheckBox(this);
    threatRings_ = new QCheckBox(this);
    playbackRate_ = new QDoubleSpinBox(this);
    followSelection_->setChecked(true);
    threatRings_->setChecked(true);
    playbackRate_->setRange(0.25, 8.0);
    playbackRate_->setValue(1.0);
    form->addRow("Follow selection", followSelection_);
    form->addRow("Show threat rings", threatRings_);
    form->addRow("Default playback rate", playbackRate_);
    layout->addLayout(form);
    auto* buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    layout->addWidget(buttons);
}
bool SettingsDialog::followSelection() const { return followSelection_->isChecked(); }
bool SettingsDialog::showThreatRings() const { return threatRings_->isChecked(); }
double SettingsDialog::playbackRate() const { return playbackRate_->value(); }
}
