//  ConfirmationSender module
//  ConfirmationSender.h
//  YiHsun Lee
//  129713202
//  2021-06-16.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <iostream>
#include "ConfirmationSender.h"

namespace sdds{
ConfirmationSender::ConfirmationSender(){}

ConfirmationSender::ConfirmationSender(const ConfirmationSender& src){
    *this = src;
}

ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& src){
    if(this != &src){
        m_cnt = src.m_cnt;
        delete[] m_reservation;
        m_reservation = nullptr;
        m_reservation = new const Reservation * [m_cnt];
        for(size_t i = 0; i < m_cnt; i++){
            m_reservation[i] = src.m_reservation[i];
        }
    }
    return *this;
}

ConfirmationSender::ConfirmationSender(ConfirmationSender&& src) noexcept{
    *this = std::move(src);
}

ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& src) noexcept{
    if(this != &src){
        delete[] m_reservation;
        m_reservation = nullptr;
        m_cnt = src.m_cnt;
        src.m_cnt = 0;
        m_reservation = src.m_reservation;
        src.m_reservation = nullptr;
    }
    return *this;
}

ConfirmationSender& ConfirmationSender::operator+=(const Reservation& src){
    bool flag = false;
    for(size_t i = 0; i < m_cnt && !flag; i++){
        if(&src == m_reservation[i]){
            flag = true;
        }
    }
    if(!flag){
        const Reservation** temp = new const Reservation * [m_cnt+1];
        for(size_t i = 0; i < m_cnt; i++){
            temp[i] = m_reservation[i];
        }
        temp[m_cnt] = &src;
        m_cnt++;
        delete[] m_reservation;
        m_reservation = temp;
    }
    return *this;
}

ConfirmationSender& ConfirmationSender::operator-=(const Reservation& src){
    bool flag = false;
    size_t index = 0;
    for(size_t i = 0; i < m_cnt && flag == false; i++){
        if(&src == m_reservation[i]){
            m_reservation[i] = nullptr;
            flag = true;
            index = i;
        }
    }
    if(flag){
        const Reservation** temp = new const Reservation * [m_cnt-1];
        for(size_t j = 0; j < m_cnt-1; j++){
            if(j < index){
                temp[j] = m_reservation[j];
            } else {
                temp[j] = m_reservation[j+1];
            }
        }
        --m_cnt;
        delete[] m_reservation;
        m_reservation = nullptr;
        m_reservation = temp;
    }

    return *this;
}

ConfirmationSender::~ConfirmationSender(){
    delete[] m_reservation;
    m_reservation = nullptr;
}

std::ostream& operator<<(std::ostream& os, const ConfirmationSender& obj){
    os << "--------------------------\n"
    << "Confirmations to Send\n"
    << "--------------------------\n";
    if(obj.m_cnt == 0){
        os << "There are no confirmations to send!\n";
    } else {
        for(size_t i = 0; i < obj.m_cnt; i++){
            if(obj.m_reservation[i] != nullptr){
                os << *obj.m_reservation[i];
            }
        }
    }
    os << "--------------------------\n";
    return os;
}
}
