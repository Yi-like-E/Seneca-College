//  Autoshop module
//  Autoshop.cpp
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-07-07.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include "Autoshop.h"
using namespace std;
namespace sdds{
Autoshop& Autoshop::operator +=(Vehicle* theVehicle){
    m_vehicles.push_back(theVehicle);
    return *this;
}

void Autoshop::display(std::ostream& out)const{
    out << "--------------------------------\n"
    << "| Cars in the autoshop!        |\n"
    << "--------------------------------\n";
    std::vector<Vehicle*>::const_iterator i;
    for(i = m_vehicles.cbegin(); i != m_vehicles.cend(); i++){
        (*i)->display(out);
        out << endl;
    }
    out << "--------------------------------\n";
}

Autoshop::~Autoshop(){
    for(auto& v: m_vehicles){
        delete v;
        v = nullptr;
    }
}
}
