#pragma once
#include <QAbstractTableModel>
#include <QVector>
#include "domain/IncidentBookmark.h"

namespace missionx {
class BookmarkTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit BookmarkTableModel(QObject* parent = nullptr);
    void setBookmarks(const QVector<IncidentBookmark>& items);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
private:
    QVector<IncidentBookmark> bookmarks_;
};
}
