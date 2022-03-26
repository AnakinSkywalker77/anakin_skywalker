#include <iostream>
#include <vector>
#include <list>
#include "nutility.h"
#include "date.h"
#include <string>
#include <algorithm>
#include <set>


using namespace std;

/*
vector functions:
	.assign():
		member function has some overloads which can do the jobs that cannot be done with operator overloading
		like assigning a list to a vector etc, you cannot do with global assign
		has no return value
	
*/

int main() {

	vector<string> svec{"ali", "nur", "deniz", "ferhan"};
	set<string> myset{"albert", "hans", "olga", "richard"};
	print(svec);
	// svec = myset;	// syntax error
	svec.assign(myset.begin(), myset.end());	// range assign
	print(svec);
	svec.assign({ "huri", "nuri", "sami"});		// initializer_list assign
	print(svec);
	svec.assign(10, "recep");					// fill assign
	print(svec);
	 

	// if a name's lenght is 5, add another one with the same name, if 6 remove it
	
}


