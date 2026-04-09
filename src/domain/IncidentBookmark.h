#pragma once
#include <QString>

namespace missionx {
struct IncidentBookmark {
    int timestampSeconds = 0;
    QString category;
    QString title;
    QString details;
};
}
