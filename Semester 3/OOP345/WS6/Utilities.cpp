//  Utilities module
//  Utilities.cpp
//  YiHsun Lee
//  129713202
//  ylee212@myseneca.ca
//  2021-06-30.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <sstream>
#include "Utilities.h"
using namespace std;
namespace sdds{
Vehicle* createInstance(std::istream& in){
    Vehicle* v{nullptr};
    string tmp;
    std::stringstream str;
    getline(in, tmp, '\n');
    str << tmp;
    tmp = tmp.substr(0, tmp.find(','));
    tmp.erase(0, tmp.find_first_not_of(" "));
    tmp.erase(tmp.find_last_not_of(" ")+1);
    if(!tmp.empty()){
        if(tmp[0] == 'c' || tmp[0] == 'C'){
            v = new Car(str);
        } else if(tmp[0] == 'r' || tmp[0] == 'R'){
            v = new Racecar(str);
        } else{
            string tag;
            getline(str, tag, ',');
            tag.erase(0, tag.find_first_not_of(" "));
            tag.erase(tag.find_last_not_of(" ")+1);
            throw "Unrecognized record type: [" + tag + "]";
        }
    }
    return v;
}
}
