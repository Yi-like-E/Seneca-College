//  Set module
//  Set.h
//  YiHsun Lee
//  129713202
//  2021-06-06.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_SET_H
#define SDDS_SET_H

#include <iostream>
namespace sdds{

template<unsigned N, typename T>
class Set{
    T collection[N];
    size_t numOfElement;
public:
    Set():collection{}, numOfElement{}{};
    size_t size()const{
        return numOfElement;
    };
    const T& get(size_t idx)const{
        return collection[idx];
    };
    void operator+=(const T& item){
        if(numOfElement < N){
            collection[numOfElement] = item;
            numOfElement++;
        }
    };
};

}

#endif
