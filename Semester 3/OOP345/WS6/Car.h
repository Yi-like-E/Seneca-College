//  Car module
//  Car.h
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-06-30.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Car_h
#define SDDS_Car_h

#include <iostream>
#include "Vehicle.h"
namespace sdds{
class Car: public Vehicle{
    std::string m_maker{};
    std::string m_condition{};
    double m_topSpeed{0};
public:
    Car(){};
    Car(std::istream&);
    std::string condition()const;
    double topSpeed()const;
    void display(std::ostream& out)const;
    ~Car(){};
};
}

#endif /* SDDS_Car_h */
