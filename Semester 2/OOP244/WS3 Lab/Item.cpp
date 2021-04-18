/*
 Section:   NII
 Date:      2021/02/04
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

    void Item::setName(const char* name) {
        strnCpy(m_itemName, name, 20);
    }

    void Item::setEmpty() {
        m_itemName[0] = '\0';
        m_price = 0.0;
    }

    void Item::set(const char* name, double price, bool taxed) {
        if (name == NULL || price < 0.0) {
            setEmpty();
        }
        else {
            setName(name);
            m_price = price;
            m_taxed = taxed;
        }
    }

    void Item::display()const {
        if (!isValid()) {
            cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
        }
        else {
            cout << "| ";
            cout.setf(ios::left);
            cout.fill('.');
            cout.width(20);
            cout << m_itemName;
            cout << " | ";
            cout.unsetf(ios::left);
            cout.fill(' ');
            cout.width(7);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << m_price;
            cout << " | ";
            if (m_taxed) {
                cout << "Yes";
            }
            else {
                cout << "No ";
            }
            cout << " |" << endl;
        }
    }

    bool Item::isValid()const {
        bool flag = true;

        if (m_itemName[0] == '\0' || m_price < 0.0) {
            flag = false;
        }

        return flag;
    }

    double Item::price()const {
        double price = 0;
        price = m_price;
        return price;
    }

    double Item::tax()const {
        const double taxRate = 0.13;
        double result = 0;

        if (m_taxed) {
            result = m_price * taxRate;
        }
        else {
            result = 0.0;
        }
        return result;
    }

}
