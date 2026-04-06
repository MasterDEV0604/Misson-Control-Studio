#pragma once
#include <QString>
#include "app/WorkspaceState.h"

namespace missionx {
class WorkspaceRepository {
public:
    bool save(const QString& path, const WorkspaceState& state) const;
    bool load(const QString& path, WorkspaceState& state) const;
};
}
