#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <thread>
#include <vector>
#include "Box.h"
using namespace std;

int main() {
    
    Box b;
    
    cout << "\nAdding Gems" << endl;
    b += Gem{"Emerald", "Green", 20, false};
    b += Gem{"Ruby", "Red", 50, true};
    b += Gem{"Sapphire", "Blue", 80, false};
    b += Gem{"Onyx", "Black", 60, false};
    b += Gem{"Opal", "White", 10, false};
    b.display();
    
    cout << "\nRemoving Gems" << endl;
    try {
        b -= "Ruby";
        b -= "Emerald";
        b -= "Diamond";
        b.display();
    }
    catch (string c) {
        cout << c << endl;
    }
    
    cout << "\nPolishing Gems" << endl;
    b.process();
    b.display();
    
    
    cout << "\nVector of Boxes" << endl;
    vector<Box*> boxes;
    boxes.push_back(new Box());
    boxes.push_back(new Box());
    boxes.push_back(new Box());
    
    for (auto x : boxes) {
        x->operator+=(Gem{ "Emerald", "Green", 20, false });
        x->operator+=(Gem{ "Ruby", "Red", 90, false });
        x->operator+=(Gem{ "Sapphire", "Blue", 40, false });
    }
    
    for_each(boxes.begin(), boxes.end(), [](Box* b){
        b->display();
    });
    
    for (auto x : boxes) {
        delete x;
    }
}

