#include <iostream>

/*
stack unwinding:
	a sample where stack unwinding is not done
	if a function throws an exception before destroying some non-local objects (in a function not dtor),
		even if you catch that exception, compiler does not return the resources
	same is valid for objects created/destroyed by new/delete, compiler does not run the codes written after
		exception is throwed, so better to use smart pointers
	stack unwindind does not work for static, globals and class static members as they are not created in stack,
		but of course if you have allocated resources in ctor() of a global object and you are returning them in 
		dtor(), then after main() ends, global object's dtor() will be called !!!
*/

int create_resource() {
	std::cout << "resources are allocated/obtained \n";
	return 5;
}

void destroy_resource() {
	std::cout << "resources are deallocated/destroyed \n";
}

void foo() {
	int handle = create_resource();

	throw 1;	// if you throw exception here even if it is caught, resources wont be deallocated/returned!!!

	destroy_resource();
}

int main() {
	try {
		foo();
	}
	catch (int) {
		std::cout << "exception is caught\n";
	}
	
	std::cout << "main continues \n";
}