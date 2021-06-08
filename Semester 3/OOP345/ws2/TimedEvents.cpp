//  TimedEvents module
//  TimedEvents.cpp
//  YiHsun Lee
//  129713202
//  2021-06-03.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <iostream>
#include "TimedEvents.h"
using namespace std;
namespace sdds{
TimedEvents::TimedEvents(){
    numOfRec = 0;
    startTime = {};
    endTime = {};
    for(int i = 0; i < MAX_EVT; i++){
        Events[i].eventName = '\0';
        Events[i].unitsOfTime = '\0';
        Events[i].duration = {};
        Events[i].eventName = "";
    }
}

void TimedEvents::startClock(){
    startTime = std::chrono::steady_clock::now();
}

void TimedEvents::stopClock(){
    endTime = std::chrono::steady_clock::now();
}

void TimedEvents::addEvent(const char* eventName){
    Events[numOfRec].eventName = eventName;
    Events[numOfRec].unitsOfTime = "nanoseconds";
    Events[numOfRec].duration = std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime);
    numOfRec++;
    
}

ostream& operator<<(ostream& os, const TimedEvents& evt){
    os << "--------------------------\n"
    << "Execution Times:\n"
    << "--------------------------\n";
    for(int i = 0; i < evt.numOfRec; i++){
        os.width(21);
        os.setf(std::ios::left);
        os << evt.Events[i].eventName;
        os.width(13);
        os.setf(std::ios::right);
        os << evt.Events[i].duration.count();
        os << " " << evt.Events[i].unitsOfTime << endl;
        os.unsetf(std::ios::right);
    }
    os << "--------------------------\n";
    return os;
}

}
