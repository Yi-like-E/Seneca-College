// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#include <iostream>
#include <cstring>
#include <string>
#include "Line.h"
using namespace std;
namespace sdds{

Line::Line():LblShape(){
    m_length = 0;
}

Line::Line(const char* str, int length):LblShape(str){
    m_length = length;
}

void Line::getSpecs(istream& is){
    LblShape::getSpecs(is);
    is >> m_length;
    is.ignore(1000, '\n');
}

void Line::draw(ostream& os)const{
    int i;
    if(m_length > 0 && label() != nullptr){
        os << label() << endl;
        for(i = 0; i < m_length; i++){
            os << "=";
        }
    }
}

}
