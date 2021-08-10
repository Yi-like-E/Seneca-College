//
//  Box.cpp
//  final practice
//
//  Created by YiHsun  on 2021-08-09.
//

#include <thread>
#include <algorithm>
#include "Box.h"
using namespace std;

Box& Box::operator+=(const Gem& obj){
    m_box.push_back(obj);
    return *this;
}

Box& Box::operator-=(std::string name){
    vector<Gem>::iterator it;
    it = find_if(m_box.begin(), m_box.end(), [name](Gem& stone){
        return stone.name == name;
    });
    if(it != m_box.end()){
        cout << it->name << " removed!\n";
        m_box.erase(it);
    } else{
        throw string("Invalid name!");
    }
    return *this;
}

void Box::process(){
    auto num = count_if(m_box.begin(), m_box.end(), [](const Gem& g){
        return !g.polished;
    });
    thread t[num];
    for(int i = 0; i < num; i++){
        t[i] = thread([&](){
            for_each(m_box.begin(), m_box.end(), [](Gem& g){
                if(!g.polished){
                    g.polished = true;
                    g.shine += 20;
                }
            });
        });
        t[i].join();
    }
}

void Box::display(){
    for_each(m_box.begin(), m_box.end(), [](Gem& g){
        cout << g.name << " | " << g.colour << " | "
        << g.shine << " | ";
        if(g.polished){
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    });
}
