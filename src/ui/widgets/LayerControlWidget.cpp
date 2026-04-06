#include "ui/widgets/LayerControlWidget.h"
#include <QCheckBox>
#include <QVBoxLayout>
namespace missionx {
LayerControlWidget::LayerControlWidget(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);
    auto* labels = new QCheckBox("Show Labels", this);
    auto* threatRings = new QCheckBox("Show Threat Rings", this);
    labels->setChecked(true);
    threatRings->setChecked(true);
    layout->addWidget(labels);
    layout->addWidget(threatRings);
    layout->addStretch(1);
    connect(labels, &QCheckBox::toggled, this, &LayerControlWidget::labelsToggled);
    connect(threatRings, &QCheckBox::toggled, this, &LayerControlWidget::threatRingsToggled);
}
}
