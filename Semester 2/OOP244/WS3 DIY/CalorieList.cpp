
/*
 Name:      YiHsun Lee
 Email:     ylee212@myseneca.ca
 Section:   NII
 Date:      2021/02/04
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */
#include <iostream>
#include "cstring.h"
#include "CalorieList.h"

using namespace std;

namespace sdds {

void CalorieList::setEmpty() {
    m_food = nullptr;
}

bool CalorieList::isValid()const {
    bool flag = true;
    int i;
    
    if (m_food != nullptr) {
        for (i = 0; i < m_noOfMeals && flag == true; i++) {
            flag = m_food[i].isValid();
        }
        if (flag) {
            flag = true;
        }
    } else{
        flag = false;
    }
    return flag;
}

double CalorieList::totalCal()const {
    int i;
    double sum = 0;
    
    for (i = 0; i < m_noOfMeals; i++) {
        sum += m_food[i].calorie();
    }
    return sum;
}

void CalorieList::Title()const {
    cout << "+----------------------------------------------------+" << endl;
    if (isValid()) {
        //cout.setf(ios::left);
        //cout.width(52);  //36
        cout << "|  Daily Calorie Consumption                         |" << endl;
    }
    else {
        cout << "| Invalid Calorie Consumption list                   |" << endl;
    }
    cout << "+--------------------------------+------+------------+" << endl;
    cout << "| Food name                      | Cals | When       |" << endl;
    cout << "+--------------------------------+------+------------+" << endl;
}

void CalorieList::footer()const {
    cout << "+--------------------------------+------+------------+" << endl;
    if (isValid()) {
        if(totalCal() < 99999){
            cout << "|    Total Calories for today:     ";
            cout.fill(' ');
            cout.width(5);
            cout << totalCal();
            cout << "|            |" << endl;
        } else{
            cout << "|    Total Calories for today:   ";
            cout.fill(' ');
            cout.width(6);
            cout << totalCal();
            cout << " |            |" << endl;
        }
        
    }
    else {
        cout << "|    Invalid Calorie Consumption list                |" << endl;
    }
    cout << "+----------------------------------------------------+" << endl;
}

void CalorieList::init(int size) {
    int i;
    
    if (size <= 0) {
        setEmpty();
    }
    else {
        m_noOfMeals = size;
        m_mealsAdded = 0;
        m_food = new Food[m_noOfMeals];
        for (i = 0; i < m_noOfMeals; i++) {
            m_food[i].setEmpty();
        }
    }
}

bool CalorieList::add(const char* item_name, int calorie, int when) {
    bool flag = true;
    
    if (m_mealsAdded < m_noOfMeals) {
        m_food[m_mealsAdded].set(item_name, calorie, when);
        m_mealsAdded += 1;
        flag = true;
    }
    else {
        flag = false;
    }
    return flag;
}

void CalorieList::display() const {
    int i;
    
    Title();
    for (i = 0; i < m_noOfMeals; i++) {
        m_food[i].display();
    }
    footer();
}

void CalorieList::deallocate() {
    delete[] m_food;
    m_food = nullptr;
}



}
