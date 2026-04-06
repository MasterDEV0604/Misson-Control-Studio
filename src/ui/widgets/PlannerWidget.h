#pragma once
#include <QWidget>
class QTableWidget;

namespace missionx {
class PlannerWidget : public QWidget {
    Q_OBJECT
public:
    explicit PlannerWidget(QWidget* parent = nullptr);
    void setRouteSummary(const QStringList& lines);
private:
    QTableWidget* table_ = nullptr;
};
}
