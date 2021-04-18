/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/16
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {

// Invalid state
void Account::setEmpty() {
    m_number = -1;
    m_balance = 0.0;
}
// New account
Account::Account() {
    m_number = 0;       // account is considered new/not set
    m_balance = 0.0;
}

Account::Account(int number, double balance ) {
    setEmpty();
    if (number >= 10000 && number <= 99999
        && balance > 0) {
        m_number = number;
        m_balance = balance;
    }
}

std::ostream& Account::display() const{
    if (*this) {
        cout << " ";
        cout << m_number;
        cout << " | ";
        cout.width(12);
        cout.precision(2);
        cout.setf(ios::right);
        cout.setf(ios::fixed);
        cout << m_balance;
        cout.unsetf(ios::right);
        cout << " ";
    }
    else if(~*this) {
        cout << "  NEW  |         0.00 ";
    }
    else {
        cout << "  BAD  |    ACCOUNT   ";
    }
    return cout;
}

Account& Account::operator=(int num){
    if(num < 10000 || num > 99999){
        setEmpty();
    } else if(m_number == 0){
        m_number = num;
    }
    return *this;
}

Account& Account::operator=(Account& other){
    if(m_number == 0 && other.m_number >= 10000 && other.m_number <= 99999 && other.m_balance > -1){
        m_balance = other.m_balance;
        other.m_balance = 0.0;
        m_number = other.m_number;
        other.m_number = 0;
    }
    return *this;
}

Account& Account::operator+=(double value){
    if(m_number != -1 && value >= 0){
        m_balance += value;
    }
    return *this;
}

Account& Account::operator-=(double value){
    if(m_number != -1 && value > 0 && m_balance > value){
        m_balance -= value;
    }
    return *this;
}

Account& Account::operator<<(Account& other){
    if(this != &other){
        if(m_number != -1 && other.m_number >= 10000 && other.m_number <= 99999 && other.m_balance >= 0){
            m_balance += other.m_balance;
            other.m_balance = 0.0;
        }
    }
    return *this;
}

Account& Account::operator>>(Account& other){
    if(this != &other){
        if(m_number != -1 && other.m_number >= 10000 && other.m_number <= 99999 && other.m_balance >= 0){
            other.m_balance += m_balance;
            m_balance = 0.0;
        }
    }
    return *this;
}

Account::operator bool()const{
    bool flag = false;
    if(m_number >= 10000 && m_number <= 99999 && m_balance >= 0){
        flag = true;
    }
    return flag;
}

Account::operator int()const{
    return m_number;
}

Account::operator double()const{
    return m_balance;
}

bool Account::operator~()const{
    bool flag = false;
    if(m_number == 0){
        flag = true;
    }
    return flag;
}

double operator+(const Account& accountA, const Account& accountB){
    double sum = 0.0;
    if(accountA.operator double() > 0 && accountB.operator double() > 0){
        sum = (accountA.operator double() + accountB.operator double());
    } 
    return sum;
}

double operator+=(double& value, const Account& account){
    if(account.operator double() > 0 && value >=0){
        value += account.operator double();
    }
    return value;
}
}
