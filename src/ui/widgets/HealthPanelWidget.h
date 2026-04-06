#pragma once
#include <QTextEdit>
#include <QVector>
#include "domain/TrackState.h"

namespace missionx {
class HealthPanelWidget : public QTextEdit {
    Q_OBJECT
public:
    explicit HealthPanelWidget(QWidget* parent = nullptr);
    void setTracks(const QVector<TrackState>& tracks);
};
}
