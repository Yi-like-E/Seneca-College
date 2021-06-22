//  Reservation module
//  Reservation.cpp
//  YiHsun Lee
//  129713202
//  2021-06-17.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <iostream>
#include "Reservation.h"
namespace sdds{
Reservation::Reservation(){};

Reservation::Reservation(const std::string& res){
    std::string id, name, email, temp, str;
    int numOfppl, day, hour;
    size_t firstComma = res.find(",");
    
    temp = res;
    for (size_t i = res.length()-1; i > firstComma; --i){
        if(res[i] == ' '){
            temp.erase(i, 1);
        }
    }
    
    id = temp.substr(0,temp.find(':'));
    id.erase(0, id.find_first_not_of(" "));
    id.erase(id.find_last_not_of(" ") + 1);
    temp.erase(0, temp.find(":")+1);
    
    name = temp.substr(0, temp.find(","));
    name.erase(0, name.find_first_not_of(" "));
    name.erase(name.find_last_not_of(" ") + 1);
    temp.erase(0, temp.find(",")+1);
    
    email = temp.substr(0, temp.find(","));
    temp.erase(0, temp.find(",")+1);
    
    numOfppl = stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",")+1);
    
    day = stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",")+1);
    
    hour = stoi(temp.substr(0, temp.find(" ")));
    
    m_reservationID = id;
    m_reservationName = name;
    m_email = email;
    m_numOfppl = numOfppl;
    m_day = day;
    m_hour = hour;
}

std::ostream& operator<<(std::ostream& os, const Reservation& obj){
    std::string individual = " people.";
    
    os << "Reservation ";
    os.width(10);
    os.setf(std::ios::right);
    os << obj.m_reservationID << ": ";
    os.width(20);
    os << obj.m_reservationName << "  ";
    os.unsetf(std::ios::right);
    os.setf(std::ios::left);
    os.width(20);
    os << "<" + obj.m_email + ">" << "    ";
    
    if(obj.m_numOfppl == 1){
        individual = " person.";
    }
    
    if(obj.m_hour >= 6 && obj.m_hour <=9){
        os << "Breakfast on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_numOfppl << individual << std::endl;
    } else if (obj.m_hour >= 11 && obj.m_hour <=15){
        os << "Lunch on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_numOfppl << individual << std::endl;
    } else if (obj.m_hour >= 17 && obj.m_hour <= 21){
        os << "Dinner on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_numOfppl << individual << std::endl;
    } else {
        os << "Drinks on day " << obj.m_day << " @ " << obj.m_hour << ":00 for " << obj.m_numOfppl << individual << std::endl;
    }
    return os;
}
}
