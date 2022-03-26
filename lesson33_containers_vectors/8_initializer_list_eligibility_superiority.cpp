#include <iostream>
#include <initializer_list>
#include <iterator>
#include <vector>
#include <algorithm>
#include "nutility.h"
using namespace std;

/*
vectors:
	initializer_list class:
		very common usage is function's parameters being initializer_list, or containers ctors
		initializer_list has eligibility superiority in function overload resolution

*/

class Student {
public:
	Student(std::string name, std::initializer_list<int> grades) {
	}
};


class Myclass {
public:
	Myclass(initializer_list<int>) {
		cout << "init list\n";
	}
	Myclass(int) {
		cout << "int\n";
	}

};
int main() {

	Student s("ali", { 3, 4, 8 });

	Myclass m1{};
	Myclass m2{12};
	Myclass m3{ 12, 23 };
	Myclass m4(10);


}