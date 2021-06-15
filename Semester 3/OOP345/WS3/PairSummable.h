//  PairSummable module
//  PairSummable.h
//  YiHsun Lee
//  129713202
//  2021-06-10.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments


#ifndef SDDS_PAIRSUMMABLE_H
#define SDDS_PAIRSUMMABLE_H

#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds{
template<typename V, typename K>
class PairSummable: public Pair<V, K>{
    static V initVal;
    static size_t minWidth;
public:
    PairSummable(){};
    PairSummable(const K& key, const V& value = initVal):Pair<V, K>(key, value){
        if(minWidth < key.size()){
            minWidth = key.size();
        }
    };
    bool isCompatibleWith(const PairSummable<V, K>& b)const{
        bool flag = false;
        if(b.key() == this->key()){
            flag = true;
        }
        return flag;
    };
    PairSummable<V, K>& operator+=(const PairSummable<V, K>& obj){
        if(isCompatibleWith(obj)){
            *this = PairSummable(this->key(), this->value() + obj.value());
        }
        return *this;
    };
    void display(std::ostream& os)const{
        os.setf(std::ios::left);
        os.width(minWidth);
        Pair<V, K>::display(os);
        os.unsetf(std::ios::left);
    }
};

template<typename V, typename K>
V PairSummable<V, K>::initVal{};
template<typename V, typename K>
size_t PairSummable<V, K>::minWidth = 0;

template<>
PairSummable<std::string, std::string>& PairSummable<std::string, std::string>::operator+=(const PairSummable<std::string, std::string>& obj){
    std::string temp;
    if(this->value() == ""){
        temp = obj.value();
    } else {
        temp = this->value() + ", " + obj.value();
    }
    *this = PairSummable(this->key(), temp);
    return *this;
};

}

#endif
