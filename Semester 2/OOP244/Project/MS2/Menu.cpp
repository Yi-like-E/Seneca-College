/* Citation and Sources...
 Final Project Milestone 2
 Module: Menu
 Filename: Menu.cpp
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
#include <iostream>
#include <cstring>
#include "utils.h"
#include "Menu.h"
using namespace std;
namespace sdds{
Menu::Menu(const char* MenuContent, int NoOfSelections){
    m_text = nullptr;
    m_text = new char[strlen(MenuContent)+1];
    strcpy(m_text, MenuContent);
    m_noOfSel = NoOfSelections;
}

Menu::~Menu(){
    delete[] m_text;
    m_text = nullptr;
}

Menu::Menu(const Menu& copy){
    if(copy.m_text != nullptr){
        m_text = nullptr;
        m_text = new char[strlen(copy.m_text)+1];
        strcpy(m_text, copy.m_text);
        m_noOfSel = copy.m_noOfSel;
    }
}

void Menu::display()const{
    cout << m_text << endl;
    cout << "0- Exit" << endl;
}

int& Menu::operator>>(int& Selection){
    int choice;
    display();
    choice = getInt(0, m_noOfSel, "> ", "Invalid option ");
    Selection = choice;
    return Selection;
}
}

