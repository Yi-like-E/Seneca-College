//
//  main.cpp
//  practice
//
//  Created by YiHsun  on 2021-06-21.
//

#include <iostream>
#include "HomeStereo.h"
#include "Switch.h"

int main(int argc, const char * argv[]) {
    size_t val = 2;
    sdds::Switch s[val];
    strcpy(s[0].name, "CNN");
    s[0].sType = sdds::StateType::boolean;
    s[0].sState.stateAsBool = true;
    strcpy(s[1].name, "CTV news");
    s[1].sType = sdds::StateType::number;
    s[0].sState.stateAsNum = 3;
    sdds::HomeStereo stereo(s, val);
    stereo.displayOutputState(std::cout);
    return 0;
}
