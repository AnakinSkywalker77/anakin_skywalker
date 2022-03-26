#include <iostream>
#include <vector>
#include <list>
#include "nutility.h"
#include "date.h"

using namespace std;

/*
vector functions:
	vector's size changing addition, removal functions:
		resize(): changes size
			if you give a size less than current size, it will remove leftover elements

*/


vector <int> foo() {
	return vector<int>{};
}

int main() {

	vector<int> ivec;
	vector<int> x{3, 4, 5, 6};
	ivec = foo();			// move assignment
	ivec = x;				// copy assignment
	ivec = { 30, 40 , 50 };	// initializer_list parameter assignment

	print(x);
	x.resize(20);			// size will be 20 and all will be value inited in this overload
	print(x);

	vector<Date> dvec;
	dvec.resize(5);		// elements will be created by dafault ctor 
	print(dvec, "\n");

	dvec.resize(10, Date(12, 3, 2022));	// this overload takes a value, new elements will be added with new date
	print(dvec, "\n");

	print(x);
	x.resize(2);
	print(x);

	x.resize(100, 1);
	print(x);
	
	// x.resize(0);	// you can remove all, but use clear
	cout << "x.size(): " << x.size() << '\n';
	x.clear();
	cout << "x.size(): " << x.size() << '\n';

}