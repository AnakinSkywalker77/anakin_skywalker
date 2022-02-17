#include <iostream>
#include <exception>

/*
exception handling:
	a perfect excample to see the object created by compiler by calling class's copr ctor

*/

class Myclass {
public:

	Myclass() = default;

	Myclass(const Myclass& r) {
		std::cout << "Myclas copy ctor this : " << this << '\n';
		std::cout << "Myclas copy ctor &r : " << &r << '\n';
	}
	~Myclass() {
		std::cout << "Myclas dtor : " << this << '\n';
	}

};

void func() {
	Myclass m;
	std::cout << "func() &m: " << &m << '\n';
	throw m;		// as compiler creates an object from m, it will call copy ctor
}

int main() {
	try
	{
		func();
	}
	catch (const Myclass&)
	{
		std::cout << "exception caught...\n";
	}
	std::cout << "main continues...\n";
}