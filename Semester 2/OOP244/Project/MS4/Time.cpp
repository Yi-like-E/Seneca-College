/* Citation and Sources...
 Final Project Milestone 1
 Module: Time
 Filename: Time.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2020/3/9  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {

Time& Time::setToNow(){
    m_min = getTime();
    return *this;
}

Time::Time(unsigned int min){
    m_min = min;
}

std::ostream& Time::write(std::ostream& ostr) const{
    ostr.width(2);
    ostr.fill('0');
    ostr << m_min/60 << ":";
    ostr.width(2);
    ostr.fill('0');
    ostr << m_min % 60;
    return ostr;
}

std::istream& Time::read(std::istream& istr){
    int hour = 0, min = 0;
    char col = '!';
    istr >> hour >> col >> min;
    if(col != ':' || hour < 0 || min < 0){
        istr.setstate(ios::failbit);
    }
    else {
        m_min = hour * 60 + min;
    }
    return istr;
}

Time& Time::operator-=(const Time& D){
    if(m_min < D.m_min){
        m_min += 24 * ((D.m_min/ (24*60)) +1) * 60;
    }
    m_min -= D.m_min;
    return *this;
}

Time Time::operator-(const Time& D)const{
    Time temp = *this;
    if(temp.m_min < D.m_min){
        temp.m_min += 24 * ((D.m_min/ (24*60)) +1) * 60;
    }
    temp.m_min -= D.m_min;
    return temp;
}

Time& Time::operator+=(const Time& D){
    m_min += D.m_min;
    return *this;
}

Time Time::operator+(const Time& D)const{
    Time temp = *this;
    temp.m_min += D.m_min;
    return temp;
}

Time& Time::operator=(unsigned int val){
    m_min = val;
    return *this;
}

Time& Time::operator *= (unsigned int val){
    m_min *= val;
    return *this;
}

Time Time::operator *(unsigned int val)const{
    Time temp = *this;
    temp.m_min *= val;
    return temp;
}

Time& Time::operator /= (unsigned int val){
    m_min /= val;
    return *this;
}

Time Time::operator /(unsigned int val)const{
    Time temp = *this;
    temp.m_min /= val;
    return temp;
}

Time::operator unsigned int()const{
    return m_min;
}

Time::operator int()const{
    return (int)m_min;
}

std::ostream& operator<<(std::ostream& ostr, const Time& D){
    return D.write(ostr);
}

std::istream& operator>>(std::istream& istr, Time& D){
    return D.read(istr);
}

}

