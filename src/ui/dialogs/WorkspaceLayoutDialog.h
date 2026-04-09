#pragma once
#include <QDialog>

namespace missionx {
class WorkspaceLayoutDialog : public QDialog {
    Q_OBJECT
public:
    explicit WorkspaceLayoutDialog(QWidget* parent = nullptr);
};
}
