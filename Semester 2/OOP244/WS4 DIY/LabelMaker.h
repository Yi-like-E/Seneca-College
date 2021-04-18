/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/14
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef LabelMaker_h
#define LabelMaker_h

#include <iostream>
#include "Label.h"
namespace sdds{
class LabelMaker{
    // The LabelMaker class creates a dynamic array of Labels and
    // gets their content from the user one by one and prints them all at once.
    Label* c_labels;
    int c_noOfLabels;
    void setEmpty();
    
public:
    LabelMaker(int noOfLabels);
    void readLabels();
    void printLabels();
    ~LabelMaker();
};
}

#endif /* LabelMaker_h */
