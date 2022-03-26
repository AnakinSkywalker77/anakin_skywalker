#include <iostream>
#include <vector>
#include "nutility.h"
#include <list>

using namespace std;

/*
vectors:
	container's begin and end functions gives you an iterator
		cbegin, cend give you const iterator

	vector functions:
		size()
		capacity()
		empty()
		reserve():
			reserves a capacity where compiler won't do reallocation until that size is reached
			it is used when the size is known beforehand and elements are added in a loop
				this way you prevent continues reallocations...
	
	vector element access functions:
		[]:
			if you send an invalid index to [], it is undefined behaviour, no exception is throwed
		at()
			at() function does same thing with [], but throws exception
		so use at() during debug version and once it is ready then at release version use [] for code efficiency


*/

int main() {
	
	vector<string> svec;
	svec.reserve(2000);
	cout << "svec.capacity(): " << svec.capacity() <<'\n';
	cout << "svec.size(): " << svec.size() << '\n';

	svec.assign(10000, "ali");
	cout << "svec.capacity(): " << svec.capacity() << '\n';
	cout << "svec.size(): " << svec.size() << '\n';

	cout << "----------[]----------\n";

	vector<string> svec2{"ali", "murat", "hasan", "zeynep", "esma"};
	cout << svec2[2] <<'\n';
	svec2[4] += "can";		// svec2[4] is a string, it overloads += operator
	cout << svec2[4] << '\n';
	cout << svec2[4].size() << '\n';

	cout << "--------------------\n";
	for (size_t i{}; i<svec2.size(); ++i)
		cout<<svec2[i] << '\n';		// svec.operator[](i)

	cout << "---------svec2[6]-----------\n";
	try
	{
		// cout << svec2[6] << '\n';	// UB, and does not throw exception
	}
	catch (const std::exception& ex)
	{
		cout << "exception is caught " << ex.what() << '\n';
	}

	cout << "---------svec2.at(6)-----------\n";
	try
	{
		cout << svec2.at(6) << '\n';	// throws exception
	}
	catch (const std::exception& ex)
	{
		cout << "exception is caught " << ex.what() << '\n';
	}

}