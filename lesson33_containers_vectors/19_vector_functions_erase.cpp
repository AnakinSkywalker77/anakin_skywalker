#include <iostream>
#include <vector>
#include <list>
#include "nutility.h"
#include "date.h"
#include <string>
#include <algorithm>

using namespace std;

/*
vector functions:
	vector's removal functions:
		erase(iterator): removes elemet at iterator's location
			erase function returns an iterator which is after the removed one
		erase(iterator_range): removes a range
			this erase function returns an iterator which is after the removed ones too

	note if you send an invalid range to an STL function, that range is not checked, exception is not throwed
		it is UB
*/

int main() {

	vector<string> svec;
	rfill(svec, 10, rname);
	print(svec);
	auto iter = svec.erase(svec.begin() + 3);
	print(svec);
	cout << "*iter: " << *iter << '\n';

	vector<string> svec2;
	rfill(svec2, 10, rname);
	print(svec2);
	auto iter2 = svec2.erase(svec2.begin() + 3, svec2.begin()+6);
	print(svec2);
	cout << "*iter2: " << *iter2 << '\n';

	vector<string> svec3;
	rfill(svec3, 10, rname);
	while (!svec3.empty()) {
		print(svec3);
		svec3.erase(svec3.begin());
	}

}