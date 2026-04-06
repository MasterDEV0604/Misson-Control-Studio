#pragma once
namespace missionx {
class TimelineScheduler {
public:
    void setRate(double rate) { rate_ = rate; }
    double rate() const { return rate_; }
private:
    double rate_ = 1.0;
};
}
