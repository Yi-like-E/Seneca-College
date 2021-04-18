// Name: YiHsun Lee
// Student No. :129713202
// Email: ylee212@myseneca.ca
// Section: NII
// Date: 03/15/2021

#ifndef Truck_h
#define Truck_h

#include <iostream>
#include <cstring>
#include "MotorVehicle.h"
using namespace std;
namespace sdds {

class Truck: public MotorVehicle{
    double maxWeight;
    double currentLoad;
public:
    Truck(const char plate[], int year, double capacity, const char address[]);
    bool addCargo(double cargo);
    bool unloadCargo();
    ostream& write(ostream& os)const;
    istream& read(istream& is);
    ~Truck();
};
ostream& operator<<(ostream& os, const Truck& truck);
istream& operator>>(istream& is, Truck& truck);
}

#endif /* Truck_hpp */
