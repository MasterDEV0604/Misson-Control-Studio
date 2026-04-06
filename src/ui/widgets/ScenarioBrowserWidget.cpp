#include "ui/widgets/ScenarioBrowserWidget.h"
namespace missionx {
ScenarioBrowserWidget::ScenarioBrowserWidget(QWidget* parent) : QListWidget(parent) {
    connect(this, &QListWidget::itemDoubleClicked, this, [this](QListWidgetItem* item) {
        emit scenarioRequested(item->data(Qt::UserRole).toString());
    });
}
void ScenarioBrowserWidget::setScenarioFiles(const QStringList& files) {
    clear();
    for (const auto& file : files) {
        auto* item = new QListWidgetItem(file, this);
        item->setData(Qt::UserRole, QString("assets/scenarios/%1").arg(file));
    }
}
}
