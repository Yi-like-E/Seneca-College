//
//  Box.hpp
//  mock_final_Q2_smartPtr
//
//  Created by YiHsun  on 2021-08-10.
//

#ifndef Box_h
#define Box_h

#include <iostream>
#include <vector>
#include <memory>
#include <string>

struct Gem {
    std::string name;
    std::string colour;
    int shine;
    bool polished;
};

class Box{
    std::vector<std::shared_ptr<Gem>> m_box;
public:
    Box& operator+=(const Gem);
    Box& operator-=(std::string name);
    void process();
    void display();
};

#endif /* Box_h */
