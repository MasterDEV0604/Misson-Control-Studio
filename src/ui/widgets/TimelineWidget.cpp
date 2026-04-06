#include "ui/widgets/TimelineWidget.h"
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSlider>

namespace missionx {
TimelineWidget::TimelineWidget(QWidget* parent) : QWidget(parent) {
    auto* layout = new QHBoxLayout(this);
    auto* start = new QPushButton("Start", this);
    auto* pause = new QPushButton("Pause", this);
    auto* step = new QPushButton("Step", this);
    auto* slider = new QSlider(Qt::Horizontal, this);
    auto* rate = new QDoubleSpinBox(this);
    rate->setRange(0.25, 8.0);
    rate->setSingleStep(0.25);
    rate->setValue(1.0);
    slider->setRange(0, 100);
    label_ = new QLabel("Timeline", this);
    layout->addWidget(start);
    layout->addWidget(pause);
    layout->addWidget(step);
    layout->addWidget(slider, 1);
    layout->addWidget(new QLabel("Rate", this));
    layout->addWidget(rate);
    layout->addWidget(label_);
    connect(start, &QPushButton::clicked, this, &TimelineWidget::startRequested);
    connect(pause, &QPushButton::clicked, this, &TimelineWidget::pauseRequested);
    connect(step, &QPushButton::clicked, this, &TimelineWidget::stepRequested);
    connect(rate, qOverload<double>(&QDoubleSpinBox::valueChanged), this, &TimelineWidget::playbackRateChanged);
}
}
