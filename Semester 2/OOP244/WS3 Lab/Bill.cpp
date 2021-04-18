/*
 Section:   NII
 Date:      2021/02/04
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#include <iostream>
#include "cstring.h"
#include "Bill.h"

using namespace std;

namespace sdds {

    void Bill::setEmpty() {
        m_title[0] = '\0';
        m_items = nullptr;
    }

    bool Bill::isValid()const {
        bool flag = true;
        int i;

        if (m_title[0] != '\0' && m_items != nullptr) {
            for (i = 0; i < m_noOfItems && flag == true; i++) {
                flag = m_items[i].isValid();
            }
            if (flag) {
                flag = true;
            }
        }
        return flag;
    }

    double Bill::totalTax()const {
        int i;
        double sum = 0;

        for (i = 0; i < m_noOfItems; i++) {
            sum += m_items[i].tax();
        }
        return sum;
    }

    double Bill::totalPrice()const {
        int i;
        double sum = 0;

        for (i = 0; i < m_noOfItems; i++) {
            sum += m_items[i].price();
        }
        return sum;
    }

    void Bill::Title()const {
        cout << "+--------------------------------------+" << endl;
        if (isValid()) {
            cout << "| ";
            cout.setf(ios::left);
            cout.width(36);
            cout << m_title;
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+----------------------+---------+-----+" << endl;
        cout << "| Item Name            | Price   + Tax |" << endl;
        cout << "+----------------------+---------+-----+" << endl;
    }

    void Bill::footer()const {
        cout << "+----------------------+---------+-----+" << endl;
        if (isValid()) {
            cout << "|                Total Tax: ";
            cout.fill(' ');
            cout.width(10);
            cout.setf(ios::fixed);
            cout.precision(2);
            cout << totalTax();
            cout << " |" << endl;
            cout << "|              Total Price: ";
            cout.fill(' ');
            cout.width(10);
            cout.precision(2);
            cout << totalPrice();
            cout << " |" << endl;
            cout << "|          Total After Tax: ";
            cout.fill(' ');
            cout.width(10);
            cout.precision(2);
            cout << totalTax() + totalPrice();
            cout << " |" << endl;
        }
        else {
            cout << "| Invalid Bill                         |" << endl;
        }
        cout << "+--------------------------------------+" << endl;
    }

    void Bill::init(const char* title, int noOfItems) {
        int i;

        if (title[0] == '\0' || noOfItems <= 0) {
            setEmpty();
        }
        else {
            m_noOfItems = noOfItems;
            m_itemsAdded = 0;
            strnCpy(m_title, title, 36);
            m_items = new Item[m_noOfItems];
            for (i = 0; i < m_noOfItems; i++) {
                m_items[i].setEmpty();
            }
        }
    }

    bool Bill::add(const char* item_name, double price, bool taxed) {
        bool flag = true;

        if (m_itemsAdded < m_noOfItems) {
            m_items[m_itemsAdded].set(item_name, price, taxed);
            m_itemsAdded += 1;
            flag = true;
        }
        else {
            flag = false;
        }
        return flag;
    }

    void Bill::display() const {
        int i;

        Title();
        for (i = 0; i < m_noOfItems; i++) {
            m_items[i].display();
        }
        footer();
    }

    void Bill::deallocate() {
        delete[] m_items;
        m_items = nullptr;
    }

}
