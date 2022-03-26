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
	vector's addition functions:
		push_back():	note vector does not have push_front() function!!!
			there are two push back functions L value and R value, one copies, other moves
		insert(location, element(s)):
			if you want to add an elemen into a location
*/

int main() {

	vector<string> svec;
	rfill(svec, 5, rname);
	print(svec);

	string s{ "jale" };
	svec.push_back(rname());	// push_back()'s string&& will be called
	print(svec);
	svec.push_back(s);			// push_back()'s const string& will be called
	print(svec);

	svec.insert(svec.begin(), "fatih");
	print(svec);
	svec.insert(svec.end(), "fatih");
	print(svec);
	svec.insert(svec.end()-1, "fatih");
	print(svec);

}