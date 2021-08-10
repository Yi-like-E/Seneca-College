// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <vector>
#include <algorithm>
#include "Workstation.h"
using namespace std;
namespace sdds{
std::deque<CustomerOrder>pending{};
std::deque<CustomerOrder>completed{};
std::deque<CustomerOrder>incomplete{};

Workstation::Workstation(const std::string& str):Station(str){};

void Workstation::fill(std::ostream& os){
    if (!m_orders.empty()){
        m_orders.front().fillItem(*this, os);
    };
}

bool Workstation::attemptToMoveOrder(){
    bool flag = false;
    if(!m_orders.empty()){
        if(m_orders.front().isItemFilled(Station::getItemName())){
            if(m_pNextStation){
                *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
            }
            else{
                if(m_orders.front().isFilled()){
                    completed.push_back(std::move(m_orders.front()));
                } else{
                    incomplete.push_back(std::move(m_orders.front()));
                }
                m_orders.pop_front();
            }
            flag = true;
        }
        else if(!Station::getQuantity()){
            if(m_pNextStation){
                *m_pNextStation += std::move(m_orders.front());
                m_orders.pop_front();
            }
            else{
                incomplete.push_back(std::move(m_orders.front()));
                m_orders.pop_front();
            }

            flag = true;
        }
    }
    return flag;
};

void Workstation::setNextStation(Workstation* station){
    m_pNextStation = station;
};

Workstation* Workstation::getNextStation() const{
    return m_pNextStation;
};

void Workstation::display(std::ostream& os) const{
    if(m_pNextStation == nullptr){
        os << getItemName() << " --> End of Line\n";
    }
    else {
        os << getItemName() << " --> " << getNextStation()->getItemName() << endl;
    }
};

Workstation& Workstation::operator+=(CustomerOrder&& newOrder){
    m_orders.push_back(std::move(newOrder));
    return *this;
};
}
