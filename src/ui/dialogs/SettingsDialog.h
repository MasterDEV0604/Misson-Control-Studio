#pragma once
#include <QDialog>
class QCheckBox;
class QDoubleSpinBox;

namespace missionx {
class SettingsDialog : public QDialog {
    Q_OBJECT
public:
    explicit SettingsDialog(QWidget* parent = nullptr);
    bool followSelection() const;
    bool showThreatRings() const;
    double playbackRate() const;
private:
    QCheckBox* followSelection_ = nullptr;
    QCheckBox* threatRings_ = nullptr;
    QDoubleSpinBox* playbackRate_ = nullptr;
};
}
