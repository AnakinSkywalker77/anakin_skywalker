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
		pop_back(): removes the last element
		erase(iterator): removes elemet at iterator's location

*/

int main() {
	
	vector<string> svec;
	rfill(svec, 20, rname);
	//while (!svec.empty()) {
	//	print(svec);
	//	(void)getchar();
	//	svec.pop_back();
	//}

	vector<string> svec2;
	rfill(svec2, 20, rname);
	print(svec2);
	svec2.erase(svec2.begin());
	print(svec2);

	cout << "--- svec2.erase(svec2.begin()+1); ---\n";
	svec2.erase(svec2.begin()+1);
	print(svec2);
	
	cout << "--- svec2.erase(next(svec2.begin())); ---\n";
	svec2.erase(next(svec2.begin()));// same with begin+1
	print(svec2);

	cout << "remove the last one: svec2.erase(svec2.end()-1)\n";
	svec2.erase(svec2.end()-1);
	print(svec2);

	cout << "remove the last one: svec2.erase(prev(svec2.end()));\n";
	svec2.erase(prev(svec2.end()));
	print(svec2);

	cout << "remove the first one which matches a value: \n";
	string name;
	cout << "enter the name to be removed: ";
	cin >> name;
	if (auto iter = find(svec2.begin(), svec2.end(), name); iter != svec2.end()) {
		svec2.erase(iter);
		print(svec2);
		cout << "svec2.size(): " << svec2.size() << '\n';
	}else {
		cout << "not found\n";
	}

	cout << "remove the last one which matches a value: \n";
	string name2;
	cout << "enter the name to be removed: ";
	cin >> name2;
	if (auto riter = find(svec2.rbegin(), svec2.rend(), name2); riter != svec2.rend()) {
		svec2.erase(riter.base()-1);
		print(svec2);
		cout << "svec2.size(): " << svec2.size() << '\n';
	}
	else {
		cout << "not found\n";
	}


}