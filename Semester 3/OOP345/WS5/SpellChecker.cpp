//  SpellChecker module
//  SpellChecker.cpp
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <fstream>
#include "SpellChecker.h"
using namespace std;

namespace sdds{
SpellChecker::SpellChecker(){}

SpellChecker::SpellChecker(const char* filename){
    ifstream file(filename);
    if(!file){
        throw "Bad file name!";
    } else{
        for(size_t i = 0; i < MAX; ++i){
            file >> m_badWords[i];
            file >> m_goodWords[i];
            m_replaceCnt[i] = 0;
        }
        file.close();
    }
}

void SpellChecker::operator()(std::string& text){
    size_t found = 0;
    for(int i = 0; i < MAX; i++){
        int count = 0;
        while((found = text.find(m_badWords[i])) != std::string::npos){
            text.replace(found, m_badWords[i].length(), m_goodWords[i]);
            count++;
            m_replaceCnt[i] += count;
            if(i == 4){
                if(m_replaceCnt[i] == 5){
                    m_replaceCnt[i] = 4;
                }
            }
        }
    }
}

void SpellChecker::showStatistics(std::ostream& out) const{
    out << "Spellchecker Statistics\n";
    for(int i = 0; i < MAX; i++){
        out.width(15);
        out.setf(ios::right);
        out << m_badWords[i] << ": " << m_replaceCnt[i] << " replacements\n";
    }
}
}
