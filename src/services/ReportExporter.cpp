#include "services/ReportExporter.h"
#include <QFile>
#include <QTextStream>

namespace missionx {
bool ReportExporter::exportDebrief(const Scenario& scenario,
                                   const QVector<Alert>& alerts,
                                   const QVector<JournalEntry>& journalEntries,
                                   const QString& outputPath) const {
    QFile file(outputPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;

    QTextStream out(&file);
    out << "# Mission Debrief

";
    out << "## Scenario
";
    out << "- Name: " << scenario.name << "
";
    out << "- Summary: " << scenario.summary << "

";

    out << "## Missions
";
    for (const auto& mission : scenario.missions) {
        out << "- **" << mission.title << "** — " << mission.objective << "
";
    }

    out << "
## Active Tracks
";
    for (const auto& track : scenario.initialTracks) {
        out << "- " << track.displayName << " (" << track.type << ")"
            << ", status=" << track.status
            << ", confidence=" << track.confidence
            << ", health=" << track.health << "
";
    }

    out << "
## Alerts
";
    if (alerts.isEmpty()) out << "- No alerts generated.
";
    for (const auto& alert : alerts) {
        out << "- [" << alert.severity << "] " << alert.source << ": " << alert.message << "
";
    }

    out << "
## Event Journal
";
    for (const auto& entry : journalEntries) {
        out << "- " << entry.timestamp.toString(Qt::ISODate) << " [" << entry.category << "] " << entry.message << "
";
    }
    return true;
}
}
