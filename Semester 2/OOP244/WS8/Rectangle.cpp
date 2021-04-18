// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#include <iostream>
#include <cstring>
#include <string>
#include "Rectangle.h"
using namespace std;
namespace sdds {

Rectangle::Rectangle():LblShape(){
    m_width = 0;
    m_height = 0;
}

Rectangle::Rectangle(const char* str, int width, int height):LblShape(str){
    int length = strlen(label()) +2;
    m_width = width;
    m_height = height;
    if(m_height < 3 || m_width < length){
        m_width = 0;
        m_height = 0;
    }
}

void Rectangle::getSpecs(istream& is){
    LblShape::getSpecs(is);
    is >> m_width;
    is.ignore(1000, ',');
    is >> m_height;
    is.ignore(1000, '\n');
}

void Rectangle::draw(ostream& os)const{
    int i, j, length;
    length = strlen(label());
    if(m_width > 0 && m_height > 0){
        os << "+";
        for(i = 0; i < (m_width - 2); i++){
            os << "-";
        }
        os << "+" << endl;
        os << "|" << left << label();
        for(i = 0; i < ((m_width-2)-length); i++){
            os << " ";
        }
        os << "|" << endl;
        for(i = 0; i < (m_height - 3); i ++){
            os << "|";
            for(j = 0; j < (m_width - 2); j++){
                os << " ";
            }
            os << "|" << endl;
        }
        os << "+";
        for(i = 0; i < (m_width - 2); i++){
            os << "-";
        }
        os << "+";
    }
}

}
