/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/16
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
class Account {
    int m_number;
    double m_balance;
    void setEmpty();
public:
    Account();
    Account(int number, double balance);
    std::ostream& display()const;
    
    // binary operators
    Account& operator=(int num);
    Account& operator=(Account& other);
    Account& operator+=(double value);
    Account& operator-=(double value);
    Account& operator<<(Account& other);
    Account& operator>>(Account& other);
    
    // type conversion operators
    operator bool()const;
    operator int()const;
    operator double()const;
    
    // unary member operator
    bool operator~()const;
};

// binary helper operators
double operator+(const Account& accountA, const Account& accountB);
double operator+=(double& value, const Account& account);
}
#endif // SDDS_ACCOUNT_H_
