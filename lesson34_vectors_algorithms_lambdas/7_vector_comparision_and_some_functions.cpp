#include <iostream>
#include <vector>
#include "date.h"
#include "nutility.h"


using namespace std;

/*
vector functions:
	3 way comparision operator
	previously STL's comparision operators were overloaded but now <-> is overloaded:
	you can compare two containers from same type using 6 compare operators:
		<, >, <=, >=, ==, !=
		comparing is done lexicographically

	max_size():		the max number of elements that a container can hold
	get_allocator():	gets the allocator object, which is the 2nd parameter
*/

int main() {

	vector<int> vec1(100'000);
	vector<int> vec2{ 2 };
	cout << boolalpha << (vec1 > vec2) <<'\n';

	string s1{ "su" };
	string s2{ "cumhuriyet" };
	cout << boolalpha << (s1 > s2) <<'\n';

	vector<int> myvec;
	cout << "myvec.max_size(): " << myvec.max_size() << '\n';
	auto a = myvec.get_allocator();
	cout << "typeid(a).name(): " << typeid(a).name() << '\n';

}
