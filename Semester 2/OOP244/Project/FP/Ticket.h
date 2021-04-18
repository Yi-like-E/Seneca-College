/* Citation and Sources...
 Final Project Milestone 1
 Module: Ticket
 Filename: Ticket.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2021/3/23  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */
#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
class Ticket:public IOAble{
    Time m_time;
    int m_number;
public:
    Ticket(int number);
    operator Time()const;
    int number()const;
    void resetTime();
    std::ostream& csvWrite(std::ostream& ostr)const;
    std::istream& csvRead(std::istream& istr);
    std::ostream& write(std::ostream& ostr )const;
    std::istream& read(std::istream& istr);
};
}
#endif // !SDDS_TICKET_H_
