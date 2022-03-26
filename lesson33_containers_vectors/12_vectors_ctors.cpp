#include <iostream>
#include <vector>
#include "nutility.h"
#include <list>

using namespace std;

/*
vectors:
	vectors ctors:
		vector()				default ctor
		vector(const vector&)	copy ctor
		vector(vector&&)		move ctor
		vector(size_t)			size parameter ctor, this is an explicit ctor
		vector(size_t, T)		size and starting value ctor
		vector(start, end)		range ctor
		vector(initializer_list) initializer list ctor

	you can not copy from one container to another container from a different type
		but you can copy a range of any containers to a container with different type
*/

int main() {

	vector<int> ivec{ 2, 5, 6, 7, 8, 9 };
	vector<int> x(ivec.begin(), ivec.begin() + 3);
	print(x);

	// it does not even have to be the same type:
	cout << "copying from an int array to vector: \n";
	int a[]{ 2, 5, 6, 7, 8, 9 };
	vector<int> y(a+1, a+4);
	print(y);

	cout << "copying from a list range to vector: \n";
	std::list<int> ilist{ 3,5,6,7 };
	// std::vector<int> myvec{ mylist };	// you cannot do that
	// std::list<double> dlist{ mylist };	// you cannot do that either
	std::vector<int> ivec2(ilist.begin(), ilist.end());
	print(ivec2);

	cout << "copying from a const char * array to vector: \n";
	// you can even do this:
	const char* p[] = { "bilge", "fatih", "berke", "necati" };
	vector<string> svec(begin(p), end(p));
	print(svec);

	cout << "size_t parameter ctor: \n";
	// vector<int> iivec = 50;	// copy initialization is syntax error as size_t parameter ctor is an explicit ctor
	vector<int> iivec(50);		// now it is fine
	print(iivec);
}



