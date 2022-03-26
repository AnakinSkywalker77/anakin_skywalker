#include <iostream>
#include <vector>
#include "nutility.h"
#include <initializer_list>

using namespace std;

/*
vectors:
	initializer_list class:
		lets talk about this a little as we have an initializer_list ctor in vector
		it is different than CIL constructor initializer list
		it holds a raw array and puts list in it and holds start and end
		when you copy an initializer_list, you copy only 8 bytes, start and end pointers :D
			it does not matter what it holds, it's size is only 2 pointer size
		template type deduction is same with auto except initializer_list
		initializer_list has 2 functions size, end, begin
		its members cannot be changed, can be used for const objects, you can only read them
		function's and ctor's parameter can be an initializer_list
*/

void func(std::initializer_list<int> x) {

}

struct Nec {

	char var[1024]{};
};

int main() {

	std::vector<int> vec{ 1, 2, 3, 4, 5 };	// initializer_list

	vec[1] = 10;
	print(vec);

	std::initializer_list<int> x{ 1, 4, 5, 6, 123 };
	print(x);
	cout << "sizeof(x): " << sizeof(x) << "\n\n";	// is always 2*pointerSize

	std::initializer_list<Nec> nec{ Nec{}, Nec{}, Nec{} };
	cout << "sizeof(nec): " << sizeof(nec) << "\n\n";	// is always 2*pointerSize

	std::initializer_list<double> y{ 1.1, 4.2, 5.5, 6.7, 123.132 };
	print(y);


}