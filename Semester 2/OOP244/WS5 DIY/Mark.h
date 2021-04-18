/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/19
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef Mark_h
#define Mark_h

#include <stdio.h>
using namespace std;
namespace sdds{
class Mark{
    int m_mark;
    void setEmpty();
    
public:
    Mark();
    Mark(int mark);
    Mark& operator+=(int num);
    Mark& operator=(int& num);
    operator int()const;
    operator double()const;
    operator char()const;
};
int operator+=(int& value, const Mark& mark);
}
#endif /* Mark_h */
