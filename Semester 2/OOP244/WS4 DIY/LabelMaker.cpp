/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/14
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include "LabelMaker.h"

namespace sdds {

void LabelMaker::setEmpty(){
    c_labels = nullptr;
}

LabelMaker::LabelMaker(int noOfLabels){
    if(noOfLabels > 0){
        c_noOfLabels = noOfLabels;
        c_labels = new Label[c_noOfLabels];
    }
}


void LabelMaker::readLabels(){
    int i;
    cout << "Enter " << c_noOfLabels << " labels:" << endl;
    for(i = 0; i < c_noOfLabels; i++){
        cout << "Enter label number " << i+1 << endl;
        cout << "> ";
        c_labels[i].readLabel();
    }
}

void LabelMaker::printLabels(){
    int i;
    for(i = 0; i < c_noOfLabels; i++){
        c_labels[i].printLabel();
        cout << endl;
    }
}

LabelMaker::~LabelMaker(){
    delete[] c_labels;
    c_labels = nullptr;
}
}
