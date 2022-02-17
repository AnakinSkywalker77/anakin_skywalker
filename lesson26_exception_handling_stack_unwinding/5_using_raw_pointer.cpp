#include <iostream>
#include <memory>

/*
stack unwinding:
	if you do not use smart pointers you could do like this:
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

// a function which can throw an exception...
void foo() {
	throw 1;
}

void func() {

	auto p = new ResourceUser;
	try {
		foo();
	}
	catch (int) {
		std::cout << "exception handler func():, delete resource and rethrow exception \n";
		delete p;
		throw;		// rethrow exception
	}
	delete p;
}
int main() {

	try {
		func();
	}
	catch (int) {
		std::cout << "exception handler main(): exception is caught\n";
	}

	std::cout << "main continues \n";
}

