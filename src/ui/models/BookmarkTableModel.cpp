#include "ui/models/BookmarkTableModel.h"
namespace missionx {
BookmarkTableModel::BookmarkTableModel(QObject* parent) : QAbstractTableModel(parent) {}
void BookmarkTableModel::setBookmarks(const QVector<IncidentBookmark>& items) { beginResetModel(); bookmarks_ = items; endResetModel(); }
int BookmarkTableModel::rowCount(const QModelIndex&) const { return bookmarks_.size(); }
int BookmarkTableModel::columnCount(const QModelIndex&) const { return 3; }
QVariant BookmarkTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || role != Qt::DisplayRole) return {};
    const auto& b = bookmarks_.at(index.row());
    if (index.column() == 0) return b.timestampSeconds;
    if (index.column() == 1) return b.category;
    return b.title;
}
}
