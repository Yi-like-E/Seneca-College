// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#ifndef LblShape_h
#define LblShape_h

#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {
class LblShape: public Shape {
    char* m_label = nullptr;
protected:
    const char* label()const;
public:
    LblShape();
    LblShape(const char* str);
    ~LblShape();
    void getSpecs(istream& is);
    LblShape (const LblShape&) = delete;
    LblShape& operator=(const LblShape&) = delete;
};
}

#endif /* LblShape_h */
