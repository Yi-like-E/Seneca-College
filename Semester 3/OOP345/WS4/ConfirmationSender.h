//  ConfirmationSender module
//  ConfirmationSender.h
//  YiHsun Lee
//  129713202
//  2021-06-12.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments
#ifndef SDDS_ConfirmationSender_h
#define SDDS_ConfirmationSender_h

#include <iostream>
#include "Reservation.h"

namespace sdds{
class ConfirmationSender{
    const Reservation** m_reservation{};
    size_t m_cnt{};
public:
    ConfirmationSender();
    ConfirmationSender(const ConfirmationSender&);
    ConfirmationSender& operator=(const ConfirmationSender&);
    ConfirmationSender(ConfirmationSender&&) noexcept;
    ConfirmationSender& operator=(ConfirmationSender&&) noexcept;
    ConfirmationSender& operator+=(const Reservation&);
    ConfirmationSender& operator-=(const Reservation&);
    ~ConfirmationSender();
    friend std::ostream& operator<<(std::ostream&, const ConfirmationSender&);
};
}

#endif /* ConfirmationSender_h */
