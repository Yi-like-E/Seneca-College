/* Citation and Sources...
 Final Project Milestone 1
 Module: TriagePatient
 Filename: TriagePatient.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2021/3/29  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */
#include <iostream>
#include <string>
#include <cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
int nextTriageTicket = 1;

TriagePatient::TriagePatient():Patient(nextTriageTicket,fileIO()){
    symptom = nullptr;
    nextTriageTicket = 1;
    nextTriageTicket++;
}

char TriagePatient::type()const{
    char ch = 'T';
    return ch;
}

ostream& TriagePatient::csvWrite(ostream& os)const{
    Patient::csvWrite(os);
    os << "," << symptom;
    return os;
}

istream& TriagePatient::csvRead(istream& is){
    string str;
    delete[] symptom;
    symptom = nullptr;
    Patient::csvRead(is);
    is.ignore(1000, ',');
    getline(is, str, '\n');
    symptom = new char[strlen(str.c_str())+1];
    strcpy(symptom, str.c_str());
    nextTriageTicket = Patient::number() + 1;
    return is;
}

ostream& TriagePatient::write(ostream& os)const{
    if(fileIO()){
        csvWrite(os);
    } else {
        os << "TRIAGE" << endl;
        Patient::write(os);
        os << endl;
        os << "Symptoms: " << symptom << endl;
    }
    return os;
}

istream& TriagePatient::read(istream& is){
    if(fileIO()){
        csvRead(is);
    } else {
        delete[] symptom;
        symptom = nullptr;
        Patient::read(is);
        symptom = getcstr("Symptoms: ", is, '\n');
    }
    return is;
}

TriagePatient::~TriagePatient(){
    delete[] symptom;
    symptom = nullptr;
}
}
