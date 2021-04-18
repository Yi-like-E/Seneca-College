// Workshop 1:
// Version: 0.9
// Date: 2021/10/16
// Author: Fardad Soleimanloo
// Description:
// This file tests the lab section of your workshop
///////////////////////////////////////////////////


#include <iostream>
#include "cstring.h"
using namespace sdds;
using namespace std;

int main() {
    char str1[80] = "abcdefghijklmnopqrstuvwxyz";
    char str2[80];
    const char* fadd;
    strCpy(str2, str1);
    cout << str2 << endl;
    strnCpy(str2, "@@@", 2);
    cout << str2 << endl;
    strnCpy(str2, "@@@", 3);
    cout << str2 << endl;
    strnCpy(str2, "@@@", 4);
    cout << str2 << endl;
    cout << strCmp("aab", "aaa") << endl;
    cout << strnCmp("aab", "aaa", 2) << endl;
    cout << strnCmp("aab", "aaa", 3) << endl;
    cout << strLen("") << endl;
    cout << strLen(str1) << endl;
    fadd = strStr(str1, "jkl");
    cout << fadd << endl;
    fadd = strStr(str1, "bbb");
    if (!fadd) cout << "Not found" << endl;
    strCpy(str2, "John ");
    strCat(str2, "Doe");
    cout << str2 << endl;
    return 0;
}


/*
 abcdefghijklmnopqrstuvwxyz
 @@cdefghijklmnopqrstuvwxyz
 @@@defghijklmnopqrstuvwxyz
 @@@
 1
 0
 1
 0
 26
 jklmnopqrstuvwxyz
 Not found
 John Doe
 */
