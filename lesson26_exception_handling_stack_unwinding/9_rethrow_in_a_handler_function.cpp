#include <iostream>

/*
exception handling:
	rethrow statement does not have to be in the catch block, it can be in a handle_exception() function
		which is called in catch block
*/

void handle_exception() {

	std::cout << "handle_exception is called\n";
	std::cout << "handle_exception does some stuff\n";
	throw;	// rethrowing here is perfectly fine, and compiler handles returning exception's this...
}

void func() {
	try
	{
		throw std::out_of_range{"range error"};
	}
	catch (const std::exception& ex)
	{
		std::cout << "func() exception handler caught exception: " << ex.what() << '\n';
		handle_exception();
	}
}

int main() {
	try
	{
		func();
	}
	catch (const std::out_of_range&)
	{
		std::cout << "main exception handler caught std::out_of_range: " << '\n';
	}
	catch (const std::exception&)
	{
		std::cout << "main exception handler caught std::exception: " << '\n';
	}
	std::cout << "main continues...\n";
}