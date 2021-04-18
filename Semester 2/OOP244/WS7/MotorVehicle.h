// Name: YiHsun Lee
// Student No. :129713202
// Email: ylee212@myseneca.ca
// Section: NII
// Date: 03/15/2021

#ifndef MotorVehicle_h
#define MotorVehicle_h

#include <iostream>
using namespace std;

const int MAX_PlateNum = 9;
const int MAX_Address = 64;
namespace sdds{

class MotorVehicle{
    char licensePlate[MAX_PlateNum];
    char addressOfVehicle[MAX_Address];
    int yearBuilt;
public:
    MotorVehicle(const char plate[], int year);
    void moveTo(const char* address);
    ostream& write(ostream& os)const;
    istream& read(istream& is);
    ~MotorVehicle();
};
ostream& operator<<(ostream& os, const MotorVehicle& vehicle);
istream& operator>>(istream& is, MotorVehicle& vehicle);
}

#endif /* MotorVehicle_hpp */
