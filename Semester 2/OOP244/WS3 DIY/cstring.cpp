/*
 Name:      YiHsun Lee
 Email:     ylee212@myseneca.ca
 Section:   NII
 Date:      2021/02/04
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include "cstring.h"
namespace sdds {
void strnCpy(char* des, const char* src, int len){
    int i, count = 0, j;
    
    for(i = 0; src[i] != '\0'; i++){
        count = i+1;
    }
    
    if(count >= len){
        for(j = 0; j< len; j++){
            des[j] = src[j];
        }
    } else{
        for(j = 0; src[j] != '\0'; j++){
            des[j] = src[j];
        }
    }
    des[j] = '\0';
}

}
