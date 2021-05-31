//  event module
//  event.cpp
//  YiHsun Lee
//  ylee212@myseneca.ca
//  129713202
//  2021/05/27
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "event.h"
using namespace std;

size_t g_sysClock = 0;

namespace sdds{
Event::Event(){};

void Event::display(){
    static int counter = 1;
    
    cout.width(2);
    cout.fill(' ');
    cout << counter++ << ". ";
    if(desc != nullptr){
        cout.width(2);
        cout.fill('0');
        cout << time/3600 << ":";
        cout.width(2);
        cout << (time % 3600) / 60 << ":";
        cout.width(2);
        cout << (time % 3600) % 60;
        cout << " => " << desc << endl;
    }
    else {
        cout << "| No Event |\n";
    }
}

void Event::set(const char* srcDesc){
    if(srcDesc != nullptr && srcDesc[0] != '\0'){
        if(desc != nullptr){
            delete[] desc;
            desc = nullptr;
        }
        desc = new char[strlen(srcDesc) +1];
        strcpy(desc, srcDesc);
        time = g_sysClock;
    }
    else {
        delete [] desc;
        desc = nullptr;
        time = 0;
    }
}

Event::Event(const Event& src){
    *this = src;
}

Event& Event::operator=(const Event& src){
    if(this != &src){
        if(src.desc != nullptr){
            delete[] desc;
            desc = new char[strlen(src.desc)+1];
            strcpy(desc, src.desc);
            time = src.time;
        }
        else {
            desc = nullptr;
            time = 0;
        }
    }
    return *this;
}

Event::~Event(){
    delete[] desc;
    desc = nullptr;
}

}
