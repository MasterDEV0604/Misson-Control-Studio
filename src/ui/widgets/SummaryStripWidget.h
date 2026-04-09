#pragma once
#include <QWidget>
class QLabel;

namespace missionx {
class SummaryStripWidget : public QWidget {
    Q_OBJECT
public:
    explicit SummaryStripWidget(QWidget* parent = nullptr);
    void setSummary(const QString& text);
private:
    QLabel* label_ = nullptr;
};
}
