#include <iostream>

/*
exception handling:
	destructor:
		terminate() is called when exception is throwed in dtor() and flow exits dtor() 
			exiting dtor is called emit or propagate (to upper layer codes), exception handler won't even be called
			and catch() won't even run
		dtor() will be handled as if it is not throwing any exceptions:
			1. if any exceptions is going to be thrown from dtor() it must be caught and handled in that dtor()
				otherwise terminate() will be called
			2. you never use exceptions in dtor()
		why we need this rule?
			for instance during an exception if dtor() is called and if that dtor() is throwing another exception
			as it is already in stack unwinding process, there is nothing to do, thet is why terminate is called

	terminate() function is called:
		1. due to uncaught exception
		2. if a handler_function(), which has a rethrow statement in it, is called like a normal function by
			mistake (meanly not in its own try-catch block)
		3. when exception is throwed in dtor() and flow exits dtor()
		4.
*/

class Myclass {
public:
	Myclass(){
		std::cout << "Myclass ctor \n";
	}

	~Myclass() {
		std::cout << "Myclass dtor\n";
		throw 1;
	}
};

void my_terminate() {

	std::cout << "my_terminate is called, and it is calling abort\n";
	abort();
}
int main() {

	std::set_terminate(my_terminate);
	try
	{
		Myclass mx;

	}// as this is a block, Myclass dtor will be called here
	catch (int)
	{
		std::cout << "main() exception caught\n";	// you won't see this as it won't run
	}

}