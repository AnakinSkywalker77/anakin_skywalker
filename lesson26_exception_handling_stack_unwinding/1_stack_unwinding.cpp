#include <iostream>


/*
stack unwinding:
	if a function ends normally, all local objects (automatic lifetime) are going to be destroyed by calling
		their dtors, this is guaranteed and the normal behaviour
	if a function throws an exception and if exception is not caught (where terminate() is called), calling
		local objects' dtors is not guaranteed
	if you catch an exception (and exit a function) program flow continues from exception handler aka catch(){},
		and compiler guarantees that all local objects (automatic lifetime) are going to be destroyed
		by calling their dtors. this is called stack unwinding
	RAII: Resource Acquisition Is Initialization: means object resources are allocated by initialization,
		meanly in ctors(), and returned/destroyed in dtors
	stack unwinding can be done by objects' ctor() and dtor()
*/

class ResourceUser {
public:
	ResourceUser() {
		std::cout << "ctor " << this << " obtained some resources \n";
	}
	~ResourceUser() {
		std::cout << "dtor " << this << " returned resources \n";
	}
private:
	unsigned char smth[1024];
};

void f3() {
	ResourceUser z;
	throw 1; // if you throw exception but do not catch, abort() is called and resources are not returned
}
void f2() {
	ResourceUser y;
	f3();
}
void f1() {
	ResourceUser x;
	f2();
}

int main() {

	// f1();  // if you throw exception but do not catch, abort() is called and resources are not returned

	// when you catch exception, stack unwinding will be done all local objects will be destroyed
	try {
		f1();
	}
	catch (int) {
		std::cout << "exception handler: exception is caught\n";
	}

	std::cout << "main continues \n";
}

