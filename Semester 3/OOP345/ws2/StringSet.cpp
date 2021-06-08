//  StringSet module
//  StringSet.h
//  YiHsun Lee
//  129713202
//  2021-06-03.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <iostream>
#include <fstream>
#include "StringSet.h"

namespace sdds{
StringSet::StringSet(){
    string = nullptr;
    numOfStr = 0;
};

StringSet::StringSet(const std::string& filename){
    static int count = 0;
    std::string str;
    std::ifstream file;
    
    string = nullptr;
    numOfStr = 0;
    
    file.open(filename);
    while(!file.eof()){
        std::getline(file, str, ' ');
        count++;
    }
    numOfStr = count;
    file.close();
    
    string = new std::string[numOfStr];
    static int i = 0;
    file.open(filename);
    while(!file.eof()){
        std::getline(file, str, ' ');
        string[i] = str;
        i++;
    }
    file.close();
    
}

StringSet::StringSet(const StringSet& src):StringSet(){
    *this = src;
}

StringSet& StringSet::operator=(const StringSet& src){
    if(this != &src){
        numOfStr = src.numOfStr;
        delete[] string;
        string = new std::string[numOfStr];
        for(size_t i = 0; i < src.numOfStr; i++){
            string[i] = src.string[i];
        }
    }
    return *this;
}

StringSet::StringSet(StringSet&& src):StringSet(){
    *this = std::move(src);
}

StringSet& StringSet::operator=(StringSet&& src){
    if(this != &src){
        delete[] string;
        string = src.string;
        src.string = nullptr;
        numOfStr = src.numOfStr;
        src.numOfStr = 0;
    }
    return *this;
}

size_t StringSet::size(){
    return numOfStr;
}

std::string StringSet::operator[](size_t index)const{
    std::string readStr ="";
    if(index < numOfStr && index >= 0){
        readStr = string[index];
    }
    return readStr;
}

StringSet::~StringSet(){
    delete[] string;
    string = nullptr;
}
}
