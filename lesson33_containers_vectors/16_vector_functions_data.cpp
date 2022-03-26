#include <iostream>
#include <vector>
#include "nutility.h"
#include <list>

using namespace std;

/*
vector functions:
	as vector elements are guaranteed to be contiguous in memory, we can use them as c arrays too
	to do that we need to have the first member address
	there are several ways to get it:
		data()
			data() is important if you have a c api which needs an array address, and you want to
				send a vector to it like following sample...
*/

// c api which needs an array address
void print_array(const int* p, size_t size) {

	while (size--)
		printf("%d ", *p++);

}

void increment_array(int* p, size_t size) {

	while (size--) {
		++* p;
		++p;
	}

}

int main() {

	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 74, 323 };

	print_array(ivec.data(), ivec.size());	// data()'s const overload will work here

	cout << "\nincremeneted array: ";
	increment_array(ivec.data(), ivec.size());	// data()'s non-const overload will work here
	print(ivec);

	// to do above things vector should not do a reallocation, otherwise you may cause a dangling pointer
	/*
	vector<int> ivec{ 1, 2, 3, 4, 5, 6, 74, 323 };
	int *p = ivec.data();
		// do someting that can cause reallocation
	increment_array(p, ivec.size());	// here p is danglin pointer
	*/

	// there are some other ways to get the first element's address (but always use data())
	auto p1 = &ivec[0];
	auto p2 = &*ivec.begin();
	auto p3 = ivec.data();
	auto p4 = &ivec.front();

}