//  TimedEvents module
//  TimedEvents.h
//  YiHsun Lee
//  129713202
//  2021-06-0ˇ.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_TimedEvents_h
#define SDDS_TimedEvents_h

#include <ctime>
#include <chrono>
#include <string>
#define MAX_EVT 10 // maximum number of event object
namespace sdds{
class TimedEvents{
    int numOfRec;
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point endTime;
    struct{
        std::string eventName;
        std::string unitsOfTime;
        std::chrono::steady_clock::duration duration;
    }Events[MAX_EVT];
public:
    TimedEvents();
    void startClock();
    void stopClock();
    void addEvent(const char*);
    friend std::ostream& operator<<(std::ostream&, const TimedEvents&);
};
}

#endif /* SDDS_TimedEvents_h */
