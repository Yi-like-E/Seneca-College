//
//  HomeStereo.hpp
//  practice
//
//  Created by YiHsun  on 2021-06-21.
//

#ifndef SDDS_HomeStereo_h
#define SDDS_HomeStereo_h

#include <iostream>

namespace sdds{
enum class StateType
{
    boolean,
    character,
    number
};

typedef struct
{
    char name[20];
    StateType sType;
    union
    {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch;

class HomeStereo{
    Switch* m_switch{};
    size_t numArr{0};
public:
    HomeStereo(){};
    HomeStereo(const Switch*, size_t);
    // copy constructor
    HomeStereo(const HomeStereo&);
    // copy assignment operator
    HomeStereo& operator=(const HomeStereo&);
    // move constructor
    HomeStereo(HomeStereo&&);
    // move assignment operator
    HomeStereo& operator=(HomeStereo&&);
    ~HomeStereo();
    std::ostream& displayOutputState(std::ostream&)const;
};
}

#endif /* SDDS_HomeStereo_h */
