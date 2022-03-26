#include <iostream>
#include <vector>
#include "nutility.h"
#include <list>

using namespace std;

/*
vectors functions:
	front(): gives you the first element for sequence containers 
	back(): gives you the last element for sequence containers 

*/

int main() {

	vector<string> svec{ "ali", "murat", "hasan", "zeynep", "esma" };

	svec.front() += "can";
	svec.back() = "nuriye";
	print(svec);

	cout << "there are const overloads of [], front(), back() function: \n";
	const vector<string> cvec{ "ali", "murat", "hasan", "zeynep", "esma" };
	cout << cvec[3];
	// cvec[3] = "mahmut";	// syntax error as cvec is const
	// cvec.front() += "can"; // syntax error as cvec is const

}