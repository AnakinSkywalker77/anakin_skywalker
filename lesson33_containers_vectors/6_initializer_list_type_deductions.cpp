#include <iostream>
#include <vector>
#include "nutility.h"
#include <initializer_list>

using namespace std;

/*
vectors:
	initializer_list class:
		generally we use it with brace initialization {} and then get the benefits type deduction
		all its elements must be the of same type

*/

int main() {

	// initializer_list type deductions:
	auto x = { 1, 2, 3, 4, 5 };		// see auto's type, type deduction
	// auto x2 = { 1, 2, 3.3, 4, 5 };	// syntax error
	auto y = { 'A', 'B', 'C', 'D', };
	// auto y2 = { 'A', 'B', 'C', 65, };	// syntax error

	auto z1{12};				// z1 int
	auto z2 = { 12 };			// z2 initializer_list<int>
	auto z1{ 12, 13, 13 };		// syntax error

}