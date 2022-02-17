#include <iostream>

/*
exception handling:
	rethrow - throw a new exception difference sample
*/

void func() {
	try
	{
		throw std::out_of_range{"range error"};
	}
	catch (const std::exception& ex)
	{
		std::cout << "func() exception handler caught exception: " << ex.what() << '\n';
		// see difference between rethrow and throw a new exception:
		// throw;
		throw ex;
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