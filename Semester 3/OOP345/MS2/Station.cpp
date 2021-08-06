// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/02
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#include "Station.h"
#include "Utilities.h"
using namespace std;

namespace sdds{

size_t Station::m_widthField{0};
int Station::id_generator{0};

Station::Station(const std::string& str){
    Utilities u;
    bool more = false;
    size_t pos = 0;
    
    m_id = ++id_generator;
    m_name = u.extractToken(str, pos, more);
    m_serNum = stoi(u.extractToken(str, pos, more));
    m_numStock = stoi(u.extractToken(str, pos, more));
    m_widthField = std::max(m_widthField, u.getFieldWidth());
    m_desc = u.extractToken(str, pos, more);
    
};

const std::string& Station::getItemName() const{
    return m_name;
};

size_t Station::getNextSerialNumber(){
    return m_serNum++;
};

size_t Station::getQuantity() const{
    return m_numStock;
};

void Station::updateQuantity(){
    m_numStock--;
    if(m_numStock < 0){
        m_numStock = 0;
    }
};

void Station::display(std::ostream& os, bool full) const{
    os << "[";
    os.setf(ios::right);
    os.width(3);
    os.fill('0');
    os << m_id <<"] Item: ";
    os.width(m_widthField);
    os.unsetf(ios::right);
    os.setf(ios::left);
    os.fill(' ');
    os << m_name << " [";
    os.width(6);
    os.unsetf(ios::left);
    os.fill('0');
    os << m_serNum <<"]";
    if(full){
        os << " Quantity: ";
        os.width(m_widthField);
        os.setf(ios::left);
        os.fill(' ');
        os << m_numStock << " Description: " << m_desc << endl;
    } else{
        os << endl;
    }
};
}
