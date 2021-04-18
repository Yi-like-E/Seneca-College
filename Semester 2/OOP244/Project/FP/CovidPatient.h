/* Citation and Sources...
 Final Project Milestone 1
 Module: CovidPatient
 Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
namespace sdds {

class CovidPatient: public Patient {
public:
    CovidPatient();
    virtual char type()const;
    virtual istream& csvRead(istream& is);
    virtual ostream& write(ostream& os)const;
    virtual istream& read(istream& is);
};

}
#endif // !SDDS_COVIDPATIENT_H_
