#include <iostream>

/*
exception handling:

constructor and exception handling:
	class type data member object:
	for class type data member objects, dtor will be called upon throwing an exception in the class's ctor(),
		but its object won't be destroyed
		note it does not work with raw pointers, you need to use smart pointers..
*/

class Member {
public:
	Member() {
		// std::cout << "Member constructor called\n";
		// throw 1;		// if this exception happens then Member won't be destroyed either
		std::cout << "Member constructed\n";
	}
	~Member() {
		std::cout << "Member destroyed\n";
	}

};

class Myclass {
public:
	Myclass() {
		std::cout << "Myclass ctor \n";
		throw 1;
	}

	~Myclass() {
		std::cout << "Myclass dtor\n";
	}

private:
	Member m;
};

int main() {
	try
	{
		Myclass mx;
	}
	catch (int)
	{
		std::cout << "main() exception is caught\n";
	}
	std::cout << "main() continues...\n";
}