/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/14
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"
#include "Label.h"

using namespace std;
namespace sdds {

void Label::setToDefault(){
    c_frame[0] = '\0' ;
    c_label = nullptr;
}

// Set label with argument
void Label::setLabel(const char* cstr){
    if(cstr != nullptr){
        delete[] c_label;
        c_label = new char[strLen(cstr) + 1];
        strCpy(c_label, cstr);
        if(strLen(cstr) > 70){
            c_label[70] = '\0';
        }
    }
    
}

// set frame with argument
void Label::setFrame(const char* cstr){
    if(cstr != nullptr && strLen(cstr) == 8){
        strCpy(c_frame, cstr);
    }
}

// Empty label with a default frame
Label::Label(){
    setToDefault();
    setFrame("+-+|+-+|");
}

// Empty label with assigned frame
Label::Label(const char* frameArg){
    setToDefault();
    setFrame(frameArg);
}

// Assigned label and frame
Label::Label(const char* frameArg, const char* content){
    setToDefault();
    setLabel(content);
    setFrame(frameArg);
}

Label::~Label(){
    delete[] c_label;
    c_label = nullptr;
}

void Label::flushKeys(){
    while(getchar() != '\n');
}

void Label::readLabel(){
    char label[71] = {'\0'};
    cin.get(label, 71, '\n');
    setLabel(label);
    flushKeys();
}

std::ostream& Label::printLabel()const{
    int length;
    if(c_label != nullptr && c_frame[0] != '\0'){
        length = strLen(c_label);
        cout << c_frame[0] << setw(length+3) << setfill(c_frame[1]) << c_frame[2] << endl;
        cout << c_frame[7] << setw(length+3) << setfill(' ') << c_frame[3] << endl;
        cout << c_frame[7] << " " << c_label << " " << c_frame[3] << endl;
        cout << c_frame[7] << setw(length+3) << setfill(' ') << c_frame[3] << endl;
        cout << c_frame[6] << setw(length+3) << setfill(c_frame[5]) << c_frame[4];
    }
    return cout;
}

}
