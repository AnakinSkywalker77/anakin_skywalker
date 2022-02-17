#include <iostream>

/*
exception handling:

constructor and exception handling:
	beware Myclass dtor() is not called
*/

class Resource {
public:
	Resource() {
		std::cout << "Resource ctor, allocates resources\n";
	}
	~Resource() {
		std::cout << "Resource dtor, return resources\n";
	}

};

class Myclass {
public:
	Myclass(int x ) {
		/*
			if some resources are allocated then it is your responsibilty to deallocate them upon an exception
			but rather than allocating resources yourself, if you create a class object here, even if an exception
			happens in Myclass ctor(), with stack unwinding, Resource's dtor() will be called and resources can be
			deallocated	in Resource's dtor()
		*/
		Resource r;

		if (x % 2 == 0)
			throw std::invalid_argument{"Myclass can't be even"};

		std::cout << "Myclass ctor no problem\n";

	}

	~Myclass() {
		std::cout << "Myclass dtor is called\n";
	}

};

int main() {
	try
	{
		Myclass m(4);
	}
	catch (const std::invalid_argument& ex)
	{
		std::cout << "main() exception is caught\n";
	}
	std::cout << "main() continues...\n";
}