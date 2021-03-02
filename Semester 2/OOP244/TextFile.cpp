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
Line::~Line() {
    delete[] m_value;
}


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
    char c;
    std::ifstream f(m_filename);
    //if(f.is_open()){
        while(f){
            c = f.get();
            if(c == '\n'){
                m_noOfLines++;
            }
        }
    //}
    //m_noOfLines++;
    if(m_noOfLines == 0){
        delete[] m_filename;
        m_filename = nullptr;
    }
    m_noOfLines++;
}

void TextFile::loadText(){
    int i = 0;
    std::string line;
    if(m_filename != NULL){
        delete[] m_textLines;
        m_textLines = new Line[m_noOfLines];
        std::ifstream f(m_filename);
        std::getline(f, line);
        while(!f.eof()){
            f >> line;
            m_textLines[i] = line.c_str();
            i++;
        }
        m_noOfLines = i;
    }
//    while(f.is_open() && !f.eof()){
//        std::getline(f, line);
//        for(i = 0; i < m_noOfLines; i++){
//            f >> line;
//            m_textLines[i] = line.c_str();
//        }
//        m_noOfLines = i;
//    }
}

void TextFile::saveAs(const char *fileName)const{
    int i;
    std::ofstream f(m_filename);
    if(f.is_open()){
        for(i = 0; i < m_noOfLines; i++){
            f << m_textLines[i] << endl;
        }
    }
}

TextFile::TextFile(unsigned pageSize){
    setEmpty();
    m_pageSize = pageSize;
}

TextFile::TextFile(const char* filename, unsigned pageSize){
    setEmpty();
    m_pageSize = pageSize;
    if(filename != nullptr){
        setFilename(filename, true);
        setNoOfLines();
        loadText();
    }
}

TextFile::TextFile(const TextFile& source){
    setEmpty();
    m_pageSize = source.m_pageSize;
    if(source){
        setFilename(source.m_filename);
        saveAs(source.m_filename);
        setNoOfLines();
        loadText();
    }
}

TextFile& TextFile::operator=(const TextFile& source){
    if(this != &source){
        if(source){
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
    int i, j, length = strLen(m_filename);
    char input;
    if(*this){
        ostr << m_filename;
        ostr << ostr.width(length) << ostr.fill('=') << "=" << endl;
        for(i = 0; i < m_pageSize; i++){
            ostr << m_textLines[i];
        }
        ostr << "Hit ENTER to continue...";
        cin >> input;
        if(input == '\n'){
            for(j = m_pageSize; j < (m_noOfLines - m_pageSize); j++){
                ostr << m_textLines[j];
            }
        }
    }
    return ostr;
}

std::istream& TextFile::getFile(std::istream& istr){
    char fname[] = {'\0'};
    istr >> fname;
    setFilename(fname);
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
    if(m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0){
        flag = true;
    }
    return flag;
}

const char* TextFile::name()const{
    return m_filename;
}

std::ostream& operator<<(std::ostream& ostr, const TextFile& text){
    text.view(ostr);
    return ostr;
}

std::istream& operator>>(std::istream& istr, TextFile& text){
    text.getFile(istr);
    return istr;
}

}
