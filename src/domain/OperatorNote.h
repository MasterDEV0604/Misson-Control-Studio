#pragma once
#include <QString>

namespace missionx {
struct OperatorNote {
    int timestampSeconds = 0;
    QString author;
    QString text;
    QString tag;
};
}
