//  Racecar module
//  Racecar.h
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-06-30.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Racecar_h
#define SDDS_Racecar_h

#include <iostream>
#include "Car.h"
namespace sdds{
class Racecar: public Car{
    double m_booster{0.0};
public:
    Racecar(std::istream& in);
    void display(std::ostream& out)const;
    double topSpeed()const;
};
}

#endif /* SDDS_Racecar_h */
