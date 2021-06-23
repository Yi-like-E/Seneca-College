//
//  insertAtEnd.hpp
//  practice_functions
//
//  Created by YiHsun  on 2021-06-21.
//

#ifndef SDDS_insertAtEnd_h
#define SDDS_insertAtEnd_h

#include <iostream>
namespace sdds{

template<typename T, typename V>
T* insertAtEnd(T* arr, size_t size, V val){
    T* newArr = new T[size+1];
    for(size_t i = 0; i < size; i++){
        newArr[i] = arr[i];
    }
    newArr[size] = val;
    delete[] arr;
    arr = newArr;
    for(size_t i = 0; i < size+1; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    return arr;
}

template <>
char* insertAtEnd(char* arr, size_t size, char val){
    char* temp = new char[size+2];
    for(size_t i = 0; i < size; i++){
        temp[i] = arr[i];
    }
    temp[size] = val;
    temp[size+1] = '\0';
    delete[] arr;
    arr = temp;
    return arr;
}

}



#endif /* SDDS_insertAtEnd_h */
