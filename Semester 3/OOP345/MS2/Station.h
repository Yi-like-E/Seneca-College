// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_Station_h
#define SDDS_Station_h

#include <iostream>
namespace sdds{
class Station{
    int m_id;
    std::string m_name{};
    std::string m_desc{};
    size_t m_serNum;
    size_t m_numStock;
    static size_t m_widthField;
    static int id_generator;
public:
    Station(){};
    Station(const std::string& str);
    const std::string& getItemName() const;
    size_t getNextSerialNumber();
    size_t getQuantity() const;
    void updateQuantity();
    void display(std::ostream& os, bool full) const;
};
}

#endif /* SDDS_Station_h */
