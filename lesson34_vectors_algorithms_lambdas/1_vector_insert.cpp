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
	insert()
		insert function's return value is the location of the inserted element
		if there many elements added, then returns the first added element's location
	note:
	linked lists are not used that much like before as vectors are outperforming them
		so whenever you need a linked list, try vector as well and check performance then decide

*/

int main() {

	vector<string> svec;
	rfill(svec, 5, rname);
	list<string> mylist{"ela","naz", "ece", "nur"};

	print(svec);
	// different overloads of insert() function:
	svec.insert(svec.begin(), "korhan");
	svec.insert(svec.begin(), { "ali", "can", "efe" });
	svec.insert(svec.begin(), 5, "kerim");
	svec.insert(svec.begin(), mylist.begin(), mylist.end());
	print(svec);


	vector<string> svec2{ "ela","naz", "ece", "nur" };
	print(svec2);
	auto iter = svec2.insert(svec2.begin()+1, "nurullah");
	print(svec2);
	cout << "iter = " << *iter << '\n';
	cout << distance(svec2.begin(), iter) << '\n';
	auto iter2 = svec2.insert(svec2.begin() + 3, { "ali", "can", "efe" });
	print(svec2);
	cout << "iter = " << *iter2 << '\n';
	cout << distance(svec2.begin(), iter2) << '\n';
}


