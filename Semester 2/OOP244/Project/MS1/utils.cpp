/* Citation and Sources...
 Final Project Milestone 1
 Module: Utils
 Filename: Utils.cpp
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2020/?/?  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 -----------------------------------------------------------
 OR
 -----------------------------------------------------------
 Write exactly which part of the code is given to you as help and
 who gave it to you, or from what source you acquired it.
 -----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
bool debug = false;  // made global in utils.h
int getTime() {
    int mins = -1;
    if (debug) {
        Time t(0);
        cout << "Enter current time: ";
        do {
        cin.clear();
        cin >> t;   // needs extraction operator overloaded for Time
        if (!cin) {
            cout << "Invlid time, try agian (HH:MM): ";
            cin.clear();
        }
        else {
            mins = int(t);
        }
        cin.ignore(1000, '\n');
        } while (mins < 0);
    }
    else {
        time_t t = time(NULL);
        tm lt = *localtime(&t);
        mins = lt.tm_hour * 60 + lt.tm_min;
    }
    return mins;
}

int getInt(const char* prompt){
    int value;
    bool entry = prompt != nullptr;
    char ch;
    
    if(prompt != nullptr){
        cout << prompt;
    }
    do {
        entry = false;
        cin >> value;
        if (cin.fail()) {
            cout << "Bad integer value, try again: ";
            cin.clear();
            cin.ignore(3000, '\n');
            entry = true;
        }
        else {
            ch = cin.get();
            if (ch != '\n') {
                cout << "Enter only an integer, try again: ";
                cin.ignore(3000, '\n');
                entry = true;
            }
        }
    } while (entry);

    return value;
}

int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError){
    int value;
    
    
    if (showRangeAtError){
        value = getInt(prompt);
        while(value < min || value > max){
            cout << errorMessage << "["<< min << " <= value <= " << max<< "]: ";
            value = getInt();
        }
    } else {
        value = getInt(prompt);
        while(value < min || value > max){
            cout << errorMessage ;
            value = getInt();
        }
    }
    return value;
}

char* getcstr(const char* prompt, std::istream& istr, char delimiter){
    string input;
    char* str = nullptr;
    if(prompt != nullptr){
        cout << prompt;
        std::getline(istr, input);
        str = new char[input.length()+2];
        //std::copy(input.begin(), input.end(), str);
        strcpy(str, input.c_str());
        str[input.length()] = '\0';
        str[input.length()+1] = delimiter;
    }
    return str;
}

}
