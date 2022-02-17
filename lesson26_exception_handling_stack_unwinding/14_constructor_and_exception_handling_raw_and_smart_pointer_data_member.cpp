#include <iostream>

/*
exception handling:
	constructor and exception handling:
		a sample with raw pointers and smart pointer (commented out)
*/

class Member {
public:
	Member() {
		std::cout << "Member constructed\n";
	}
	~Member() {
		std::cout << "Member destroyed\n";
	}

};

class Myclass {
public:
	Myclass() : p(new Member) {
		std::cout << "Myclass ctor \n";
		throw 1;	// with raw pointer upon exception neither dtors will be called !!!
	}

	~Myclass() {
		std::cout << "Myclass dtor\n";
		delete p;		// note when it smart pointer, you do not need to delete
	}

private:
	Member* p;
	// std::unique_ptr<Member> p;	// if you use smart pointer Member will be destroyed properly with stack unwinding
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