//  Collection module
//  Collection.h
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_Collection_h
#define SDDS_Collection_h

#include <iostream>
#include <string>

namespace sdds{

template <typename T>
class Collection{
    std::string m_colName{};
    T* m_items{};
    size_t m_size{0};
    void (*observerFn)(const Collection<T>&, const T&){nullptr};
public:
    Collection(const std::string& name){
        m_colName = name;
    }
    
    Collection(const Collection&) = delete;
    Collection& operator=(const Collection&) = delete;
    
    ~Collection(){
        delete[] m_items;
        m_items = nullptr;
    };
    
    const std::string& name() const{
        return m_colName;
    };
    
    size_t size() const{
        return m_size;
    };
    
    void setObserver(void (*observer)(const Collection<T>&, const T&)){
        this->observerFn = observer;
    };
    
    Collection<T>& operator+=(const T& item){
        bool flag = false;
        for(size_t i = 0; i < m_size; i++){
            if(m_items[i].title() == item.title()){
                flag = true;
            }
        }
        if(!flag){
            T* temp = new T[m_size+1];
            for(size_t i = 0; i < m_size; i++){
                temp[i] = m_items[i];
            }
            temp[m_size] = item;
            delete[] m_items;
            m_items = temp;
            ++m_size;
            if(observerFn != nullptr){
                observerFn(*this, m_items[m_size-1]);
            }
        }
        return *this;
    };
    
    T& operator[](size_t idx) const{
        if(idx >= m_size){
            throw std::out_of_range("Bad index [" + std::to_string(idx)+ "]. Collection has [" + std::to_string(size()) + "] items.");
        } else{
            return m_items[idx];
        }
    }
    
    T* operator[](const std::string& title) const{
        for(size_t i = 0; i < m_size; i++){
            if(m_items[i].title() == title){
                return &(m_items[i]);
            }
        }
        return nullptr;
    };
    
    friend std::ostream& operator<<(std::ostream& os, const Collection& src){
        for(size_t i = 0; i < src.size(); i++){
            os << src[i];
        }
        return os;
    }
};
}

#endif /* Collection_h */
