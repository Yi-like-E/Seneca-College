//  Book module
//  Book.h
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments


#ifndef SDDS_Book_h
#define SDDS_Book_h

#include <iostream>
#include <string>
namespace sdds{
class Book{
    std::string m_author{};
    std::string m_title{};
    std::string m_country{};
    size_t m_year{0};
    double m_price{0};
    std::string m_desc{};
public:
    Book();
    const std::string& title() const;
    const std::string& country() const;
    const size_t& year() const;
    double& price();
    Book(const std::string& strBook);
    friend std::ostream& operator<<(std::ostream&, const Book&);
    
    template <typename T>
    void fixSpelling(T& spellChecker){
        spellChecker(m_desc);
    }
};
}

#endif /* SDDS_Book_h */
