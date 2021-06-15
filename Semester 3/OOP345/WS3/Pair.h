//  Pair module
//  Pair.h
//  YiHsun Lee
//  129713202
//  2021-06-10.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_PAIR_H
#define SDDS_PAIR_H
#include <iostream>

namespace sdds{

template<typename V, typename K>
class Pair{
    V m_val;
    K m_key;
public:
    Pair():m_val{}, m_key{}{};
    Pair(const K& key, const V& value){
        m_val = value;
        m_key = key;
    };
    const V& value()const{
        return m_val;
    };
    const K& key()const{
        return m_key;
    };
    virtual void display(std::ostream& os)const{
        os << m_key << " : " << m_val << "\n";
    };
};

template <typename V, typename K>
std::ostream& operator<<(std::ostream& os, const Pair<V, K>& pair){
    pair.display(os);
    return os;
};

}

#endif
