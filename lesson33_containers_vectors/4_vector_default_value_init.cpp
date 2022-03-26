#include <iostream>
#include <vector>
#include <list>
#include "date.h"
#include <iterator>

using namespace std;

/*
vectors:
	sequence containers have the same common ctor functions, so they are same for: vector, list, forward_list, deque etc
		default ctor: STL containers can be default initialized
		initializer_list ctor
*/


int main() {

	std::vector<Date> vec;	// default initialization

	cout << "vec.size() : " << vec.size() << '\n';
	cout << "size(vec)  : " << std::size(vec) << '\n';
	cout << "size(vec)  : " << size(vec) << '\n';	// ADL


	cout << "vec.empty() : " << std::boolalpha << vec.empty() << '\n';


	std::vector<Date> vec1{};	// value initialization
	std::vector<Date> vec();	// a function declaration

}