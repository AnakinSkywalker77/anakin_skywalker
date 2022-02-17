#include <iostream>
#include <exception>
using namespace std;
/*
exception handling:

	we need to know why this exception has happened
	we can send info to the upper codes in two different ways:
		1. by throwed object's type
			if you want to catch all exceptions throwed from std library
				then you need a catch(const std::exception& ex) as all exceptions are derived from this class
		2. by throwed object's state

	we will be creating our exception handler classes by inheriting from std::exception class
*/

class FileError {

};

class FileReadError : public FileError {

};

class FileWriteError : public FileError {

};

int main() {

	// this error like many others can be handled by FileError& catch block in a polymorphic way
	// throw FileWriteError{};
	string str{ "alican" };
	try {
		auto c = str.at(34);		// out_of_range -> logic_error -> exception
	}
	// catch (const std::out_of_range& ex) {
	// you can catch it by base class:
	catch (const std::exception& ex) {
		cout << "exception caught : " << ex.what() << '\n';
	}
}


