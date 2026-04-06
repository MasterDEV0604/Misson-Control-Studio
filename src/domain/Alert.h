#pragma once
#include <QString>

namespace missionx {
struct Alert {
    QString severity;
    QString source;
    QString message;
};
}
