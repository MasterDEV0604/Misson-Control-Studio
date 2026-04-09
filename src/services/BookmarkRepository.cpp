#include "services/BookmarkRepository.h"

namespace missionx {
QVector<IncidentBookmark> BookmarkRepository::loadExampleBookmarks() const {
    return {{45, "warning", "Route review", "Possible overlap near handoff checkpoint"},
            {95, "note", "Pause and inspect", "Operator manually inspected relay alignment"}};
}
}
