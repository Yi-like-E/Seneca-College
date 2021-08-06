// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef SDDS_Utilities_h
#define SDDS_Utilities_h

#include <iostream>
namespace sdds{
class Utilities{
    size_t m_widthField{1};
    static char m_delimiter;
public:
    void setFieldWidth(size_t newWidth);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
};
}

#endif /* SDDS_Utilities_h */
