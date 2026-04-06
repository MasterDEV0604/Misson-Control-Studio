#pragma once
#include <QDialog>
class QLineEdit;

namespace missionx {
class ExportDialog : public QDialog {
    Q_OBJECT
public:
    explicit ExportDialog(QWidget* parent = nullptr);
    QString outputPath() const;
private:
    QLineEdit* path_ = nullptr;
};
}
