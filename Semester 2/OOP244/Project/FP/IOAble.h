/* Citation and Sources...
 Final Project Milestone 2
 Module: IOAble
 Filename: IOAble.h
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

#ifndef IOAble_hpp
#define IOAble_hpp

#include <iostream>
#include <fstream>
using namespace std;
namespace sdds {

class IOAble{
public:
    virtual ostream& csvWrite(ostream& os)const = 0;
    virtual istream& csvRead(istream& is) = 0;
    virtual ostream& write(ostream& os)const = 0;
    virtual istream& read(istream& is) = 0;
    virtual ~IOAble() = 0;
};
std::ostream& operator<<(std::ostream& ostr, const IOAble& io);
std::istream& operator>>(std::istream& istr, IOAble& io);
}

#endif /* IOAble_hpp */
