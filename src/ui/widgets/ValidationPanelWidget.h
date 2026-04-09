#pragma once
#include <QListWidget>

namespace missionx {
class ValidationPanelWidget : public QListWidget {
    Q_OBJECT
public:
    explicit ValidationPanelWidget(QWidget* parent = nullptr);
    void setMessages(const QStringList& messages);
};
}
