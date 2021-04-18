// Name: YiHsun Lee
// Student No.: 129713202
// Email: ylee212@myseneca.ca
// Section: NII

#include <iostream>
#include <cstring>
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds{

LblShape::LblShape(){
    m_label = nullptr;
}

const char* LblShape::label()const{
    return m_label;
}

LblShape::LblShape(const char* str){
    m_label = nullptr;
    m_label = new char[strlen(str)+1];
    strcpy(m_label, str);
}

LblShape::~LblShape(){
    delete[] m_label;
    m_label = nullptr;
}

void LblShape::getSpecs(istream& is){
    string label;
    getline(is, label, ',');
    delete[] m_label;
    m_label = nullptr;
    m_label = new char[strlen(label.c_str())+1];
    strcpy(m_label, label.c_str());
}

}
