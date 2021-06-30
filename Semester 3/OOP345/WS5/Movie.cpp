//  Movie module
//  Movie.cpp
//  YiHsun Lee
//  129713202
//  2021-06-19.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <sstream>
#include "Movie.h"
using namespace std;

namespace sdds{
Movie::Movie(){}

const std::string& Movie::title() const{
    return m_title;
}

Movie::Movie(const std::string& strMovie){
    std::string temp, title, desc;
    int year;
    temp = strMovie;

    //find title
    title = temp.substr(0, temp.find(","));
    temp.erase(0, temp.find(",") + 1);
    title.erase(0, title.find_first_not_of(" "));
    title.erase(title.find_last_not_of(" ") + 1);

    //find release year
    year = std::stoi(temp.substr(0, temp.find(",")));
    temp.erase(0, temp.find(",") + 1);

    //find desctiption
    desc = temp;
    desc.erase(0, desc.find_first_not_of(" "));
    desc.erase(desc.find_last_not_of(" ") + 1);

    m_title = title;
    m_releaseYear = year;
    m_desc = desc;
    
}

std::ostream& operator<<(std::ostream& os, const Movie& src){
    os.width(40);
    os << src.title() << " | ";
    os.width(4);
    os << src.m_releaseYear << " | " << src.m_desc << endl;
    return os;
    
}
}
