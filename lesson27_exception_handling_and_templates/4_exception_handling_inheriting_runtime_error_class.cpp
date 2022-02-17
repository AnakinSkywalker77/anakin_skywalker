#include <iostream>
#include <stdexcept>
/*
	throwing exceptions from your custom class
		what() function:
			creating custom exception types:
				exception class does not have a default ctor, so you need to write ctor for derived class while inheriting
					from derived class of exception
		there will be "exception handling 2" lessons if we have enough time...
*/


class FormatError : public std::runtime_error {
public:
	/*
	if you do not provide a ctorand call runtime_error's const char* parameter ctor here,
	compiler will delete our ctor due to syntax error. 
	it will be deleted by compiler as runtime_error does not have a default ctor
	*/
	FormatError() : std::runtime_error{ "format error !" }{}
	// or
	FormatError(const char* p) : std::runtime_error{ p }{}
	// or you can use inherited ctor
	// using std::runtime_error::runtime_error;

private:

};

int main() {

	try {
		throw FormatError{};
		// throw FormatError{"format error from other ctor !"};
	}
	catch (std::exception & ex) {
		std::cout << "main() exception caught: " << ex.what() << "\n";
	}
}