/*
 Name:       YiHsun Lee
 Student ID: 129713202
 Email:      ylee212@myseneca.ca
 Section:    NII
 Date:       2021/02/11
 I have done all the coding by myself and only copied the code
 that my professor provided to complete my workshops and assignments.
 */

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp
#include "Canister.h"


using namespace std;
namespace sdds {

const double PI = 3.14159265;

void Canister::setToDefault(){
    m_contentName = nullptr;
    m_height = 13.0;
    m_diameter = 10.0;
    m_contentVolume = 0.0;
    m_usable = true;
}

bool Canister::isEmpty()const{
    bool flag = false;
    if(m_contentVolume < 0.00001){
        flag = true;
    }
    return flag;
}

bool Canister::hasSameContent(const Canister& C)const{
    bool flag = false;
    if(strCmp(C.m_contentName, m_contentName) == 0 && C.m_contentName != nullptr && m_contentName != nullptr){
        flag = true;
    }
    return flag;
}

void Canister::setName(const char* Cstr){
    if(Cstr != nullptr && m_usable == true){
        delete[] m_contentName;
        m_contentName = new char[strLen(Cstr)+1];
        strCpy(m_contentName, Cstr);
    }
}

Canister::Canister(){
    setToDefault();
}

Canister::Canister(const char* contentName){
    setToDefault();
    setName(contentName);
}

Canister::Canister(double height, double diameter, const char* contentName){
    setToDefault();
    if(height >= 10 && height <= 40 && diameter >= 10 && diameter <= 30){
        m_height = height;
        m_diameter = diameter;
        m_contentVolume = 0;
        setName(contentName);
    } else {
        m_usable = false;
    }
}

void Canister::clear(){
    if(m_usable == false){
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}

double Canister::capacity()const{
    double volume;
    volume = PI * (m_height - 0.267) * (m_diameter/2) * (m_diameter/2);
    return volume;
}

double Canister::volume()const{
    return m_contentVolume;
}

Canister& Canister::setContent(const char* contentName){
    if(contentName == nullptr){
        (*this).m_usable = false;
    } else if ((*this).isEmpty()){
        setName(contentName);
    } else if(strCmp(m_contentName, contentName) != 0){
        (*this).m_usable = false;
    }
    return *this;
}

Canister& Canister::pour(double quantity){
    if ((*this).m_usable == true && quantity > 0){
        if((quantity + volume()) <= capacity()){
            (*this).m_contentVolume += quantity;
        } else {
            (*this).m_usable = false;
        }
    }
    return *this;
}

Canister& Canister::pour(Canister& C){
    setContent(C.m_contentName);
    if(C.volume() > (capacity() - volume())){
        C.m_contentVolume -= (capacity() - volume());
        m_contentVolume = capacity();
    } else {
        pour(C.m_contentVolume);
        C.m_contentVolume = 0.0;
    }
    return C;
}

std::ostream& Canister::display()const{
    cout.width(7);
    cout.setf(ios::fixed);
    cout.precision(1);
    cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
    if(m_usable == false){
        cout << " of Unusable content, discard!";
    } else if (m_contentName != nullptr){
        cout << " of ";
        cout.setf(ios::right);
        cout.width(7);
        cout << m_contentVolume << "cc   " << m_contentName;
    }
    
    return cout;
}

Canister::~Canister(){}

}
