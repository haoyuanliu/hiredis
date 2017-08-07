#include <unistd.h>
#include <stdint.h>
#include <sys/time.h>
#include <stdio.h>
#include <string>
static int kMicroSecondsPerSecond = 1000*1000;

class TimeStamp {
    public:
        TimeStamp() : microSecondsSinceEpoch_(0) {}
        TimeStamp(int64_t microSeconds) : microSecondsSinceEpoch_(microSeconds) {}
        static TimeStamp now();
        std::string toString();
        std::string toFormattedString(bool showMicroSeconds = true);
        int64_t getSeconds();
        int64_t getMicroSecondsSinceEpoch();
    private:
        int64_t microSecondsSinceEpoch_;
};
inline TimeStamp addTime(TimeStamp time, double seconds) {
    int64_t delta = static_cast<int64_t>(seconds * kMicroSecondsPerSecond);
    return TimeStamp(time.getMicroSecondsSinceEpoch() + delta);
}
inline double timeDiff(TimeStamp high, TimeStamp low) {
    int64_t diff = high.getMicroSecondsSinceEpoch() - low.getMicroSecondsSinceEpoch();
    return static_cast<double>(diff) / kMicroSecondsPerSecond;
}
