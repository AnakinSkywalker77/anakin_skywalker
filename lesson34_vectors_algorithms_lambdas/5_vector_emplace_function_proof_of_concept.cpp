#include <iostream>
#include <vector>
#include "date.h"
#include "nutility.h"


using namespace std;

/*
vector functions:
	.emplace() functions

	note all insert functions have a correspoindoing emplace function:
		con.push_back()
			con.emplace_back()
		con.push_front()
			con.emplace_front()
		con.insert()
			con.emplace()


*/

class Myclass {
public:
	Myclass() {
		cout << "default ctor\n";
	}
	Myclass(const Myclass&) {
		cout << "copy ctor\n";
	}
	Myclass(const Myclass&&) {
		cout << "move ctor\n";
	}
	Myclass(int, int, int) {
		cout << "Myclass(int, int, int)\n";
	}
};

int main() {

	vector<Myclass> myvec;
	myvec.reserve(20);
	
	// see first default ctor and then copy ctor are called for this:
	//Myclass m;
	//myvec.push_back(m);

	// see first default ctor and then copy ctor (or move ctor if it exist) are called for this:
	//myvec.push_back(Myclass{});

	// see first Myclass(int, int, int) and then copy ctor (or move ctor if it exist) are called this time: 
	//myvec.push_back(Myclass{ 1, 3, 4 });

	// as myvec hold Myclass objects, emplace_back() calls Myclass's default ctor and creates object in vector
	myvec.emplace_back();

	// see only Myclass(int, int, int) is called: 
	myvec.emplace_back(1, 4, 5);

	// using for any type:
	vector<Date> dvec{ Date{1, 4, 1987} };
	print(dvec, "\n");
	dvec.emplace(dvec.begin(), 5, 5, 1955);
	print(dvec, "\n");

}


