//  Movie module
//  Movie.h
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Movie_h
#define SDDS_Movie_h

#include <iostream>
#include <string>
namespace sdds{
class Movie{
    std::string m_title{};
    int m_releaseYear{0};
    std::string m_desc{};
public:
    Movie();
    const std::string& title() const;
    Movie(const std::string& strMovie);
    friend std::ostream& operator<<(std::ostream&, const Movie&);
    
    template <typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_title);
        spellChecker(m_desc);
    };
};
}

#endif /* Movie_h */
