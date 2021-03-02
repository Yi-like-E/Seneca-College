#include "cstring.h"
namespace sdds {
void strCpy(char* des, const char* src){
    int i = 0;
    
    for (i = 0; src[i] != '\0'; i++){
        des[i] = src[i];
    }
    des[i] = '\0';
}
int strLen(const char* s){
    int len = 0, i;
    
    for(i = 0; s[i] != '\0'; i++){
        len = i+1;
    }
    return len;
}
void strCat(char* des, const char* src){
    int length, i = 0;
    
    length = strLen(des);
    
    while(src[i] != '\0'){
        des[length] = src[i];
        length++;
        i++;
    }
    des[length] = '\0';
}
}
