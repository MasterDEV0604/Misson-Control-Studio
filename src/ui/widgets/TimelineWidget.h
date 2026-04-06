#pragma once
#include <QWidget>
class QLabel;
class QPushButton;
class QSlider;
class QDoubleSpinBox;

namespace missionx {
class TimelineWidget : public QWidget {
    Q_OBJECT
public:
    explicit TimelineWidget(QWidget* parent = nullptr);
signals:
    void startRequested();
    void pauseRequested();
    void stepRequested();
    void playbackRateChanged(double rate);
private:
    QLabel* label_ = nullptr;
};
}
