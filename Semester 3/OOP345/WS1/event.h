//  event module
//  event.h
//  YiHsun Lee
//  ylee212@myseneca.ca
//  129713202
//  2021/05/27
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef _SDDS_EVENT_H
#define _SDDS_EVENT_H

extern size_t g_sysClock;

namespace sdds{
class Event{
    char* desc{nullptr};
    size_t time = 0;
public:
    Event();
    void display();
    void set(const char* src = nullptr);
    Event(const Event& src); // copy constructor
    Event& operator=(const Event& src); // copy assignment operator
    ~Event(); // destructor
};
}
#endif /* _SDDS_EVENT_H */
