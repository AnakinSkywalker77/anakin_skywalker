#include <iostream>

/*
exception handling:

	terminate() function is called:
		1. due to uncaught exception
		2. if a handler_function(), which has a rethrow statement in it, is called like a normal function by
			mistake (meanly not in its own try-catch block)
		3.
		4.

	a sample for 2nd case:
*/

void handle_exception() {

	std::cout << "handle_exception is called\n";
	std::cout << "handle_exception does some stuff\n";
	throw;
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

void my_terminate() {
	std::cout << "my_terminate is calling abort()";
	abort();
}

int main() {

	std::set_terminate(my_terminate);
	handle_exception();
}