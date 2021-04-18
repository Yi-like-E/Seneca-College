/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2020/01/20
 */

#ifndef cstring_h
#define cstring_h

#include <stdio.h>

namespace sdds{
    void strCpy(char* des, const char* src);
    void strnCpy(char* des, const char* src, int len);
    int strCmp(const char* s1, const char* s2);
    int strnCmp(const char* s1, const char* s2, int len);
    int strLen(const char* s);
    const char* strStr(const char* str1, const char* str2);
    void strCat(char* des, const char* src);
}

#endif /* cstring_h */
