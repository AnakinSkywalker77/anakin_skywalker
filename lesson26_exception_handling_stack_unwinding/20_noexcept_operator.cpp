#include <iostream>

/*
exception handling:
	noexcept operator: unevaluated context, compile time operator like sizeof
		an exception: dtor() is considered noexcept by default
			it is as it is either it is written by compiler or user

*/

class Myclass {
public:
	~Myclass();		// user declared but it is as if declared with noexcept
};

int main() {
	Myclass m;
	constexpr auto a = noexcept(m.~Myclass());	// you can call as it is unevaluated context and it is true
												// even if it is user declared
}

class A {
};

void func(int)noexcept(noexcept(A{}));	// first noexcept specifier, second noexcept operator
