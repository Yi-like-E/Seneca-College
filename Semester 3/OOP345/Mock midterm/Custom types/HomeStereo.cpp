//
//  HomeStereo.cpp
//  practice
//
//  Created by YiHsun  on 2021-06-21.
//

#include <iostream>
#include <cstring>
#include "HomeStereo.h"

using namespace std;
namespace sdds{

HomeStereo::HomeStereo(const Switch* obj, size_t num){
    numArr = num;
    m_switch = new Switch[num];
    for(size_t i = 0; i < num; i++){
        m_switch[i].sType = obj[i].sType;
        m_switch[i].sState = obj[i].sState;
        strncpy(m_switch[i].name, obj[i].name, 20);
    }
}

HomeStereo::HomeStereo(const HomeStereo& src){
    *this = src;
}

HomeStereo& HomeStereo::operator=(const HomeStereo& src){
    if(this != &src){
        numArr = src.numArr;
        delete[] m_switch;
        m_switch = new Switch[numArr];
        for(size_t i = 0; i < numArr; i++){
            m_switch[i] = src.m_switch[i];
        }
    }
    return *this;
}

HomeStereo::HomeStereo(HomeStereo&& src){
    *this = std::move(src);
}

HomeStereo& HomeStereo::operator=(HomeStereo&& src){
    if(this != &src){
        delete[] m_switch;
        m_switch = src.m_switch;
        src.m_switch = nullptr;
        numArr = src.numArr;
        src.numArr = 0;
    }
    return *this;
}

HomeStereo::~HomeStereo(){
    delete[] m_switch;
    m_switch = nullptr;
}

std::ostream& HomeStereo::displayOutputState(std::ostream& os)const{
    for(size_t i = 0; i < numArr; i++){
        os << "Channel Name: " << m_switch[i].name << " - State [ ";
        if(m_switch[i].sState.stateAsBool){
            os << "on ]\n";
        } else if(m_switch[i].sState.stateAsChar == 'O'){
            os << "on ]\n";
        } else if(m_switch[i].sState.stateAsNum == 1){
            os << "on ]\n";
        } else {
            os << "off ]\n";
        }
    }
    return os;
}
}
