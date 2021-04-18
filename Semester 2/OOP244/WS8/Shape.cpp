// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds{

Shape::~Shape(){};

ostream& operator<<(ostream& os, Shape& shape){
    shape.draw(os);
    return os;
};

istream& operator>>(istream& is, Shape& shape){
    shape.getSpecs(is);
    return is;
};

}
