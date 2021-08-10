// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/11
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_Workstation_h
#define SDDS_Workstation_h

#include <iostream>
#include <deque>
#include "CustomerOrder.h"
namespace sdds{
extern std::deque<CustomerOrder>pending;
extern std::deque<CustomerOrder>completed;
extern std::deque<CustomerOrder>incomplete;
class Workstation:public Station{
    std::deque<CustomerOrder>m_orders{};
    Workstation* m_pNextStation = nullptr;
public:
    explicit Workstation(const std::string& str);
    void fill(std::ostream& os);
    bool attemptToMoveOrder();
    void setNextStation(Workstation* station = nullptr);
    Workstation* getNextStation() const;
    void display(std::ostream& os) const;
    Workstation& operator+=(CustomerOrder&& newOrder);
    
    Workstation(const Workstation&) = delete;
    Workstation& operator=(const Workstation&) = delete;
    Workstation(Workstation&&) = delete;
    Workstation& operator=(Workstation&&) = delete;
};
}

#endif /* SDDS_Workstation_h */
