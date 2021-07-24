//  Racecar module
//  Racecar.cpp
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-06-30.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include "Racecar.h"
using namespace std;
namespace sdds{
Racecar::Racecar(std::istream& in):Car(in){
    string tmp;
    getline(in, tmp, '\n');
    m_booster = std::stod(tmp);
}

void Racecar::display(std::ostream& out)const{
    Car::display(out);
    out << "*";
}

double Racecar::topSpeed()const{
    return Car::topSpeed()*(1+m_booster);
}
}
