// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/15
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds{
size_t CustomerOrder::m_widthField = 0;

CustomerOrder::CustomerOrder(const std::string str){
    Utilities u;
    bool more = false;
    size_t pos = 0;

    m_name = u.extractToken(str, pos, more);
    m_product = u.extractToken(str, pos, more);
    string items = str.substr(pos, str.length()-pos);
    m_cntItem = (std::count(items.begin(), items.end(), u.getDelimiter()))+1;
    m_lstItem = new Item*[m_cntItem];
    for(size_t i = 0; i < m_cntItem && more; i++){ 
        m_lstItem[i] = new Item(u.extractToken(str, pos, more));
    }
    m_widthField = std::max(m_widthField, u.getFieldWidth());
};

CustomerOrder::CustomerOrder(CustomerOrder&& src)noexcept{
    *this = std::move(src);
};
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src)noexcept{
    if(this != &src){
        for(size_t i = 0; i < m_cntItem; i++){
            delete m_lstItem[i];
        }
        delete[] m_lstItem;
        m_name = src.m_name;
        src.m_name = "";
        m_product = src.m_product;
        src.m_product = "";
        m_cntItem = src.m_cntItem;
        src.m_cntItem = 0;
        m_lstItem = src.m_lstItem;
        src.m_lstItem = nullptr;
    }
    return *this;
};

CustomerOrder::~CustomerOrder(){
    for(size_t i = 0; i < m_cntItem; i++){
        delete m_lstItem[i];
    }
    delete[] m_lstItem;
    m_lstItem = nullptr;
};

bool CustomerOrder::isFilled() const{
    bool flag = true;
    for(size_t i = 0; i < m_cntItem; i++){
        if(!m_lstItem[i]->m_isFilled){
            flag = false;
        }
    };
    return flag;
};

bool CustomerOrder::isItemFilled(const std::string& itemName) const{
    bool flag = true;
    for(size_t i = 0; i < m_cntItem; i++){
        if(m_lstItem[i]->m_itemName == itemName){
            flag = m_lstItem[i]->m_isFilled;
        }
    }
    return flag;
};

void CustomerOrder::fillItem(Station& station, std::ostream& os){
    for(size_t i = 0; i < m_cntItem; i++){
        if(station.getItemName() == m_lstItem[i]->m_itemName){
            if(station.getQuantity() != 0){
                m_lstItem[i]->m_serialNumber = station.getNextSerialNumber();
                m_lstItem[i]->m_isFilled = true;
                station.updateQuantity();
                os << "    Filled " << m_name << ", " << m_product
                << " [" << m_lstItem[i]->m_itemName << "]\n";
            } else{
                os << "    Unable to fill " << m_name << ", " << m_product
                << " [" << m_lstItem[i]->m_itemName << "]\n";
            }
        }
    }
};

void CustomerOrder::display(std::ostream& os) const{
    os << m_name << " - " << m_product << endl;
    for(size_t i = 0; i < m_cntItem; i++){
        os << "[" << std::right << setw(6) << setfill('0') << m_lstItem[i]->m_serialNumber <<"] "
        << std::left << setw(m_widthField) << setfill(' ') << m_lstItem[i]->m_itemName
        << " - " << (m_lstItem[i]->m_isFilled? "FILLED" : "TO BE FILLED") << endl;
    }
};
}
