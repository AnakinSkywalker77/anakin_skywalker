#include <iostream>
#include <vector>

/*
containers:
	container types:
		sequence containers have an indexed location
			addition/removal is done by an index (location)
		associative containers have a value related location
			addition/removal is done by value (by comparing), you cannot decide location, container itself does
		unordered associative containers
	
	common properties for all containers:
		containers are class templates, and compiler is writing their codes during compile time
		containers have public interfaces so that we can use them
		containers are not related to OOP's runtime polymorphism
			polymorphism is used statically done during compile time (compile time polymorphism)
		as they are templates, if you do not call a member function, it's code is not written which is an advantage
		have a complexity O(n) guarantee
		supports exception handling guarantee
		sometimes you can do the same work by either a member function or a global function
			in those situations, always use member function for better performance
		
	containers work with value semantics:
		ther are value semantics and reference semantic, hence value type and reference type
		value semantics:
			value type: after assigning an object to another from the same type, if they do not affect each other,
				they have independed value type/semantics
		reference semantics:
			reference type: after assigning an object to another from the same type, if they can be used for one another,
				they change the same object
		vec.push_back(x);
			it does not push x to vec, pushes a copy of x into vec
		when a container is destroyed all the objects it is holding are destroyed too (by calling their dtors)
		you cannot create a vector with reference semantics
			so you cannot hold objects in a vector with reference
		vectors can be created with followings:
			pointers (better to use smart pointer objects)
			smart pointers: unique_ptr, shared_ptr
			reference_wrapper objects which are used to hold references (but you cannot hold references directly)
		it was mandatory to have a copy ctor as objects are held by copying them
			but after modern cpp (cpp11), you do not have to have a copy ctor
				you can use move semantics, move ctor
				or copy using push_back
				or with emplace functions: they construct objects in vector by using it's ctors

*/

using namespace std;

class Myclass {};

int main() {


	vector<Myclass&> ivec;	// vectors cannot hold references: error C2528: '_Ptr': pointer to reference is illegal

}