//  Restaurant module
//  Restaurant.cpp
//  YiHsun Lee
//  129713202
//  2021-06-16.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <iostream>
#include "Restaurant.h"

namespace sdds{
Restaurant::Restaurant(){}

Restaurant::Restaurant(const Reservation* reservations[], size_t cnt){
    if(reservations != nullptr){
        m_cnt = cnt;
        m_reservation = new Reservation[m_cnt];
        for(size_t i = 0; i < cnt; i++){
            m_reservation[i] = *reservations[i];
        }
    }
}

size_t Restaurant::size()const{
    return m_cnt;
}

Restaurant::Restaurant(const Restaurant& src){
    *this = src;
}

Restaurant& Restaurant::operator=(const Restaurant& src){
    if(this != &src){
        delete[] m_reservation;
        m_reservation = nullptr;
        m_cnt = src.m_cnt;
        m_reservation = new Reservation[m_cnt];
        for(size_t i = 0; i < m_cnt; i++){
            m_reservation[i] = src.m_reservation[i];
        }
    }
    return *this;
}

Restaurant::Restaurant(Restaurant&& src) noexcept{
    *this = std::move(src);
}

Restaurant& Restaurant::operator=(Restaurant&& src) noexcept{
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

Restaurant::~Restaurant(){
    delete[] m_reservation;
    m_reservation = nullptr;
}

std::ostream& operator<<(std::ostream& os, const Restaurant& obj){
    static int count = 1;
    os << "--------------------------\n"
       << "Fancy Restaurant (" << count++ << ")\n"
       << "--------------------------\n";
    if(obj.m_cnt == 0){
        os << "This restaurant is empty!\n";
    } else {
        for(size_t i = 0; i < obj.m_cnt; i++){
            os << obj.m_reservation[i];
        }
    }
    os << "--------------------------\n";
    return os;
}
}
