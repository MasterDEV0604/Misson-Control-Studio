#include "ui/widgets/SummaryStripWidget.h"
#include <QHBoxLayout>
#include <QLabel>
namespace missionx {
SummaryStripWidget::SummaryStripWidget(QWidget* parent) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    label_ = new QLabel("Mission summary strip", this);
    layout->addWidget(label_);
}
void SummaryStripWidget::setSummary(const QString& text) { label_->setText(text); }
}
