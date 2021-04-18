#include <fstream>
#include <iostream>
#include <cstring>
#include "Text.h"
using namespace std;
namespace sdds {
int Text::getFileLength() const {
    int len = 0;
    ifstream fin(m_filename);
    while (fin) {
        fin.get();
        len += !!fin;
    }
    return len;
}

Text::Text(const char* filename){
    if(filename != nullptr){
        m_filename = new char[strlen(filename)+1];
        strcpy(m_filename, filename);
        m_content = nullptr;
    } else {
        m_filename = nullptr;
        m_content = nullptr;
    }
}

const char& Text::operator[](int index)const{
    if(index < getFileLength()){
         return m_content[index];
    }
    else {
        //throw "ERROR";       // undefined behaviour?
        return m_content[index] = '\0';
    }
}

Text::Text(const Text &t){
    if(t.m_filename != nullptr && t.m_content != nullptr){
        m_filename = new char[strlen(t.m_filename)+1];
        strcpy(m_filename, t.m_filename);
        m_content = new char[t.getFileLength()+1];
        t.m_content[t.getFileLength()] = '\0';
        strcpy(m_content, t.m_content);
    }
}
    
Text& Text::operator=(const Text& source){
    if(this != &source){
        if(source.m_filename != nullptr && source.getFileLength() != 0){
            if(m_filename != nullptr){
                delete[] m_filename;
                m_filename = nullptr;
            }
            m_filename = new char[strlen(source.m_filename)+1];
            strcpy(m_filename, source.m_filename);
            read();
        }
    }
    return *this;
}

void Text::read(){
    char ch;
    ifstream fin;
    fin.open(m_filename);
    delete[] m_content;
    m_content = nullptr;
    if(fin){
        m_content = new char[getFileLength()+1];
        for(int i = 0; i < getFileLength(); i++){
            ch = fin.get();
            m_content[i] = ch;
        }
    }
}

void Text::write(std::ostream& os)const{
    if(m_content != nullptr){
        for(int i = 0; i < getFileLength(); i++){
            os << m_content[i];
        }
    }
}

Text::~Text(){
    delete[] m_content;
    m_content = nullptr;
    delete[] m_filename;
    m_filename = nullptr;
}

ostream& operator<<(ostream& os, const Text& t){
    t.write(os);
    return os;
}

}
