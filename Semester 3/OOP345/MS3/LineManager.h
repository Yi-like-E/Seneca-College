// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_LineManager_hpp
#define SDDS_LineManager_hpp

#include <iostream>
#include <vector>
#include "Workstation.h"
namespace sdds{
class LineManager{
    std::vector<Workstation*> activeLine;
    size_t m_cntCustomerOrder{0};
    Workstation* m_firstStation = nullptr;
public:
    LineManager(){};
    LineManager(const std::string& file, const std::vector<Workstation*>& stations);
    void linkStations();
    bool run(std::ostream& os);
    void display(std::ostream& os) const;
};
}
#endif /* SDDS_LineManager_hpp */
