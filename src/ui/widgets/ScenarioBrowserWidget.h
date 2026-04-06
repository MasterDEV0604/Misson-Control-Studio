#pragma once
#include <QListWidget>

namespace missionx {
class ScenarioBrowserWidget : public QListWidget {
    Q_OBJECT
public:
    explicit ScenarioBrowserWidget(QWidget* parent = nullptr);
    void setScenarioFiles(const QStringList& files);
signals:
    void scenarioRequested(const QString& path);
};
}
