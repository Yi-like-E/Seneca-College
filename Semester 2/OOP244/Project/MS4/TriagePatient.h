/* Citation and Sources...
 Final Project Milestone 1
 Module: TriagePatient
 Filename: TriagePatient.h
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2020/3/29  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */

#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include "Patient.h"
namespace sdds {

class TriagePatient:public Patient{
    char* symptom;
public:
    TriagePatient();
    virtual char type()const;
    virtual ostream& csvWrite(ostream& os)const;
    virtual istream& csvRead(istream& is);
    virtual ostream& write(ostream& os)const;
    virtual istream& read(istream& is);
    ~TriagePatient();
};
}
#endif // !SDDS_TRIAGEPATIENT_H
