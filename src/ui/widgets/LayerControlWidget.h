#pragma once
#include <QWidget>
class QCheckBox;

namespace missionx {
class LayerControlWidget : public QWidget {
    Q_OBJECT
public:
    explicit LayerControlWidget(QWidget* parent = nullptr);
signals:
    void labelsToggled(bool enabled);
    void threatRingsToggled(bool enabled);
};
}
