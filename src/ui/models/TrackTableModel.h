#pragma once
#include <QAbstractTableModel>
#include <QVector>
#include "domain/TrackState.h"

namespace missionx {
class TrackTableModel : public QAbstractTableModel {
    Q_OBJECT
public:
    explicit TrackTableModel(QObject* parent = nullptr);

    void setTracks(const QVector<TrackState>& tracks);
    const TrackState* trackAt(int row) const;

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

private:
    QVector<TrackState> tracks_;
};
}
