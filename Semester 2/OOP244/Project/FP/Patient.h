/* Citation and Sources...
 Final Project Milestone 2
 Module: Patient
 Filename: Patient.h
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2021/3/23  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */

#ifndef Patient_h
#define Patient_h

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

using namespace std;
namespace sdds{
class Patient: public IOAble{
    char* patientName;
    int ohip;
    Ticket ticketObj;
    bool flag;
public:
    Patient(int ticketnum = 0, bool fileFlag = false);
    ~Patient();
    Patient(const Patient&) = delete;
    Patient& operator=(const Patient&) = delete;
    virtual char type()const = 0;
    bool fileIO()const;
    void fileIO(bool flag);
    void setArrivalTime();
    operator Time() const;
    int number() const;
    virtual ostream& csvWrite(ostream& os)const;
    virtual istream& csvRead(istream& is);
    virtual ostream& write(ostream& os)const;
    virtual istream& read(istream& is);
};
bool operator==(const Patient& patient, char ch);
bool operator==(const Patient& p1, const Patient& p2);
}

#endif /* Patient_h */
