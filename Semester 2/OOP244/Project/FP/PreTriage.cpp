/* Citation and Sources...
 Final Project Milestone 1
 Module: TriagePatient
 Filename: PreTriage.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2021/4/05  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {

PreTriage::PreTriage(const char* dataFilename):
m_averCovidWait(15), m_averTriageWait(5),
m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2),
m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
{
    if(m_dataFilename != nullptr){
        delete[] m_dataFilename;
    }
    m_dataFilename = new char[strlen(dataFilename)+1];
    strcpy(m_dataFilename, dataFilename);
    load();
}

PreTriage::~PreTriage(){
    ofstream fout;
    int i;
    fout.open(m_dataFilename);
    if(fout.is_open()){
        fout << m_averCovidWait << "," << m_averTriageWait << endl;
        cout << "Saving Average Wait Times,\n" << "   COVID Test: " << m_averCovidWait
             << endl << "   Triage: " << m_averTriageWait << endl << "Saving m_lineup...\n";
        for(i = 0; i < m_lineupSize; i++){
            m_lineup[i]->csvWrite(fout) << endl;
            cout << i+1 << "- ";
            m_lineup[i]->csvWrite(cout) << endl;
            delete m_lineup[i];
            
        }
        delete[] m_dataFilename;
        cout << "done!" << endl;
    }
}

const Time PreTriage::getWaitTime(const Patient& p)const{
    int i, count = 0;
    Time time;
    for(i = 0; i < m_lineupSize; i++){
        if(m_lineup[i]->type() == p.type()){
            count++;
        }
    }
    time *= count;
    return time;
}

void PreTriage::setAverageWaitTime(const Patient& p){
    Time ct;
    unsigned int ticketNum = p.number();
    
    ct.setToNow();
    if(p.type() == 'C'){
        m_averCovidWait = ((ct - p.operator Time()) + (m_averCovidWait * (ticketNum - 1))) / ticketNum;
    }
    else if(p.type() == 'T'){
        m_averTriageWait = ((ct - p.operator Time()) + (m_averTriageWait * (ticketNum - 1))) / ticketNum;
    }
}

void PreTriage::removePatientFromLineup(int index){
    removeDynamicElement(m_lineup, index, m_lineupSize);
}

int PreTriage::indexOfFirstInLine(char type) const{
    int i, match = -1;
    
    for(i = 0; i < m_lineupSize && match == -1; i++){
        if(m_lineup[i]->type() == type){
            match = i;
        }
    }
    return match;
}

void PreTriage::load(){
    char ch;
    int i;
    ifstream fin;
    
    fin.open(m_dataFilename);
    cout << "Loading data...\n";
    
    if(fin){
        fin >> m_averCovidWait;
        fin.ignore(100, ',');
        fin >> m_averTriageWait;
        fin.ignore(100, '\n');
        Patient* p = nullptr;
        for(i = 0; i < maxNoOfPatients && fin; i++){
            ch = 'x';
            fin >> ch;
            fin.ignore(100, ',');
            if(ch == 'C'){
                p = new CovidPatient();
            }
            else if(ch == 'T'){
                p = new TriagePatient();
            }
            if(p != nullptr){
                p->fileIO(true);
                p->csvRead(fin);
                p->fileIO(false);
                m_lineup[i] = p;
                m_lineupSize++;
                p = nullptr;
            }
        }
    }
    
    if(fin){
        cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
        cout << m_lineupSize << " Records imported...\n\n";
    }
    else if(m_lineupSize == 0){
        cout << "No data or bad data file!\n\n";
    }
    else {
        cout << m_lineupSize << " Records imported...\n\n";
    }
}

void PreTriage::reg(){
    int selection;
    if(m_lineupSize >= maxNoOfPatients){
        cout << "Line up full!" << endl;
    } else {
        m_pMenu >> selection;
        switch(selection){
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                break;
            case 0:
                break;
        }
        m_lineup[m_lineupSize]->setArrivalTime();
        cout << "Please enter patient information: \n";
        m_lineup[m_lineupSize]->fileIO(false);
        m_lineup[m_lineupSize]->read(cin);
        cout << endl << "******************************************\n";
        m_lineup[m_lineupSize]->write(cout);
        cout << "Estimated Wait Time: "
        << getWaitTime(*m_lineup[m_lineupSize]) << endl
        << "******************************************\n\n";
        m_lineupSize++;
    }
}

void PreTriage::admit(){
    int selection, index;
    char type = 'x';
    m_pMenu >> selection;
    switch(selection){
        case 1:
            type = 'C';
            break;
        case 2:
            type = 'T';
            break;
        case 0:
            break;
    }
    index = indexOfFirstInLine(type);
    if(index != -1){
        cout << "\n******************************************\n";
        m_lineup[index]->fileIO(false);
        cout << "Calling for ";
        m_lineup[index]->write(cout);
        cout << "******************************************\n\n";
        setAverageWaitTime(*m_lineup[index]);
        removePatientFromLineup(index);
    }
}

void PreTriage::run(void){
    int selection, flag = 0;
    
    do{
        m_appMenu >> selection;
        switch(selection){
            case 0:
                flag = 1;
                break;
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
        }
    }while (flag == 0);
}

}
