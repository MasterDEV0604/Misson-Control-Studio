#include "ui/widgets/PlannerWidget.h"
#include <QHeaderView>
#include <QTableWidget>
#include <QVBoxLayout>
namespace missionx {
PlannerWidget::PlannerWidget(QWidget* parent) : QWidget(parent) {
    auto* layout = new QVBoxLayout(this);
    table_ = new QTableWidget(this);
    table_->setColumnCount(2);
    table_->setHorizontalHeaderLabels({"Waypoint", "ETA (s)"});
    table_->horizontalHeader()->setStretchLastSection(true);
    layout->addWidget(table_);
}
void PlannerWidget::setRouteSummary(const QStringList& lines) {
    table_->setRowCount(lines.size());
    for (int i = 0; i < lines.size(); ++i) {
        const auto parts = lines[i].split('|');
        table_->setItem(i, 0, new QTableWidgetItem(parts.value(0)));
        table_->setItem(i, 1, new QTableWidgetItem(parts.value(1)));
    }
}
}
