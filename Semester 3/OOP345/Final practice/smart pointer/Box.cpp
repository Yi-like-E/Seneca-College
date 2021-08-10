//
//  Box.cpp
//  mock_final_Q2_smartPtr
//
//  Created by YiHsun  on 2021-08-10.
//

#include <algorithm>
#include <thread>
#include "Box.h"
using namespace std;

Box& Box::operator+=(const Gem obj){
    shared_ptr<Gem> temp{new Gem(obj)};
    m_box.push_back(temp);
    return *this;
}

Box& Box::operator-=(std::string name){
    auto found = find_if(m_box.begin(), m_box.end(), [name](shared_ptr<Gem> stone){
        return stone->name == name;
    });
    if(found != m_box.end()){
        cout << found->get()->name << " removed!\n";
        m_box.erase(found);
    } else{
        throw string("Invalid name!");
    }
    return *this;
}

void Box::process(){
    auto num = count_if(m_box.begin(), m_box.end(), [](shared_ptr<Gem> g){
        return !g->polished;
    });
    thread t[num];
    for(int i = 0; i < num; i++){
        t[i] = thread([&](){
            for_each(m_box.begin(), m_box.end(), [](shared_ptr<Gem> g){
                if(!g->polished){
                    g->polished = true;
                    g->shine += 20;
                }
            });
        });
        t[i].join();
    }
}

void Box::display(){
    for_each(m_box.begin(), m_box.end(), [](shared_ptr<Gem> g){
        cout << g->name << " | " << g->colour << " | "
        << g->shine << " | ";
        if(g->polished){
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    });
}
