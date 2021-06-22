//  Restaurant module
//  Restaurant.h
//  YiHsun Lee
//  129713202
//  2021-06-12.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments
#ifndef SDDS_Restaurant_h
#define SDDS_Restaurant_h

#include <iostream>
#include "Reservation.h"

namespace sdds{
class Restaurant{
    Reservation* m_reservation{};
    size_t m_cnt{};
public:
    Restaurant();
    Restaurant(const Reservation* reservations[], size_t cnt);
    size_t size()const;
    Restaurant(const Restaurant&);
    Restaurant& operator=(const Restaurant&);
    Restaurant(Restaurant&&) noexcept;
    Restaurant& operator=(Restaurant&&) noexcept;
    ~Restaurant();
    friend std::ostream& operator<<(std::ostream&, const Restaurant&);
};
}

#endif /* Restaurant_h */
