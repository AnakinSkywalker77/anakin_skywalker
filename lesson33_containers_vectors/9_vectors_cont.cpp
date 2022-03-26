#include <iostream>
#include <initializer_list>
#include <iterator>
#include <vector>
#include <algorithm>
#include "nutility.h"
#include "date.h";

using namespace std;

/*
vectors:
	
*/

int main() {

	// vectors, like all sequence containers, have both initializer_list parameter ctor and a size_t parameter ctor
	vector<int> ivec1(12);
	cout << "ivec1.size(): " << ivec1.size() << '\n';
	print(ivec1);

	vector<int> ivec2{ 12 };
	cout << "ivec2.size(): " << ivec2.size() << '\n';
	print(ivec2);

	vector<int> x1;				// default ctor
	vector<int> x2{};			// default ctor
	vector<int> x3{ 1, 2, 4 };	// initializer_list ctor


	vector<int> x4(40);			// size_t parameter ctor
	print(x4);
	vector<int> x5(40, 5);			// size_t, int parameter ctor
	print(x5);

	vector<int> x6{40, 5};			// initializer_list ctor
	print(x6);


	Date dx{ 12, 5, 1987 };
	vector<Date> dvec(5);
	print(dvec, "\n");
	vector<Date> dvec2(5, dx);
	print(dvec2, "\n");

}

