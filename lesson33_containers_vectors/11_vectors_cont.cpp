#include <iostream>
#include <vector>
#include "nutility.h"

using namespace std;

/*
vectors:
*/

// there are two options when you call following function: cpp17 copy elision, move ctor
vector<int> func() {
	///
	// return vector<int>{1, 2, 34, 5}; // mandatory copy elision, here the object created will be x directly, no move will happen

	vector<int> ivec{1, 2, 3, 4};
	return ivec;	// either move semantics as a temp object is returned or NRVO named return value optimisation will be done
}

int main() {
	
	auto x = func();


}