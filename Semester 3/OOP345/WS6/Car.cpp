//  Car module
//  Car.cpp
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-06-30.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include "Car.h"
using namespace std;
namespace sdds{
Car::Car(std::istream& is){
    string tag, maker, condition, speed;
    
    getline(is, tag, ',');
    getline(is, maker, ',');
    getline(is, condition, ',');
    getline(is, speed, ',');
    
    tag.erase(0, tag.find_first_not_of(" "));
    tag.erase(tag.find_last_not_of(" ")+1);
    
    maker.erase(0, maker.find_first_not_of(" "));
    maker.erase(maker.find_last_not_of(" ")+1);
    m_maker = maker;
    
    condition.erase(0, condition.find_first_not_of(" "));
    condition.erase(condition.find_last_not_of(" ")+1);
    
    speed.erase(0, speed.find_first_not_of(" "));
    speed.erase(speed.find_last_not_of(" ")+1);
    
    
    if(condition.empty() || condition == " "){
        m_condition = "new";
    } else if(condition == "n"){
        m_condition = "new";
    } else if(condition == "u"){
        m_condition = "used";
    } else if(condition == "b"){
        m_condition = "broken";
    } else {
        std::string err = "Invalid record!";
        throw err;
    }
    
    if(isdigit(speed[0])){
        m_topSpeed = stod(speed);
    } else{
        std::string err = "Invalid record!";
        throw err;
    }
}

std::string Car::condition()const{
    return m_condition;
}

double Car::topSpeed()const{
    return m_topSpeed;
}

void Car::display(std::ostream& out)const{
    out << "| ";
    out.setf(ios::right);
    out.width(10);
    out << m_maker << " | ";
    out.unsetf(ios::right);
    out.setf(ios::left);
    out.width(6);
    out << m_condition << " | ";
    out.width(6);
    out.setf(ios::fixed);
    out.precision(2);
    out << topSpeed() << " |";
}
}
