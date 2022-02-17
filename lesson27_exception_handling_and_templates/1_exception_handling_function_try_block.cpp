#include <iostream>
/*
exception handling:
	function try block:
		it is the only way to catch exceptions and it is mainly for ctors (but cpp says you can use it in any function)
		you can use function parameters in catch block, and there can be return statements in catch block as well
			note that if any exception happens during functions' parameter creation, this try-catch can't catch it
			if there is no return statement in catch block when function has a return type, it is undefined behavior
*/

int func(int x)
try {
	throw 1;
}
catch(int ex)
{
	std::cout << "x is accesible here: " << x << '\n';
	// if func has a return type and if you do not return anything here it is UB
	return  ex;			// you can even have a return statement here
}

class Myclass {
public:
	Myclass() {
		throw 1;
	}
	Myclass(const Myclass&) {
		throw 2;
	}
};

void foo(Myclass m)		// following try-catch block cannot catch the exception caused by foo's parameter creation
try
{
}
catch(int){
	std::cout << "foo exception caught\n";
}

int main() {

	func(7);

	foo(Myclass{});		// because there will be exception thrown from parameter creation and we do not catch it, terminate() is called

	// here we are catching the exception:
	
	//try {
	//	foo(Myclass{});
	//}
	//catch (...) {
	//	std::cout << "main() exception caught\n";
	//}
}