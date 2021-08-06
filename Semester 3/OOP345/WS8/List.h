#ifndef SDDS_LIST_H
#define SDDS_LIST_H
// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

// Name: YiHsun Lee
// Seneca Student ID: 129713202
// Seneca email: ylee212@myseneca.ca
// Date of completion:2021/July/20
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
    template <typename T>
    class List {
		std::vector<T> list;
	public:
		List() { }
		List(const char* fn) {
			std::ifstream file(fn);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(fn) + std::string(" ***");
            while (file) {
                T e;
                if (e.load(file))
                    list.push_back(T(e));
            }
		}
		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		// Operator+= overload with a smart pointer
        void operator+=(std::unique_ptr<T>& obj){
            list.push_back(*obj);
        }

		// Operator+= overload with a raw pointer
        void operator+=(T* obj){
            list.push_back(*obj);
        }

		void display(std::ostream& os) const {
            os << std::fixed << std::setprecision(2);
            for (auto& e : list)
                e.display(os);
        }
	};

    template<typename T>
    std::ostream& operator<<(std::ostream& os, const List<T>& l) {
		l.display(os);
		return os;
	}
}
#endif
