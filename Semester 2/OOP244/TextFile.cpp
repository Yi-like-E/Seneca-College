#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
Line::operator const char* () const {
    return (const char*)m_value;
}
Line& Line::operator=(const char* lineValue) {
    delete[] m_value;
    m_value = new char[strLen(lineValue) + 1];
    strCpy(m_value, lineValue);
    return *this;
}

Line::Line(){
    m_value = nullptr;
}

Line::~Line() {
    delete[] m_value;
}

//Line& Line::operator=(const Line& rightOper){
//    if(this != &rightOper){
//        m_value = rightOper.m_value;
//    }
//    return *this;
//}
//
//Line::Line(const Line& copy){
//    *this = copy;
//}

void TextFile::setEmpty(){
    delete[] m_textLines;
    m_textLines = nullptr;
    delete[] m_filename;
    m_filename = nullptr;
    m_noOfLines = 0;
}

void TextFile::setFilename(const char* fname, bool isCopy){
    char name[] = "C_";
    if(!isCopy){
        delete[] m_filename;
        m_filename = new char[strLen(fname)+1];
        strCpy(m_filename, fname);

    } else {
        delete[] m_filename;
        strCat(name, fname);
        //strcat(name, fname);
        m_filename = new char[strLen(name)+1];
        strCpy(m_filename, name);
    }
}

void TextFile::setNoOfLines(){
    char ch;
    int count = 0;
    std::ifstream f(m_filename);
    while(f){
        ch = f.get();
        if(ch == '\n'){
            count++;
        }
    }
    m_noOfLines = count;
    if(m_noOfLines == 0){
        delete[] m_filename;
        m_filename = nullptr;
    } else {
        m_noOfLines+=1;
    }
}

void TextFile::loadText(){
    int i = 0;
    std::string line;
    if(m_filename != nullptr){
        delete[] m_textLines;
        m_textLines = new Line[m_noOfLines];
        std::ifstream f(m_filename);
        while(std::getline(f, line)){
            m_textLines[i] = line.c_str();
            i++;
        }
        m_noOfLines = i;
    }

}

void TextFile::saveAs(const char *fileName)const{
    int i;
    std::ofstream f(m_filename);
    if(f.is_open()){
        for(i = 0; i < m_noOfLines; i++){
            f << m_textLines[i].m_value << endl;
        }
    }
}

TextFile::TextFile(unsigned pageSize){
    m_pageSize = pageSize;
    setEmpty();
}

TextFile::TextFile(const char* filename, unsigned pageSize){
    m_pageSize = pageSize;
    setEmpty();
    if(filename != nullptr){
        setFilename(filename);
        setNoOfLines();
        loadText();
    }
}

TextFile::TextFile(const TextFile& source){
    m_pageSize = source.m_pageSize;
    setEmpty();
    if(source){
        setFilename(source.m_filename, true);
        saveAs(source.m_filename);
        setNoOfLines();
        loadText();
    }
}

TextFile& TextFile::operator=(const TextFile& source){
    if(this != &source){
        if(source && *this){
            delete[] m_textLines;
            m_textLines = nullptr;
            saveAs(source.m_filename);
            setNoOfLines();
            loadText();
        }
    }
    return *this;
}
TextFile::~TextFile(){
    delete[] m_textLines;
    delete[] m_filename;
}

unsigned TextFile::lines()const{
    return m_noOfLines;
}

std::ostream& TextFile::view(std::ostream& ostr)const{
    int i, j;
    char input;
    if(*this){
        ostr << m_filename << endl;
        ostr.width(10);
        ostr.fill('=');
        ostr << "=" << endl;
        for(i = 0; i < m_pageSize; i++){
            ostr << m_textLines[i] << endl;
        }
        ostr << "Hit ENTER to continue...";
        cin >> input;
        if(input == '\n'){
            for(j = m_pageSize; j < (m_noOfLines - m_pageSize); j++){
                ostr << m_textLines[j] << endl;
            }
        }
    }
    return ostr;
}

std::istream& TextFile::getFile(std::istream& istr){
    string fname;
    istr >> fname;
    setFilename(fname.c_str());
    setNoOfLines();
    loadText();
    return istr;
}

const char* TextFile::operator[](unsigned index)const{
    const char* line = NULL;
    if(*this){
        if(index > (m_noOfLines - 1)){
            index -= (m_noOfLines - 1);
        }
        line = m_textLines[index];
    }
    return line;
}

TextFile::operator bool()const{
    bool flag = false;
    if(m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0 && m_pageSize != 0){
        flag = true;
    }
    return flag;
}

const char* TextFile::name()const{
    return m_filename;
}

std::ostream& operator<<(std::ostream& ostr, const TextFile& text){
    return text.view(ostr);
}

std::istream& operator>>(std::istream& istr, TextFile& text){
    return text.getFile(istr);
}

}
