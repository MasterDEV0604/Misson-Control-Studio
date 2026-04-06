#pragma once
#include <QWidget>
#include <QVector>
#include "domain/Route.h"
#include "domain/TrackState.h"

namespace missionx {
class MapCanvas : public QWidget {
    Q_OBJECT
public:
    explicit MapCanvas(QWidget* parent = nullptr);

    void setTracks(const QVector<TrackState>& tracks);
    void setRoutes(const QVector<Route>& routes);
    void setShowLabels(bool enabled);
    void setShowThreatRings(bool enabled);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    QVector<TrackState> tracks_;
    QVector<Route> routes_;
    bool showLabels_ = true;
    bool showThreatRings_ = true;
};
}
