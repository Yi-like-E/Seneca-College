/* Citation and Sources...
 Final Project Milestone 2
 Module: IOAble
 Filename: IOAble.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2021/3/17  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */

#include <iostream>
#include <fstream>
#include "IOAble.h"
using namespace std;
namespace sdds {
ostream& IOAble::csvWrite(ostream& os)const{
    return os;
}

istream& IOAble::csvRead(istream& is){
    return is;
}

ostream& IOAble::write(ostream& os)const{
    return os;
}

istream& IOAble::read(istream& is){
    return is;
}

IOAble::~IOAble(){};

std::ostream& operator<<(std::ostream& ostr, const IOAble& io){
    return io.write(ostr);
}

std::istream& operator>>(std::istream& istr, IOAble& io){
    return io.read(istr);
}
}
