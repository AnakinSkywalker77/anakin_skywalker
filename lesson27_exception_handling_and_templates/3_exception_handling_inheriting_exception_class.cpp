#include <iostream>
#include <stdexcept>
/*
	throwing exceptions from your custom class:
		what() function:
			exception class has a virtual what() function, and you can override it
*/


class FormatError : public std::exception {
public:
	// if you do not override what() it will print unknown exception whereever you catch an exception from FormatError
	const char* what()const override {
		return "format error !!\n";
	}
private:

};

int main() {

	try {
		throw FormatError{};
	}
	catch (std::exception & ex) {
		std::cout << "main() exception caught: " << ex.what() << "\n";
	}
}