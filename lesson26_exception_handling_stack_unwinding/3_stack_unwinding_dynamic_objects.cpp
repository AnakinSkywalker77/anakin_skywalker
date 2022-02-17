#include <iostream>


/*
stack unwinding:
	if you throw an exception, and if there are some local dynamically created objects, stack unwinding won't be
		done for them as they are not in stack, in HEAP !!!
	for the following example, there are memory and reource leak both!!!

	solution: use smart pointers, they exist for this purpose
		smart pointer classes are not pointers, but they have a pointer interface and they are used to conrtol
			dynamically created objects lifetime
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
	ResourceUser* ptr = new ResourceUser;
	throw 1;
	delete ptr;
}
void f2() {
	ResourceUser* ptr = new ResourceUser;
	f3();
	delete ptr;
}
void f1() {
	ResourceUser* ptr = new ResourceUser;
	f2();
	delete ptr;
}

int main() {

	try {
		f1();
	}
	catch (int) {
		std::cout << "exception handler: exception is caught\n";
	}

	std::cout << "main continues \n";
}

