// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/03
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_CustomerOrder_h
#define SDDS_CustomerOrder_h

#include <iostream>
#include "Station.h"
namespace sdds{
struct Item
{
    std::string m_itemName{};
    size_t m_serialNumber{0};
    bool m_isFilled{false};
    
    Item(const std::string& src) : m_itemName(src) {};
};

class CustomerOrder{
    std::string m_name{};
    std::string m_product{};
    size_t m_cntItem{0};
    Item** m_lstItem{};
    static size_t m_widthField;
public:
    CustomerOrder(){};
    CustomerOrder(const std::string str);
    CustomerOrder& operator=(const CustomerOrder&) = delete;
    CustomerOrder(const CustomerOrder&) {throw "Copy operator not allowed";};
    CustomerOrder(CustomerOrder&& src)noexcept;
    CustomerOrder& operator=(CustomerOrder&& src)noexcept;
    ~CustomerOrder();
    bool isFilled() const;
    bool isItemFilled(const std::string& itemName) const;
    void fillItem(Station& station, std::ostream& os);
    void display(std::ostream& os) const;
};
}

#endif /* SDDS_CustomerOrder_h */
