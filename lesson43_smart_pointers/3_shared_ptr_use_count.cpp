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
	shared_ptr<Person> sp;
	cout << "sp.usecount(): " << sp.use_count() << "\n\n";		// usecount() gives you the count of the shared_ptr objects showing the main object

	auto sptr1 = make_shared<Person>("Selami","Karakelle");
	cout << "sptr1.usecount(): " << sptr1.use_count() << "\n\n";

	auto sptr2 = sptr1;
	cout << "sptr1.usecount(): " << sptr1.use_count() << "\n";
	cout << "sptr1.usecount(): " << sptr1.use_count() << "\n\n";

	sp = sptr1;
	cout << "sp.usecount(): " << sp.use_count() << "\n";
	cout << "sptr1.usecount(): " << sptr1.use_count() << "\n";
	cout << "sptr12.usecount(): " << sptr2.use_count() << "\n\n";

	// all are showing same objects:
	cout << *sp << "\n";
	cout << *sptr1 << "\n";
	cout << *sptr2 << "\n";

}