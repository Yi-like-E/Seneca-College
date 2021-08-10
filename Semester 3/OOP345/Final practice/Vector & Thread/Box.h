//
//  Box.hpp
//  final practice
//
//  Created by YiHsun  on 2021-08-09.
//

#ifndef Box_h
#define Box_h

#include <vector>
#include <string>
#include <iostream>

struct Gem {
    std::string name;
    std::string colour;
    int shine;
    bool polished;
};

class Box{
    std::vector<Gem> m_box;
public:
    Box& operator+=(const Gem&);
    Box& operator-=(std::string name);
    void process();
    void display();
};

#endif /* Box_h */
