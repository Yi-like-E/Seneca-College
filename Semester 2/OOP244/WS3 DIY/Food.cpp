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
#include "Food.h"
using namespace std;
namespace sdds {

void Food::setName(const char* name) {
    strnCpy(m_foodName, name, 30);
}

void Food::setEmpty() {
    m_foodName[0] = '\0';
    m_consumptionTime = 0;
}

void Food::set(const char* name, int calories, int time) {
    if (name == NULL || time <= 0) {
        setEmpty();
    }
    else {
        setName(name);
        m_calorieNum = calories;
        m_consumptionTime = time;
    }
}

void Food::display()const {
    if (!isValid()) {
        cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
    }
    else {
        cout << "| ";
        cout.setf(ios::left);
        cout.fill('.');
        cout.width(30);
        cout << m_foodName;
        cout << " | ";
        cout.unsetf(ios::left);
        cout.fill(' ');
        cout.width(4);
        cout << m_calorieNum;
        cout << " | ";
        cout.setf(ios::left);
        cout.fill(' ');
        cout.width(10);
        if(m_consumptionTime == 1){
            cout << "Breakfast";
        } else if(m_consumptionTime == 2){
            cout << "Lunch";
        } else if(m_consumptionTime == 3){
            cout << "Dinner";
        } else if(m_consumptionTime == 4){
            cout << "Snack";
        }
        cout << " |" << endl;
    }
}

bool Food::isValid()const {
    bool flag = true;
    
    if (m_foodName[0] == '\0' || m_consumptionTime < 0) {
        flag = false;
    }
    
    return flag;
}

int Food::calorie()const {
    int calorie = 0;
    if( 0 <= m_calorieNum || m_calorieNum >= 3000){
        calorie = m_calorieNum;
    };
    return calorie;
}

int Food::time()const {
    int when = -1;
    
    if(0 < m_consumptionTime && m_consumptionTime <= 4){
        when = m_consumptionTime;
    }
    return when;
}

}
