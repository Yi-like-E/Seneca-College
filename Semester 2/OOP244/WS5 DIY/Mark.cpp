/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/19
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include "Mark.h"
using namespace std;
namespace sdds {

void Mark::setEmpty(){
    m_mark = -1;
}

Mark::Mark(){
    m_mark = 0;
}

Mark::Mark(int mark){
    if(mark >= 0 && mark <= 100){
        m_mark = mark;
    } else {
        setEmpty();
    }
}

Mark& Mark::operator+=(int num){
    if(m_mark >= 0 && m_mark <= 100){
        m_mark += num;
        if (m_mark > 100){
            setEmpty();
        }
    }
    return *this;
}

Mark& Mark::operator=(int& num){
    if(m_mark >= 0 && m_mark >= 100){
        m_mark = num;
    } else {
        setEmpty();
    }
    return *this;
}

Mark::operator int()const{
    int mark;
    if(m_mark == -1){
        mark = 0;
    }
    else {
        mark = m_mark;
    }
    return mark;
}

Mark::operator double()const{
    double gpa = 0.0;
    
    if(m_mark > -1 && m_mark < 50){
        gpa = 0.0;
    }
    else if(m_mark >= 50 && m_mark < 60){
        gpa = 1.0;
    }
    else if(m_mark >= 60 && m_mark <70){
        gpa = 2.0;
    }
    else if(m_mark >= 70 && m_mark < 80){
        gpa = 3.0;
    }
    else if (m_mark >= 80 && m_mark <= 100){
        gpa = 4.0;
    }
    return gpa;
}

Mark::operator char()const{
    char grade = 'X';
    
    if(m_mark >= 0 && m_mark < 50){
        grade = 'F';
    }
    else if(m_mark >= 50 && m_mark < 60){
        grade = 'D';
    }
    else if(m_mark >= 60 && m_mark <70){
        grade = 'C';
    }
    else if(m_mark >= 70 && m_mark < 80){
        grade = 'B';
    }
    else if (m_mark >= 80 && m_mark <= 100){
        grade = 'A';
    }
    return grade;
}

int operator+=(int& value, const Mark& mark){
    if(mark.operator int() > -1 && value >=0){
        value += mark.operator int();
    }
    return value;
}
}
