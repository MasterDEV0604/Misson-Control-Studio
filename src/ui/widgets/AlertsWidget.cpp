#include "ui/widgets/AlertsWidget.h"
namespace missionx {
AlertsWidget::AlertsWidget(QWidget* parent) : QListWidget(parent) {}
void AlertsWidget::setAlerts(const QVector<Alert>& alerts) {
    clear();
    for (const auto& alert : alerts) {
        addItem(QString("[%1] %2 — %3").arg(alert.severity, alert.source, alert.message));
    }
}
}
