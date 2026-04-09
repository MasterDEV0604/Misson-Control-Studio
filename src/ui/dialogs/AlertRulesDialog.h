#pragma once
#include <QDialog>
class QComboBox;

namespace missionx {
class AlertRulesDialog : public QDialog {
    Q_OBJECT
public:
    explicit AlertRulesDialog(QWidget* parent = nullptr);
    void setRulePacks(const QStringList& names);
private:
    QComboBox* combo_ = nullptr;
};
}
