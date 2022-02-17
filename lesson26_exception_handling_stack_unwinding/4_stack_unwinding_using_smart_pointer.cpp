#include <iostream>
#include <memory>

/*
stack unwinding:
	using smart pointers for previous sample
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

	auto uptr = std::make_unique<ResourceUser>();
	// is same with :
	// std::unique_ptr<ResourceUser> uptr = std::make_unique<ResourceUser>();
	/*
		note that here even if "std::make_unique<ResourceUser>();" is holding a dynamic object, uptr is a local
			object and once exception is throwed and caught, it's dtro() will be called, and there the dynamic
			object is destroyed
		so do not hold your dynamic objects in raw pointers !!!
	*/

	throw 1;
}
void f2() {
	auto uptr = std::make_unique<ResourceUser>();
	f3();
}
void f1() {
	auto uptr = std::make_unique<ResourceUser>();
	f2();
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

