#include <iostream>

/*
exception handling:
	throw exception:	throw expr;
	rethrow statement:	throw;

	rethrow sample
*/
void f3() {
	std::cout << "f3 is called \n";
	throw std::out_of_range{"value is out of range"};
	std::cout << "f3 this text won't be seen on screen !!! \n";
}

void f2() {
	try
	{
		f3();
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << "f2 exception handler caught exception: " << ex.what() << '\n';
		throw;	// rethrowing throwing the same exception object sent from f3 !!!

		// throw ex;	// this is not rethrowing, this is throwing a copy of the exception
		std::cout << "f2 this text won't be seen on screen either !!! \n";
	}
}

int main() {
	try
	{
		f2();
	}
	catch (const std::exception& ex)
	{
		std::cout << "main exception handler caught exception: " << ex.what() << '\n';
	}
	std::cout << "main continues...\n";

}