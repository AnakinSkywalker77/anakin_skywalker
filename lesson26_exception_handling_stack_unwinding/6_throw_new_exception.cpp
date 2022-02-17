#include <iostream>

/*
exception handling:
	throw exception:	throw expr;
	rethrow statement:	throw;
		newbies generally use exception handling like traditional error handling (as if check return value
			and flow to happy or unhappy path)
			but exception handling is completely different, you should not be trying to act right at the exception
				line and try to fix there
		note that exception must be caught by whoever can do smth about the exception, not others
			if you have something to do, do it by catching the exception, and then if others may need to do catch
				it, rethrow it: throw;
			if you don't have anything to do, then do not even catch it (you should not be catching it at all)
		you can do followings when you catch an exception:
			1. handle it (do whatever you need to for that exception) and let the flow continue after catch block
			2. handle it and then terminate()
			3. partially handle exception and rethrow it to the higher layer codes to handle the rest
				you can throw a new exception which is more meaningful to the upper layers, and this is called
					exception translation: throw expr;
				but with rethrow you are rethrowing the exception object itsef, not a copy of it

*/

/*
	throwing a new exception sample:
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
		throw std::runtime_error{"runtime error"};	// throwing a new exception
		std::cout << "f2 this text won't be seen on screen either !!! \n";
	}
}

void f1() {
	try
	{
		f2();
	}
	catch (const std::runtime_error& ex)
	{
		std::cout << "f1 exception handler caught exception: " << ex.what() << '\n';
	}
	std::cout << "f1 this text WILL BE seen on screen !!! \n";
}

int main() {

	f1();
}