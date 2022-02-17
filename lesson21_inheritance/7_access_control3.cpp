#include <iostream>
/*
let's pretend you have a request to call Base class's protected function from client codes,
how can you do that?
two ways:
	1. provide a function with the same name in derived class and call base class's function
	2. by adding "using Base::func;" to derived class, and using like this can only be used
		for derived class !!! you cannot do "using Anyclass::func;"
	note 2nd way can be used for function overloading too
*/

class Base {
protected:
	void func(int x) {
		std::cout << "Base::func() x = : " << x << "\n";
	}
public:
	void foo(int x) {
		std::cout << "Base::foo(int) x = : " << x << "\n";
	}
};

class Der : public Base {
public:
	// either this:
	//void func(int x) {
	//	std::cout << "Der::func() x = : " << x << "\n";
	//	Base::func(x);
	//}
	// or:
	using Base::func;


	// function overloading":
	using Base::foo;
	void foo(double x) {
		std::cout << "Der::foo(double) x = : " << x << "\n";
	}
};

int main() {

	Der myder;
	myder.func(4);

	std::cout << "--- main function overloading: ----\n";
	myder.foo(5);
	myder.foo(1.2);
}

// note that if foo() in Der was like foo(int x) then myder.foo(5); would call Der's foo
