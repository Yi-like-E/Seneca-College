/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/14
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include "cstring.h"   // using strLen, strCpy and strCmp
namespace sdds {

void strCpy(char* des, const char* src){
    int i;
    
    for (i = 0; src[i] != '\0'; i++){
        des[i] = src[i];
    }
    des[i] = '\0';
}

int strCmp(const char* s1, const char* s2){
    int i, result;
    
    for(i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++); // calculate at which index s1 and s2 are different.
    
    if(s1[i] < s2[i]){
        result = -1;
    }
    else if(s1[i] > s2[i]){
        result = 1;
    }
    else{
        result = 0;
    }
    return result;
}

int strLen(const char* s){
    int len = 0, i;
    
    for(i = 0; s[i] != '\0'; i++){
        len = i+1;
    }
    return len;
}

}
