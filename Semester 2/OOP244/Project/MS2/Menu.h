/* Citation and Sources...
 Final Project Milestone 2
 Module: Menu
 Filename: Menu.h
 Version 1.0
 Author    YiHsun Lee
 Revision History
 -----------------------------------------------------------
 Date      Reason
 2020/3/17  Preliminary release
 2020/?/?  Debugged DMA
 -----------------------------------------------------------
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 ----------------------------------------------------------- */
#ifndef Menu_h
#define Menu_h

#include <iostream>
using namespace std;
namespace sdds{
class Menu{
    char* m_text; // holds the menu content dynamically
    int m_noOfSel;  // holds the number of options displayed in menu content
    void display()const;
public:
    Menu(const char* MenuContent, int NoOfSelections);
    virtual ~Menu();
    int& operator>>(int& Selection);
    // add safe copying logic
    Menu& operator=(const Menu&) = delete;
    Menu(const Menu& copy);
};
}

#endif /* Menu_h */
