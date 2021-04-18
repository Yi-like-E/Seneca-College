#ifndef SDDS_SEARCHNLIST_H_
#define SDDS_SEARCHNLIST_H_
#include "Collection.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds {

template<typename T1, typename T2>
bool search(Collection<T1>& obj, T1* arr, int num, T2 arg){
    int i;
    bool flag = false;
    for(i = 0; i < num; i++){
        if(arr[i] == arg){
            flag = true;
            obj.add(arr[i]);
        }
    }
    return flag;
}

template<typename T>
void listArrayElements(const char* title, const T* arr, int num){
    int i, j = 1;
    cout << title << endl;
    for(i = 0; i < num; i++){
        cout << j << ": " << arr[i] << endl;
        j++;
    }
}
}
#endif
