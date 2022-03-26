#include <iostream>
#include <vector>
#include "nutility.h"

using namespace std;

/*
vectors:
	vector has cc and move ctor, and when you move a vector to another one, it is moved from state,
		"moved from state" object's state is still valid and vector can be used
		moved from state object's value is not guaranteed, depends on compiler
			they will be like default inited objects with zero size (mostly zero size)
*/

int main() {

	vector<string> vec1{ "ali", "erdem", "ayse" };
	// auto vec2 = vec1;	// copy ctor
	auto vec2 = move(vec1);	// move ctor, vector itself is moved from state
	print(vec1);
	cout << "vec1.size(): " << vec1.size() << '\n';
	print(vec2);


	cout << "moving a vector's element is different than above:\n";
	vector<string> vec3{ "ali", "erdem", "ayse" };
	vector<string> vec4;
	for (size_t i = 0; i < vec3.size(); ++i)
		vec4.push_back(std::move(vec3[i]));	// move ctor, vectpr's elements are moved
		// vec4.push_back(vec3[i]);	// copy ctor
	print(vec3);
	cout << "vec3.size(): " << vec3.size() << '\n';		// even if vec3's elements are moved, it's size is 3
	print(vec4);


	/*
	a good sample:
	following code when used with move has much better performance:

	std::string str;
	std::vector<std::string> svec;

	while (std::cin >> str) {
		// svec.push_back(str); // this one copies
		svec.push_back(std::move(str));	// this one moves, and str can be used again and again
	}

	*/

}