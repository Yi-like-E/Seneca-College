/*
 Section:    NII
 Date:       2021/01/20
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include "cstring.h"
using namespace std;

namespace sdds {

    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src) {
        int i = 0;

        for (i = 0; src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len) {
        int i = 0;

        if (strLen(src) >= len) {
            for (i = 0; i < len; i++) {
                des[i] = src[i];
            }
        }
        else {
            for (i = 0; src[i] != '\0'; i++) {
                des[i] = src[i];
            }
            des[i] = '\0';
        }
    }

    // Compares two C-strings
    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
        int i, result;

        for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++); // calculate at which index s1 and s2 are different.

        if (s1[i] < s2[i]) {
            result = -1;
        }
        else if (s1[i] > s2[i]) {
            result = 1;
        }
        else {
            result = 0;
        }
        return result;
    }

    // returns 0 i thare the same
    // return > 0 if s1 > s2
    // return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {

        int i, result;

        for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && i < len - 1; i++);

        if (s1[i] < s2[i]) {
            result = -1;
        }
        else if (s1[i] > s2[i]) {
            result = 1;
        }
        else {
            result = 0;
        }
        return result;

    }

    // returns the lenght of the C-string in characters
    int strLen(const char* s) {
        int len = 0, i;

        for (i = 0; s[i] != '\0'; i++) {
            len = i + 1;
        }
        return len;
    }

    // returns the address of first occurance of "str2" in "str1"
    // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2) {

        do {
            const char* start = str1;
            const char* occ = str2;

            do {
                str1++;
                occ++;
            } while (*str1 != '\0' && *occ != '\0' && *str1 == *occ);

            if (*occ == '\0') {

                return start;  // return the starting address when it's a complete match
            }

            str1 = start + 1;

        } while (*str1 != '\0');

        return nullptr;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {

        int length, i = 0;

        length = strLen(des);

        while (src[i] != '\0') {
            des[length] = src[i];
            length++;
            i++;
        }
        des[length] = '\0';
    }

}
