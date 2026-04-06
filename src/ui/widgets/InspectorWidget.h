#pragma once
#include <QTextEdit>
#include "domain/Scenario.h"

namespace missionx {
class InspectorWidget : public QTextEdit {
    Q_OBJECT
public:
    explicit InspectorWidget(QWidget* parent = nullptr);
    void setScenario(const Scenario& scenario);
};
}
