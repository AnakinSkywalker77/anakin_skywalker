#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
#include "nutility.h"
#include<iterator>


using namespace std;

/*
algorithms:
	before continue with the containers we will learn some algorithms
	transform():
		has two overloads
		1. takes a range and sends all elements in the range to a unary functor, and the output
			(return value) of the functor is written to a range, (it does not only copy a range to another)
		2. takes two ranges and sends all corresponding elements to a binary functor and the output
			(return value) of the functor is written to a range. like it sends first elements of the input
			ranges to the functor, and then writes the output to a out range, and then takes second elements
			and so on.
*/

// transform is something like this:
template <typename InIter, typename OutIter, typename Ufunc>
OutIter Transform1(InIter beg, InIter end, OutIter destbeg,  Ufunc f) {

	while (beg != end) {
		*destbeg++ = f(*beg++);
	}
	return destbeg;
}
template <typename InIter1, typename InIter2,  typename OutIter, typename Bifunc>
OutIter Transform2(InIter1 beg1, InIter1 end, InIter2 beg2, OutIter destbeg, Bifunc f) {

	while (beg1 != end) {
		*destbeg++ = f(beg1++, beg2++);
	}
	return destbeg;
}


int square(int x) {
	return x * x;
}

int main() {

	vector<int> ivec{ 1, 4, 5, 7, 9, 12, 8 };
	list<int> ilist(ivec.size());

	// transform(ivec.begin(), ivec.end(), ilist.begin(), square);
	// print(ilist);

	// do same thing with lambda:
	int n;
	cout << "what to multiply: ";
	cin >> n;
	// transform(ivec.begin(), ivec.end(), ilist.begin(), [n](const int x) {return n * x; });
	// print(ilist);

	// source range can be destination range as well !!!
	transform(ivec.begin(), ivec.end(), ivec.begin(), [n](const int x) {return n * x; });
	print(ivec);

	// range types do not have to be same either:
	// lets pretend you have a town name vector and want to get their lenght to a list
	vector<string> svec;
	rfill(svec, 20, rtown);
	print(svec);
	list<size_t> lenlist;
	transform(svec.begin(), svec.end(), back_inserter(lenlist), [](const string& s) {return s.length(); });
	print(lenlist);
}
