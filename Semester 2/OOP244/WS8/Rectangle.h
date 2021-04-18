// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds {
class Rectangle: public LblShape{
    int m_width;
    int m_height;
public:
    Rectangle();
    Rectangle(const char* str, int width, int height);
    void getSpecs(istream& is);
    void draw(ostream& os)const;
};
}

#endif /* Rectangle_h */
