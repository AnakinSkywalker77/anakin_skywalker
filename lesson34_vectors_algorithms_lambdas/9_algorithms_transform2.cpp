#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
#include "nutility.h"
#include<iterator>


using namespace std;

/*
algorithms:
	transform():
		transform's 2nd overload sample
*/

string foo(const string &s, const int n) {

	return s + to_string(n);
}

int main() {

	vector<string> svec{ "ali", "mert", "hakan", "selim", "eda" };
	list<int> ilist{ 1, 2, 3, 4, 5 };
	vector<string> dvec;

	transform(svec.begin(), svec.end(), ilist.begin(), back_inserter(dvec), foo);

	print(dvec);


}
