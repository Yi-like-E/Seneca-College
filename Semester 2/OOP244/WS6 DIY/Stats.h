/*
Name: YiHsun Lee
Student no.: 129713202
Section: NII
*/
#include <iostream>
namespace sdds {
    class Number {
        double m_value;
        operator const double()const;
        Number();
        Number& operator=(const double);
        ~Number() {};
        friend class Stats;
    };
    class Stats {
        Number* m_numbers = nullptr;
        char* m_filename = nullptr;
        unsigned m_columnWidth;
        unsigned m_noOfColumns;
        unsigned m_precision;
        unsigned m_numCount;    // counts how many values are in the .csv aka size
        double dummy;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfnumCount();
        void load();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        // 3 arg constructor
        Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        // 4 arg constructor
        Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        // copy constructor
        Stats(const Stats&);
        // copy assignment
        Stats& operator=(const Stats&);
        // index operator overloads
        double& operator[](unsigned idx);
        double operator[](unsigned idx)const;
        // boolean conversion overload
        operator bool()const;
        // methods(member variables)
        void sort(bool ascending);
        unsigned size()const;
        const char* name()const;
        unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        // destructor
        ~Stats();
    };
    std::ostream& operator<<(std::ostream& ostr, const Stats& stat);
    std::istream& operator>>(std::istream& istr, Stats& stat);
}