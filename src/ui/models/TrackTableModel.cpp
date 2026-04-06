#include "ui/models/TrackTableModel.h"
#include <QBrush>

namespace missionx {
TrackTableModel::TrackTableModel(QObject* parent) : QAbstractTableModel(parent) {}
void TrackTableModel::setTracks(const QVector<TrackState>& tracks) {
    beginResetModel();
    tracks_ = tracks;
    endResetModel();
}
const TrackState* TrackTableModel::trackAt(int row) const {
    if (row < 0 || row >= tracks_.size()) return nullptr;
    return &tracks_[row];
}
int TrackTableModel::rowCount(const QModelIndex&) const { return tracks_.size(); }
int TrackTableModel::columnCount(const QModelIndex&) const { return 6; }
QVariant TrackTableModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid()) return {};
    const auto& t = tracks_[index.row()];
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
            case 0: return t.displayName;
            case 1: return t.type;
            case 2: return t.status;
            case 3: return t.health;
            case 4: return QString::number(t.confidence, 'f', 2);
            case 5: return QString("(%1, %2)").arg(t.position.x(), 0, 'f', 1).arg(t.position.y(), 0, 'f', 1);
        }
    }
    if (role == Qt::ForegroundRole && index.column() == 3) {
        if (t.health == "red") return QBrush(Qt::red);
        if (t.health == "amber") return QBrush(QColor(255, 190, 64));
    }
    return {};
}
QVariant TrackTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) {
        case 0: return "Track";
        case 1: return "Type";
        case 2: return "Status";
        case 3: return "Health";
        case 4: return "Confidence";
        case 5: return "Position";
    }
    return {};
}
}
