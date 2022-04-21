#include <memory>
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	shared_ptr:
		using same resource with several shared_ptr pointers

*/

// shared_ptr holds two pointers where unique_ptr holds one
int main() {
	auto up = make_unique<Person>("ahmet", "salihoglu");
	auto sp = make_shared<Person>("ahmet", "salihoglu");

	cout << "size of unique_ptr: " << sizeof(up) << "\n";
	cout << "size of shared_ptr: " << sizeof(sp) << "\n";

	// what is the difference between these two?
	Person* p = new Person("ali", "olmez");					// object is created here
	shared_ptr<Person> sp(p);								// control block is allocated here so compiler cannot do optimization

	auto sp2 = make_shared<Person>("mustafa", "yilmaz");	// here compiler can do optimization 
															// can allocate memory for object and control block at once

}