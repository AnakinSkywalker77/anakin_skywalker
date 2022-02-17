#include <iostream>
#include <exception>


/*
exception handling:

	catch all block will catch all exception regardless of their type:
		catch(...){
		}
	other catch block must be before this one...

*/

class NecError {};

void foo() {
	// throw 1;
	// throw NecError{};
	// throw std::out_of_range{"out of range exception"};
	// throw std::logic_error{ "logic error exception" };
	// throw std::exception{"exception"};
	throw "whatever";
}

int main() {

	try {
		foo();
	}
	catch (const std::out_of_range& ex) {
		std::cout << "exception caught : " << ex.what() << '\n';
	}
	catch (const std::logic_error& ex) {
		std::cout << "exception caught : " << ex.what() << '\n';
	}
	catch (const std::exception& ex) {
			std::cout << "exception caught : " << ex.what() << '\n';
	}
	catch (...) {
		std::cout << "exception caught from catch (...) \n";
	}

}


