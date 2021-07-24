//  Autoshop module
//  Autoshop.h
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-07-07.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Autoshop_h
#define SDDS_Autoshop_h

#include <iostream>
#include <list>
#include <vector>
#include "Vehicle.h"

namespace sdds{
class Autoshop{
    std::vector<Vehicle*>m_vehicles;
public:
    Autoshop& operator +=(Vehicle* theVehicle);
    void display(std::ostream& out)const;
    ~Autoshop();
    template<typename T>
    void select(T test, std::list<const Vehicle*>& vehicles){
        std::vector<Vehicle*>::iterator i;
        for(i = m_vehicles.begin(); i < m_vehicles.end(); i++){
            if(test(*i)){
                vehicles.push_back(*i);
            }
        }
    }
};
}

#endif /* SDDS_Autoshop_h */
