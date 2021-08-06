// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <string>
#include <exception>
#include "Utilities.h"
using namespace std;
namespace sdds{

char Utilities::m_delimiter{};

void Utilities::setFieldWidth(size_t newWidth){
    m_widthField = newWidth;
};

size_t Utilities::getFieldWidth() const{
    return m_widthField;
};

std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more){
    string token = {};
    size_t pos = str.find(m_delimiter, next_pos);
    if(pos != next_pos){
        token = str.substr(next_pos, pos - next_pos);
        next_pos = pos+1;
        m_widthField = std::max(m_widthField, token.length());
        if(pos != string::npos){
            more = true;
        } else{
            more = false;
        }
    } else {
        more = false;
        throw "Delimiter not found at " + std::to_string(next_pos);
    }
    return token;
};

void Utilities::setDelimiter(char newDelimiter){
    m_delimiter = newDelimiter;
};

char Utilities::getDelimiter(){
    return m_delimiter;
};
}
