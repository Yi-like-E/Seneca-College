// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// Build a list of product with raw pointers
        for(size_t i = 0; i < desc.size(); i++){
            for(size_t j = 0; j < price.size(); j++){
                if(desc[i].code == price[j].code){
                    Product* p = new Product(desc[i].desc, price[j].price);
                    p->validate();
                    priceList+=p;
                    delete p;
                    
                }
            }
        }
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// Build a list of product with smart pointers
        for(size_t i = 0; i < desc.size(); i++){
            for(size_t j = 0; j < price.size(); j++){
                if(desc[i].code == price[j].code){
                    std::unique_ptr<Product> p{new Product(desc[i].desc, price[j].price)};
                    p->validate();
                    priceList+=p;
                }
            }
        }

		return priceList;
	}
}
