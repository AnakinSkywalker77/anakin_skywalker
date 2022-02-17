#include <iostream>
#include <exception>


/*
exception handling:

	uncaught exception reasons:
		1. there is no try block
		2. there are try block or blocks, but there is no suitable catch block
		3. global variables and class's static data member of class type,
			if any exception thrown from class ctor it cannot be caught
				even if you put all the main() code in try block you cannot catch as it runs before main()
*/



void foo() {
	throw std::out_of_range{ "error error..." };
}

class Myclass {
public:
	Myclass() {
		// foo();		// the exception thrown here can't be caught if object is global or static data member
	}
};

Myclass m;

int main() {

	try {
		foo();
	}
	catch (const std::logic_error& ex) {
	// catch (const std::runtime_error& ex) {	// you cannot catch with this type of catch block
			std::cout << "exception caught : " << ex.what() << '\n';
	}

}


