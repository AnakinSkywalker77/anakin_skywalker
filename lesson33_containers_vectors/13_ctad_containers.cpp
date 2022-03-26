#include <iostream>
#include <vector>
#include "nutility.h"
#include <list>

using namespace std;

/*
vectors:
	CTAD: cpp17 class template argument deduction

*/

template <typename T>
class Myclass {
public:
	Myclass(T) {}

};

void foo(int a, int b, int c, int d) {

	cout << " when you want to navigate function parameters : ";
	for (int i : {a, b, c, d}) {		// range based for loop
		cout << i << ' ';
	}
}

int main() {

	Myclass m(12);		// ctad

	pair p{ 23, 5.6 };	//ctad
	pair<int, double> p2{ 23, 5.6 };	// normally we should write like this (before cpp17)

	// ctad in containers:
	vector x{ 1, 4, 5, 6, 7 };	// ctad
	list mylist{ 1, 3, 4, 7, 8 };
	vector myvec{mylist.begin(), mylist.end()};	// vector<iterator>
	vector myvec2(mylist.begin(), mylist.end());	// vector<int>
	tuple t{ 12, 2.3, 45L, 'A' };

	vector v{ 1, 5, 9, 13 };	// vector<int>

	foo(3, 4, 5, 6);
}



