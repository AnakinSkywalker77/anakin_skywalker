#include <memory>
#include <iostream>
#include <string>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	shared_ptr:
		using same resource with several shared_ptr pointers
		for raw pointers if they point to the same object, there are two issues:
			1. who is going to delete?
				it is going to use a ref counter, the last pointer will check and delete object if it is the last one
			2.
		shared_ptr used less than unique_ptr, harder to implement, but it does not have additional cost
			btw unique_ptr has only one pointer wrapper to raw pointer, does not add additional cost to raw poionter, and simple to use
		weak_ptr is a helper class for shared_ptr, not a smart pointer itself
		deleter was a template argument in unique_ptr, but
		type erasure idiom/technique (will be handled in advanced cpp):
			there is a type in class implementation but clients cannot see it in class's interface
				(but custom deleter can be used as ctor's parameter)
			this way is used for shared_ptr, in shared_ptr deleter type is type erase, we are not going to use deleter type in our
				class but custom deleter can be used/send as ctor's parameter
		for shared_ptr if we do not send deleter while creating a shared_ptr, default deleter will run only
			shared_ptr is not closed for copying like unique_ptr, so can be copied
		use make_shared and make_unique always if there is no specific reason, do not create object with new dynamically yourself
			shared_ptr holds two pointers where unique_ptr holds one
				shared_ptr holds a pointer for object and other for control block (ref count, weak count, and other data)
			make_shared reduces erorrs and compiler can optimize to make allocation only once for object and control block
		it is not guaranteed to do stack unwinding if any exception occured and not caught,
			so most probably even objects held by shared_ptr won't be deleted
		.reset() destroys/deletes shared_ptr
*/

// a sample to show how shared_ptr uses default and custom deleter
int main() {

	shared_ptr<Person> sp{ new Person {"Anakin", "Skywalker"} };	// will be default deleted

	// custom deleter can be send to ctor as argument: can be any closure type like functor class, lambda, or a real function

	shared_ptr<Person> sp2{ new Person {"Anakin", "Skywalker2"},	// custom deleter
		[](Person* p) {
		cout << "the object at the address of" << p << " is destroyed \n";
		}
	};

	cout << "main ends \n";
}