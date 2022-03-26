#include <iostream>
#include <vector>
#include <list>

using namespace std;

/*
vectors:
	vector implementation

*/

// how a vector is implemented:
template <typename T, typename A = std::allocator<T>>
class Vector {

};


int main() {

	// so followings are same:
	vector<int, allocator<int>> ivec1;
	vector<int> ivec2;

	// you can even do:
	vector<vector<vector<int>>> vec;
	vector<list<double>> lvec;
	vector<pair<int, double>> pvec;
	
}


