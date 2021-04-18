/*
Name: YiHsun Lee
Student no.: 129713202
Section: NII
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Stats.h"
#include "cstring.h"
using namespace std;
namespace sdds {
    Number::operator const double() const {
        return (const double)m_value;
    }
    Number& Number::operator=(const double value) {
        m_value = value;
        return *this;
    }

    Number::Number() {
        m_value = 0.0;
    }

    void Stats::setEmpty() {
        delete[] m_numbers;
        m_numbers = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Stats::setFilename(const char* fname, bool isCopy) {
        int length;
        if (!isCopy) {
            delete[] m_filename;
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else {
            delete[] m_filename;
            length = strLen(fname) + 3;
            m_filename = new char[length];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }

    void Stats::setNoOfnumCount() {
        int count = 0;
        char ch;
        std::ifstream f(m_filename);
        while (!f.eof()) {
            ch = f.get();
            if (ch == ',') {
                count++;
            }
        }
        m_numCount = count;
        if (m_numCount == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        else {
            m_numCount += 1;
        }
    }

    void Stats::load() {
        int i = 0;
        string line_num;
        double num;
        if (m_numCount > 0) {
            delete[] m_numbers;
            m_numbers = new Number[m_numCount];
            std::ifstream f(m_filename);
            while (getline(f, line_num, ',')) {
                num = stod(line_num);
                m_numbers[i] = num;
                i++;
            }
        }
        m_numCount = i;
    }

    void Stats::saveAs(const char* fileName)const {
        unsigned int i;
        std::ofstream f(fileName);
        if (f.is_open()) {
            for (i = 0; i < size(); i++) {
                if (i == size() - 1) {
                    f << m_numbers[i];
                }
                else {
                    f << m_numbers[i] << ",";
                }
            }
        }
    }

    Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        setEmpty();
    }

    Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        setEmpty();
        std::ifstream f(filename);
        if (f.good() && filename != nullptr) {
            setFilename(filename);
            setNoOfnumCount();
            load();
        }
    }

    Stats::Stats(const Stats& source) {
        m_columnWidth = source.m_columnWidth;
        m_noOfColumns = source.m_noOfColumns;
        m_precision = source.m_precision;
        setEmpty();
        if (source) {
            setFilename(source.name(), true);
            source.saveAs(m_filename);
            setNoOfnumCount();
            load();
        }
    }

    Stats& Stats::operator=(const Stats& source) {
        if (this != &source) {
            if (source && *this) {
                m_columnWidth = source.m_columnWidth;
                m_noOfColumns = source.m_noOfColumns;
                m_precision = source.m_precision;
                delete[] m_numbers;
                m_numbers = nullptr;
                source.saveAs(m_filename);
                setNoOfnumCount();
                load();
            }
        }
        return *this;
    }

    Stats::~Stats() {
        delete[] m_numbers;
        delete[] m_filename;
    }

    unsigned Stats::size()const {
        return m_numCount;
    }

    std::ostream& Stats::view(std::ostream& ostr)const {
        unsigned i, count = 0;
        if (*this) {
            ostr << m_filename << endl;
            ostr.width(strLen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl << endl;
            for (i = 0; i < m_numCount; i++) {
                ostr.fill(' ');
                ostr.width(m_columnWidth);
                ostr.setf(ios::fixed);
                ostr.precision(m_precision);
                ostr << m_numbers[i];
                count++;
                if (count == m_noOfColumns) {
                    ostr << endl;
                    count = 0;
                }
            }
            if (count % m_noOfColumns != 0) {
                ostr << endl;
            }
            ostr << "Total of " << m_numCount << " listed!" << endl;
        }
        return ostr;
    }

    std::istream& Stats::getFile(std::istream& istr) {
        string fname;
        istr >> fname;
        setFilename(fname.c_str());
        setNoOfnumCount();
        load();
        return istr;
    }

    double& Stats::operator[](unsigned idx) {
        if (*this) {
            if (idx > m_numCount - 1) {
                idx -= (m_numCount);
            }
            return m_numbers[idx].m_value;
        }
        else {
            dummy = 0.00;
            return dummy;
        }
    }

    double Stats::operator[](unsigned idx)const {
        double value;
        if (*this) {
            if (idx > m_numCount - 1) {
                idx -= (m_numCount);
            }
            value = m_numbers[idx];
        }
        else {
            value = 0.00;
        }
        return value;
    }

    Stats::operator bool()const {
        bool flag = false;
        if (m_numbers != nullptr && m_filename != nullptr && m_numCount != 0 ) {
            flag = true;
        }
        return flag;
    }

    void Stats::sort(bool ascending) {
        unsigned int i, j;
        double temp;
        if (*this) {
            if (ascending) {
                for (i = m_numCount - 1; i > 0; i--) {
                    for (j = 0; j < i; j++) {
                        if (m_numbers[j] > m_numbers[j + 1]) {
                            temp = m_numbers[j];
                            m_numbers[j] = m_numbers[j + 1];
                            m_numbers[j + 1] = temp;
                        }
                    }
                }
            }
            else {
                for (i = 0; i < m_numCount; i++) {
                    for (j = i + 1; j < m_numCount; j++) {
                        if (m_numbers[i] < m_numbers[j]) {
                            temp = m_numbers[i];
                            m_numbers[i] = m_numbers[j];
                            m_numbers[j] = temp;
                        }
                    }
                }
            }
        }
    }


    unsigned Stats::occurrence(double min, double max, std::ostream& ostr) {
        unsigned int i, count = 0, occ = 0;
        if (*this) {
            ostr << endl;
            for (i = 0; i < m_numCount; i++) {
                if (m_numbers[i] >= min && m_numbers[i] <= max) {
                    ostr.width(m_columnWidth);
                    ostr.setf(ios::fixed);
                    ostr.precision(m_precision);
                    ostr << m_numbers[i];
                    count++;
                    occ++;
                    if (count == m_noOfColumns) {
                        ostr << endl;
                        count = 0;
                    }
                }
            }
            if (count % m_noOfColumns != 0) {
                ostr << endl;
            }
            ostr << "Total of " << occ << " numbers are between " << min << " and " << max << endl;
        }
        return occ;
    }

    const char* Stats::name()const {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const Stats& stat) {
        return stat.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, Stats& stat) {
        return stat.getFile(istr);
    }

}