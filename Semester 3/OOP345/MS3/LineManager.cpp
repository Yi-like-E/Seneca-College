// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/17
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <fstream>
#include <algorithm>
#include "LineManager.h"
using namespace std;
namespace sdds{
LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations){
    ifstream f(file);
    Utilities u;
    if(f){
        string str, current, next;
        bool more;
        size_t pos = 0;
        Workstation* curSt{};
        Workstation* nextSt{};
        Workstation* firstSt{};
        while(getline(f, str)){
            current = u.extractToken(str, pos, more);
            curSt = *find_if(stations.begin(), stations.end(), [&](Workstation* stations){
                return stations->getItemName() == current;
            });
            activeLine.push_back(curSt);
            if(more){
                next = u.extractToken(str, pos, more);
                nextSt = *find_if(stations.begin(), stations.end(), [&](Workstation* stations){
                    return stations->getItemName() == next;
                });
                curSt->setNextStation(nextSt);
            }
        }
        for_each(stations.begin(), stations.end(), [&](Workstation* temp){
            firstSt = *find_if(stations.begin(), stations.end(), [&](Workstation* station){
                return station->getNextStation() == firstSt;
            });
        });
        m_firstStation = firstSt;
    }
    else{
        throw "Invalid file";
    }
    f.close();
    m_cntCustomerOrder = pending.size();
};

void LineManager::linkStations(){
    Workstation* station = m_firstStation;
    vector<Workstation*> reOrderedLine;
    while(station != nullptr){
        reOrderedLine.push_back(station);
        station = station->getNextStation();
    }
    activeLine = reOrderedLine;
};

bool LineManager::run(std::ostream& os){
    static size_t count = 0;
    os << "Line Manager Iteration: " << ++count << endl;
    if(!pending.empty()){
        *m_firstStation += std::move(pending.front());
        pending.pop_front();
    }
    for(auto &station: activeLine){
        station->fill(os);
    }
    for(auto &station: activeLine){
        station->attemptToMoveOrder();
    }
    return completed.size() + incomplete.size() == m_cntCustomerOrder;
};

void LineManager::display(std::ostream& os) const{
    for(auto &i: activeLine){
        i->display(os);
    };
};
}
