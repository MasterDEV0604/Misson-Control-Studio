#pragma once
#include <QVector>
#include "domain/IncidentBookmark.h"

namespace missionx {
class BookmarkRepository {
public:
    QVector<IncidentBookmark> loadExampleBookmarks() const;
};
}
