//  Reservation module
//  Reservation.h
//  YiHsun Lee
//  129713202
//  2021-06-17.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Reservation_h
#define SDDS_Reservation_h

#include <iostream>
#include <string>

namespace sdds{
class Reservation{
    std::string m_reservationID{""};
    std::string m_reservationName{""};
    std::string m_email{""};
    int m_numOfppl{0};
    int m_day{0};
    int m_hour{0};
public:
    Reservation();
    Reservation(const std::string&);
    friend std::ostream& operator<<(std::ostream&, const Reservation&);
};
}

#endif /* SDDS_Reservation_h */
