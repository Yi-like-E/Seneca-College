// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#ifndef Line_h
#define Line_h

#include <iostream>
#include "LblShape.h"
using namespace std;
namespace sdds{
class Line: public LblShape{
    int m_length;
public:
    Line();
    Line(const char* str, int length);
    void getSpecs(istream& is);
    void draw(ostream& os)const;
};
}

#endif /* Line_h */
