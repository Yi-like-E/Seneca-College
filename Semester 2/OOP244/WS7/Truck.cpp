// Name: YiHsun Lee
// Student No. :129713202
// Email: ylee212@myseneca.ca
// Section: NII
// Date: 03/15/2021

#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include "MotorVehicle.h"
#include <iostream>
using namespace std;
namespace sdds {

Truck::Truck(const char plate[], int year, double capacity, const char address[]):MotorVehicle(plate, year){
    maxWeight = capacity;
    currentLoad = 0;
    moveTo(address);
}

bool Truck::addCargo(double cargo){
    bool flag = false;
    if(currentLoad < maxWeight){
        if((currentLoad + cargo) <= maxWeight){
            currentLoad += cargo;
        } else {
            currentLoad = maxWeight;
        }
        flag = true;
    }
    return flag;
}

bool Truck::unloadCargo(){
    bool flag = false;
    if(currentLoad != 0){
        currentLoad = 0;
        flag = true;
    }
    return flag;
}

ostream& Truck::write(ostream& os)const{
    MotorVehicle::write(os);
    os << " | " << currentLoad << "/" << maxWeight;
    return os;
}

istream& Truck::read(istream& is){
    MotorVehicle::read(is);
    cout << "Capacity: ";
    is >> maxWeight;
    cout << "Cargo: ";
    is >> currentLoad;
    return is;
}

Truck::~Truck(){};

ostream& operator<<(ostream& os, const Truck& truck){
    return truck.write(os);
}

istream& operator>>(istream& is, Truck& truck){
    return truck.read(is);
}

}
