//  StringSet module
//  StringSet.h
//  YiHsun Lee
//  129713202
//  2021-06-03.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments


#ifndef SDDS_StringSet_h
#define SDDS_StringSet_h

#include <string>
namespace sdds{
class StringSet{
    std::string* string;
    size_t numOfStr;
public:
    StringSet();
    StringSet(const std::string& filename);
    StringSet(const StringSet& src); // copy constructor
    StringSet& operator=(const StringSet& src); // copy assignment operator
    StringSet(StringSet&& src); // move operator
    StringSet& operator=(StringSet&& src); // move assignment operator
    size_t size();
    std::string operator[](size_t)const;
    ~StringSet(); // destructor
};
}
#endif /* SDDS_StringSet_h */
