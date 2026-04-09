#pragma once
#include <QListWidget>
#include <QVector>
#include "domain/IncidentBookmark.h"

namespace missionx {
class BookmarkWidget : public QListWidget {
    Q_OBJECT
public:
    explicit BookmarkWidget(QWidget* parent = nullptr);
    void setBookmarks(const QVector<IncidentBookmark>& bookmarks);
};
}
