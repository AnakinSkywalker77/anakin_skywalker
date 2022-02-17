#include <iostream>

/*
exception handling:

constructor and exception handling:
	exceptions are mostly constructors' concern as ctors create, initialize objects, giving them proper values
	zombie object:
		for some reasons (like unfullfilled conditions) if ctor() cannot create objects properly (and exception is
			not	alowed and you can't throw an exception), but technically as ctor() is run and objects are
			considered created (but actually there is no object), such objects are called zombie objects,
			(and normally they have a function like usable() to be called before using etc...)
		if exception is allowed, ctor() can throw an exception in this situation and note that dtor() won't be
			called for such zombie objects as object is not created!!!
		by default if ctor() can't do its job, it should throw an exception

*/


class Myclass {
public:
	Myclass(int x ) {
		std::cout << "ctor allocates some resources\n";

		if (x % 2 == 0)
			throw std::invalid_argument{"can't be even"};

		std::cout << "ctor no problem\n";

	}

	~Myclass() {
		std::cout << "dtor is called\n";
		std::cout << "dtor deallocates those resources\n";
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