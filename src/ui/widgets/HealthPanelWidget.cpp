#include "ui/widgets/HealthPanelWidget.h"
namespace missionx {
HealthPanelWidget::HealthPanelWidget(QWidget* parent) : QTextEdit(parent) { setReadOnly(true); }
void HealthPanelWidget::setTracks(const QVector<TrackState>& tracks) {
    clear();
    int green = 0, amber = 0, red = 0;
    for (const auto& t : tracks) {
        if (t.health == "red") ++red;
        else if (t.health == "amber") ++amber;
        else ++green;
    }
    append(QString("Green: %1").arg(green));
    append(QString("Amber: %1").arg(amber));
    append(QString("Red: %1").arg(red));
}
}
