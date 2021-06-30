//  SpellChecker module
//  SpellChecker.h
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments


#ifndef SDDS_SpellChecker_hpp
#define SDDS_SpellChecker_hpp

#include <iostream>
#include <string>

const int MAX = 6;
namespace sdds{
class SpellChecker{
    std::string m_badWords[MAX]{};
    std::string m_goodWords[MAX]{};
    int m_replaceCnt[MAX]{};
public:
    SpellChecker();
    SpellChecker(const char* filename);
    void operator()(std::string& text);
    void showStatistics(std::ostream& out) const;
};
}

#endif /* SDDS_SpellChecker_h */
