// Name: YiHsun Lee
// Student No. :129713202
// Email: ylee212@myseneca.ca
// Section: NII
// Date: 03/15/2021

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "MotorVehicle.h"
using namespace std;

namespace sdds{

MotorVehicle::MotorVehicle(const char plate[], int year){
    if(strLen(plate) !=0 && strLen(plate) < MAX_PlateNum && year > 0){
        strCpy(licensePlate, plate);
        strCpy(addressOfVehicle, "Factory");
        yearBuilt = year;
    }
}

void MotorVehicle::moveTo(const char* address){
    if(strCmp(addressOfVehicle, address) != 0 && strLen(address) < MAX_Address){
        cout << "|" ;
        cout.setf(ios::right);
        cout.width(8);
        cout << licensePlate << "| |";
        cout.width(20);
        cout << addressOfVehicle;
        cout << " ---> ";
        cout.unsetf(ios::right);
        cout.setf(ios::left);
        cout.width(20);
        cout << address << "|" << endl;
        strCpy(addressOfVehicle, address);
    }
}

ostream& MotorVehicle::write(ostream& os)const{
    os << "| " << yearBuilt << " | " << licensePlate << " | " << addressOfVehicle;
    return os;
}

istream& MotorVehicle::read(istream& is){
    cout << "Built year: ";
    is >> yearBuilt;
    cout << "License plate: ";
    is >> licensePlate;
    cout << "Current location: ";
    is >> addressOfVehicle;
    return is;
}

MotorVehicle::~MotorVehicle(){};

ostream& operator<<(ostream& os, const MotorVehicle& vehicle){
    return vehicle.write(os);
}

istream& operator>>(istream& is, MotorVehicle& vehicle){
    return vehicle.read(is);
}

}
