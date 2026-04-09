#include "ui/widgets/BookmarkWidget.h"
namespace missionx {
BookmarkWidget::BookmarkWidget(QWidget* parent) : QListWidget(parent) {}
void BookmarkWidget::setBookmarks(const QVector<IncidentBookmark>& bookmarks) {
    clear();
    for (const auto& b : bookmarks) addItem(QString("[%1s] %2 - %3").arg(b.timestampSeconds).arg(b.category, b.title));
}
}
