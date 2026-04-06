#include "ui/widgets/MapCanvas.h"
#include <QPainter>

namespace missionx {
MapCanvas::MapCanvas(QWidget* parent) : QWidget(parent) { setMinimumSize(720, 480); }
void MapCanvas::setTracks(const QVector<TrackState>& tracks) { tracks_ = tracks; update(); }
void MapCanvas::setRoutes(const QVector<Route>& routes) { routes_ = routes; update(); }
void MapCanvas::setShowLabels(bool enabled) { showLabels_ = enabled; update(); }
void MapCanvas::setShowThreatRings(bool enabled) { showThreatRings_ = enabled; update(); }

void MapCanvas::paintEvent(QPaintEvent*) {
    QPainter p(this);
    p.fillRect(rect(), QColor("#182030"));
    p.setRenderHint(QPainter::Antialiasing, true);

    p.setPen(QPen(QColor("#2e3a52"), 1));
    for (int x = 0; x < width(); x += 40) p.drawLine(x, 0, x, height());
    for (int y = 0; y < height(); y += 40) p.drawLine(0, y, width(), y);

    p.setPen(QPen(QColor("#7db7ff"), 2));
    for (const auto& route : routes_) {
        for (int i = 1; i < route.points.size(); ++i) p.drawLine(route.points[i-1].position, route.points[i].position);
        for (const auto& point : route.points) p.drawEllipse(point.position, 4, 4);
    }

    for (const auto& track : tracks_) {
        QColor color = QColor("#90e39a");
        if (track.health == "amber") color = QColor("#ffd27d");
        if (track.health == "red") color = QColor("#ff8f8f");
        p.setBrush(color);
        p.setPen(Qt::NoPen);
        p.drawEllipse(track.position, 8, 8);
        if (showThreatRings_) {
            p.setBrush(Qt::NoBrush);
            p.setPen(QPen(QColor(255, 255, 255, 32), 1));
            p.drawEllipse(track.position, 22, 22);
        }
        if (showLabels_) {
            p.setPen(Qt::white);
            p.drawText(track.position + QPointF(10, -10), track.displayName);
        }
    }
}
}
