#include "ui/widgets/ValidationPanelWidget.h"
namespace missionx {
ValidationPanelWidget::ValidationPanelWidget(QWidget* parent) : QListWidget(parent) {}
void ValidationPanelWidget::setMessages(const QStringList& messages) {
    clear();
    if (messages.isEmpty()) addItem("No validation issues.");
    for (const auto& msg : messages) addItem(msg);
}
}
