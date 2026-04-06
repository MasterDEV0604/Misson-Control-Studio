#pragma once
#include <QString>
#include <QVector>
#include "domain/Alert.h"
#include "domain/Scenario.h"
#include "services/EventJournal.h"

namespace missionx {
class ReportExporter {
public:
    bool exportDebrief(const Scenario& scenario,
                       const QVector<Alert>& alerts,
                       const QVector<JournalEntry>& journalEntries,
                       const QString& outputPath) const;
};
}
