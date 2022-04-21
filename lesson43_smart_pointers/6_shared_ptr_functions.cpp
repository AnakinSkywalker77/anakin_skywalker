#include <memory>
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	shared_ptr:

*/


int main() {

	auto sp1 = make_shared<std::string>("mustafa");

	cout << *sp1 << "\n";
	// we can call member functiuons using following two ways:
	cout << (*sp1).size() << "\n";
	cout << sp1->size() << "\n";

	auto sp2 = make_shared<Person>("necati", "ergin");
	cout << *sp2 << "\n";

	// it has operator bool function:
	auto x = sp1, y = sp1, z = sp1, t = sp1;
	if (sp1) {
		cout << "sp1 is full, has a resource\n";
		cout << "sp1.usecount(): " << sp1.use_count() <<"\n";
	}
	else {
		cout << "sp1 is empty, does not have a resource\n";
	}
	x.reset();	// when you reset x, then x is not going to show sp1 object anymore, so use_count() will decrease
	cout << "sp1.usecount(): " << sp1.use_count() <<"\n";
	y.reset(new string("mustafa"));	// you can reset to a new object, and it will release previous one and start showing new one
	cout << "y.usecount(): " << y.use_count() << "\n";
	cout << "sp1.usecount(): " << sp1.use_count() << "\n";

	shared_ptr<Person> sp3;
	if (sp3) {
		cout << "sp3 is full, has a resource\n";
	}
	else {
		cout << "sp3 is empty, does not have a resource\n";
	}

	// get() gives us the address of the wrapped object:
	auto ps = z.get();

}