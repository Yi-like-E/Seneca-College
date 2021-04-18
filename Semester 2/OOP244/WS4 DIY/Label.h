/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/14
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef Label_h
#define Label_h
#include <iostream>
using namespace std;

namespace sdds{
class Label{
    // The label class creates a label by drawing a frame around a one-line text
    // with an unknown size (maximum of 70 chars, must be kept dynamically).
    char c_frame[9];
    char* c_label;
public:
    void setToDefault();
    void setLabel(const char* cstr);
    void setFrame(const char* cstr);
    void flushKeys();
    // Constructors
    Label();
    Label(const char* frameArg);
    Label(const char* frameArg, const char* content);
    // Destructor
    ~Label();
    void readLabel();
    std::ostream& printLabel()const;
};
}

#endif /* Label_h */
