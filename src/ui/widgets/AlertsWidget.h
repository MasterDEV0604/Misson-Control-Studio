#pragma once
#include <QListWidget>
#include <QVector>
#include "domain/Alert.h"

namespace missionx {
class AlertsWidget : public QListWidget {
    Q_OBJECT
public:
    explicit AlertsWidget(QWidget* parent = nullptr);
    void setAlerts(const QVector<Alert>& alerts);
};
}
