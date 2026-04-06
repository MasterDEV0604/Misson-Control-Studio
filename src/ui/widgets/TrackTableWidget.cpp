#include "ui/widgets/TrackTableWidget.h"
#include <QHeaderView>
namespace missionx {
TrackTableWidget::TrackTableWidget(QWidget* parent) : QTableView(parent), model_(new TrackTableModel(this)) {
    setModel(model_);
    horizontalHeader()->setStretchLastSection(true);
    verticalHeader()->setVisible(false);
    setSelectionBehavior(QAbstractItemView::SelectRows);
}
void TrackTableWidget::setTracks(const QVector<TrackState>& tracks) { model_->setTracks(tracks); }
}
