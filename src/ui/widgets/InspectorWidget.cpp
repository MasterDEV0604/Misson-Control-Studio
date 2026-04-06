#include "ui/widgets/InspectorWidget.h"
namespace missionx {
InspectorWidget::InspectorWidget(QWidget* parent) : QTextEdit(parent) { setReadOnly(true); }
void InspectorWidget::setScenario(const Scenario& scenario) {
    clear();
    append(QString("Scenario: %1").arg(scenario.name));
    append(QString("Summary: %1").arg(scenario.summary));
    append(QString("Missions: %1").arg(scenario.missions.size()));
    append(QString("Tracks: %1").arg(scenario.initialTracks.size()));
    for (const auto& mission : scenario.missions) {
        append(QString("- %1: %2").arg(mission.title, mission.objective));
    }
}
}
