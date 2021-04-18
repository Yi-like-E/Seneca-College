/* Citation and Sources...
 Final Project Milestone 2
 Module: Patient
 Filename: Patient.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2020/3/23  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */

#include <iostream>
#include <cstring>
#include <string>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds{

Patient::Patient(int ticketnum, bool fileFlag):ticketObj(ticketnum){
    flag = fileFlag;
    patientName = nullptr;
}

char Patient::type()const{
    char ch = 'a';
    return ch;
}

Patient::~Patient(){
    delete[] patientName;
    patientName = nullptr;
}

bool Patient::fileIO()const{
    return flag;
}

void Patient::fileIO(bool val){
    flag = val;
}

void Patient::setArrivalTime(){
    ticketObj.resetTime();
}

Patient::operator Time() const{
    return Time(ticketObj);
}

int Patient::number() const{
    return ticketObj.number();
}

ostream& Patient::csvWrite(ostream& os)const{
    os << type() << "," << patientName << "," << ohip << ",";
    ticketObj.csvWrite(os);
    return os;
}

istream& Patient::csvRead(istream& is){
    string name;
    getline(is, name, ',');
    delete[] patientName;
    patientName = nullptr;
    patientName = new char[strlen(name.c_str())+1];
    strcpy(patientName, name.c_str());
    is >> ohip;
    is.ignore(1000, ',');
    ticketObj.csvRead(is);
    return is;
}

ostream& Patient::write(ostream& os)const{
    int i;
    ticketObj.write(os);
    os << endl;
    if(strlen(patientName) > 25){
        for(i = 0; i < 25; i++){
            os << patientName[i];
        }
    } else {
        os << patientName;
    }
    os << ", OHIP: " << ohip;
    return os;
}

istream& Patient::read(istream& is){
    string name;
    int num;
    cout << "Name: ";
    getline(is,name,'\n');
    delete[] patientName;
    patientName = nullptr;
    patientName = new char[strlen(name.c_str())+1];
    strcpy(patientName, name.c_str());
    num = getInt(100000000, 999999999, "OHIP:", "Invalid OHIP Number, ", true);
    ohip = num;
    return is;
}

bool operator==(const Patient& patient, char ch){
    return patient.type() == ch;
}

bool operator==(const Patient& p1, const Patient& p2){
    return p1.type() == p2.type();
}
}
