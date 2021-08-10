#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

struct ComputerParts {
    string partType;
    string model;
    double price;
    double powerConsumption;
    bool used;
};

int main() {

    vector<ComputerParts> wishList;
    
    // task1
    wishList.push_back({"GPU", "RTX 3080", 1000, 300, false});
    wishList.push_back({"CPU", "RTX 1080", 900, 500, true});
    wishList.push_back({"APX", "CT-R", 1500, 1000, false});
    wishList.push_back({"GPX", "Z 2020", 500, 4450, true});
    
    // task2
    sort(wishList.begin(), wishList.end(), [](ComputerParts& a, ComputerParts& b){
        return a.price < b.price;
    });
    
    cout << "task1 task2 \n";
    for_each(wishList.begin(), wishList.end(), [](ComputerParts& part){
        cout << part.partType << "|" << part.model << "|" << part.price << "|" << part.powerConsumption << "|";
        if (part.used){
            cout << "True" << endl;
        } else{
            cout << "False" << endl;
        }
    });
    
    // task3
    cout << "\ntask3\n";
    sort(wishList.begin(), wishList.end(), [](ComputerParts& a, ComputerParts& b){
        return a.powerConsumption < b.powerConsumption;
    });
    cout << "Most power consumption: " << wishList.back().model << "|" << wishList.back().powerConsumption << endl;
    cout << "Least power consumption: " << wishList.front().model << "|" << wishList.front().powerConsumption << endl;
    
    // task4
    cout << "\ntask4\n";
//    for(auto i = 0; i < wishList.size(); i++){
//        if(wishList[i].used){
//            wishList.erase(wishList.begin()+i);
//        }
//    }
//
//    for_each(wishList.begin(), wishList.end(), [](ComputerParts& part){
//        cout << part.partType << "|" << part.model << "|" << part.price << "|" << part.powerConsumption << "|";
//        if (part.used){
//            cout << "True" << endl;
//        } else{
//            cout << "False" << endl;
//        }
//    });
    
    // task5
    cout << "\ntask5\n";
    auto sum = accumulate(wishList.begin(), wishList.end(), (double)0, [](double init, ComputerParts& a){
        return init + a.price;
    });
    
    auto avg = sum / wishList.size();
    cout << "Average cost: " << avg << endl;
    
    // task6
    cout << "\ntask6\n";
    auto size = wishList.size();
    vector<ComputerParts> newList(size);
    transform(wishList.begin(), wishList.end(), newList.begin(),[](ComputerParts a){
        a.used = true;
        a.price = a.price*0.8;
        return a;
    });
    
    for_each(newList.begin(), newList.end(), [](ComputerParts& part){
        cout << part.partType << "|" << part.model << "|" << part.price << "|" << part.powerConsumption << "|";
        if (part.used){
            cout << "True" << endl;
        } else{
            cout << "False" << endl;
        }
    });
    
    // task7
    cout << "\ntask7\n";
    auto num = count_if(wishList.begin(), wishList.end(), [](ComputerParts a){
        return a.partType == "CPU";
    });
    cout << "Number of CPU: " << num << endl;
    
    // task8
    cout << "\ntask8\n";
    vector<ComputerParts> newWishList;
    newWishList.push_back({"Bed", "Ikea", 2000, 1800, true});
    newWishList.push_back({"Desk", "Structube", 400, 380, false});
    newWishList.push_back({"Soft", "Brick", 3500, 2800, true});
    
    wishList.insert(wishList.end(), newWishList.begin(), newWishList.end());

    
    for_each(wishList.begin(), wishList.end(), [](ComputerParts& part){
        cout << part.partType << "|" << part.model << "|" << part.price << "|" << part.powerConsumption << "|";
        if (part.used){
            cout << "True" << endl;
        } else{
            cout << "False" << endl;
        }
    });
}

