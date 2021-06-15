//  SetSummable module
//  SetSummable.h
//  YiHsun Lee
//  129713202
//  2021-06-06.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments


#ifndef SDDS_SETSUMMABLE_H
#define SDDS_SETSUMMABLE_H

#include <iostream>
#include <string>
#include "Set.h"

namespace sdds{

template<unsigned N, typename T>
class SetSummable: public Set<N, T>{
public:
    T accumulate(const std::string& filter)const{
        T obj(filter);
        for(size_t i = 0; i < this->size(); i++){
            if(obj.isCompatibleWith(this->get(i))){
                obj += this->get(i);
            }
        }
        return obj;
    }
};

}

#endif
