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
		auto type deduction rules are same with template type deduction rules except this initializer_list
		we can use iterators obtained from initializer_list's begin() and end() as range and send them to any range accepting
			alghoritms
*/

template <typename T>
void func(T t) {
	cout << typeid(T).name() << '\n';
}

void foo(int x ) {
	cout << x << ' ';
}

int main() {
	
	// template type deduction is same for x and y:
	int x = 12;
	auto y = x;
	func(y);
	func(x);

	auto a = { 1, 4, 5, 6 };
	func(a);
	// func({ 2, 4, 5, 8 });		// syntax error can't do type deduction here

	a.begin();
	cout << "a.size(): "  << a.size() << '\n';

	// initializer_list's begin() and end() as range
	vector<int> ivec;
	copy(a.begin(), a.end(), back_inserter(ivec));
	print(ivec);

	cout << "iter: ";
	for (auto iter = a.begin(); iter != a.end(); ++iter)
		cout << *iter << " ";

	// initializer_list is read only
	auto iter = a.begin();
	// *iter = 20;		// syntax error even if you do not define initializer_list as const, it is const

	// use initializer_list in range based for loop:
	cout << "range based for loop: ";
	int x1 = 10, x2 = 40;
	for (auto i : { x1, x2, 4, 5, 7 })
		foo(i);

	// when you copy, only begin and end pointers:
	cout << "\n (a.begin() == b.begin()):  ";
	auto b = a;		// now a and b are showing same memory location
	cout << boolalpha << (a.begin() == b.begin()) << '\n';


}