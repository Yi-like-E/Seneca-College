// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII


#ifndef Shape_h
#define Shape_h

#include <iostream>
using namespace std;
namespace sdds {
class Shape{
public:
    virtual void draw(ostream& os)const = 0;
    virtual void getSpecs(istream& is) = 0;
    virtual ~Shape();
};
ostream& operator<<(ostream& os, Shape& shape);
istream& operator>>(istream& is, Shape& shape);
}

#endif /* Shape_h */
