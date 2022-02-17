#include <iostream>
#include <exception>
using namespace std;
/*
exception handling polymorphic classes:
	catch blocks are handled from top to bottom
	so if the polymorphic classes are used, catch blocks must be from specific ones to general ones
		otherwise if catch(Base&) comes first, it will catch them all, so it is a logic error

	note that you must use catch by reference semantic like catch(Base& x); not copy semantic catch(Base x)
		if you do catch by copy semantic catch(Base x)
			1. base must be a concrete class and in catch block virtual dispatch mechanism does not work
				because neither reference nor pointer semantic is used!!!
			2. as object will be copied to x, copy ctor will be called and in copy ctor we can have an exception

	even make it const if you are only accessing that object: catch(const Base& x);
*/

class Base {
public:
	virtual const char* what()const {
		return "Base::what() \n";
	};
};
class Der : public Base {
	virtual const char* what()const override {
		return "Der::what() \n";
	};

};

void my_terminate() {
	cout << "my_terminate() is called, and I am calling abort() \n";
	abort();
}
void f3() {
	cout << "f3 is called \n";
	throw Der{};
	// throw Base{};
	cout << "f3 is ended \n";
}
void f2() {
	cout << "f2 is called \n";
	f3();
	cout << "f2 is ended \n";
}

void f1() {
	cout << "f1 is called \n";
	f2();
	cout << "f1 is ended \n";
}

int main() {
	try {
		f1();
	}
	catch (const Base x) {		// exception handler
		// virtual dispatch mechanism does not work here as catch parameter is copy semantic
		cout << "exception caught... catch(Base&) " << x.what() <<'\n';
	}
	cout << "main() continues \n";
}