/* Citation and Sources...
 Final Project Milestone 1
 Module: CovidPatient
 Filename: CovidPatient.cpp
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

#include "CovidPatient.h"

namespace sdds {
int nextCovidTicket = 1;

CovidPatient::CovidPatient():Patient(nextCovidTicket,fileIO()){
    nextCovidTicket++;
}

char CovidPatient::type()const{
    char ch = 'C';
    return ch;
}

istream& CovidPatient::csvRead(istream& is){
    Patient::csvRead(is);
    nextCovidTicket = Patient::number() + 1;
    is.ignore(100, '\n');
    return is;
}

ostream& CovidPatient::write(ostream& os)const{
    if(fileIO()){
        Patient::csvWrite(os);
    } else {
        os << "COVID TEST" << endl;
        Patient::write(os) << endl;
    }
    return os;
}

istream& CovidPatient::read(istream& is){
    if(fileIO()){
        csvRead(is);
    } else {
        Patient::read(is);
    }
    return is;
}
}
