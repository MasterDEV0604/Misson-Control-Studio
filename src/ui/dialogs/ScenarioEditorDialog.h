#pragma once
#include <QDialog>
#include "domain/Scenario.h"
class QLineEdit;
class QTextEdit;

namespace missionx {
class ScenarioEditorDialog : public QDialog {
    Q_OBJECT
public:
    explicit ScenarioEditorDialog(QWidget* parent = nullptr);
    void setScenario(const Scenario& scenario);
private:
    QLineEdit* name_ = nullptr;
    QTextEdit* summary_ = nullptr;
};
}
