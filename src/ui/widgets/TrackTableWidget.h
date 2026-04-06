#pragma once
#include <QTableView>
#include "ui/models/TrackTableModel.h"

namespace missionx {
class TrackTableWidget : public QTableView {
    Q_OBJECT
public:
    explicit TrackTableWidget(QWidget* parent = nullptr);
    void setTracks(const QVector<TrackState>& tracks);
private:
    TrackTableModel* model_ = nullptr;
};
}
