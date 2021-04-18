#include <cstring>
#include <iostream>
#include "HtmlText.h"
using namespace std;
namespace sdds {
HtmlText::HtmlText(const char* filename, const char* title):Text(filename){
    if(title != nullptr){
        m_title = nullptr;
        m_title = new char[strlen(title)+1];
        strcpy(m_title, title);
    } else {
        m_title = nullptr;
    }
}

HtmlText::HtmlText(const HtmlText& html):Text(html){
    if(html.m_title != nullptr){
        m_title = new char[strlen(html.m_title)+1];
        strcpy(m_title, html.m_title);
    }
}

HtmlText& HtmlText::operator=(const HtmlText& source){
    if(this != &source){
        if(source.m_title != nullptr){
            if(m_title != nullptr){
                delete[] m_title;
                m_title = nullptr;
            }
            m_title = new char[strlen(source.m_title)+1];
            strcpy(m_title, source.m_title);
            Text::operator=(source);
        }
    }
    return *this;
}

HtmlText::~HtmlText(){
    delete[] m_title;
    m_title = nullptr;
}

void HtmlText::write(ostream& os)const{
    char ch;
    bool MS = false;
    int i = 0;
    
    os << "<html><head><title>";
    if(m_title != nullptr){
        os << m_title;
    } else {
        os << "No Title";
    }
    os << "</title></head>\n<body>\n";
    if(m_title != nullptr){
        os << "<h1>" << m_title << "</h1>\n";
    }
    while(Text::operator[](i) != '\0'){
        ch = Text::operator[](i);
        if(Text::operator[](i) == ' '){
            if(MS){
                os << "&nbsp;";
            } else {
                os << ' ';
                MS = true;
            }
        } else if (ch == '<'){
            os << "&lt;";
            MS = false;
        } else if (ch == '>'){
            os << "&gt;";
            MS = false;
        } else if (ch == '\n'){
            os << "<br />\n";
            MS = false;
        } else {
            os << ch;
            MS = false;
        }
        i++;
    }
    os << "</body>\n</html>";
    
}

}

