#include <iostream>

/*
exception handling:
	noexcept operator: unevaluated context, compile time operator like sizeof
		noexcept(expr): if expr throws an exception then expr is true otherwise false
		compiler can check the code it is writing and can decide whether it is noexcept or not
			with cpp20 you can write noexcept to ctors etc
		if a function, while it is giving no throw guarantee, if it throws an exception during runtime
			terminate() function will be called and you cannot catch that exception

	terminate() function is called:
		1. due to uncaught exception
		2. if a handler_function(), which has a rethrow statement in it, is called like a normal function by
			mistake (meanly not in its own try-catch block)
		3. when exception is throwed in dtor() and flow exits dtor()
		4. if a function, while it is giving no throw guarantee, if it throws an exception during runtime
*/
class A {
public:
	// A& operator=(const A&); // when you uncomment this one b is false

};

class B {

private:
	A ax;
};


/*
		if a function, while it is giving no throw guarantee, if it throws an exception during runtime
			terminate() function will be called and you cannot catch that exception
*/
void foo() {
	throw 1;
}
void func()noexcept {
	std::cout << "func is called \n";
	foo();
}

int main() {
	B x, y;
	// b is true as A ctor, B ctor are written by compiler noexcept, as well as opeartor=
	constexpr auto b = noexcept(x=y);
	try
	{
		func();
	}
	catch (int)
	{
		std::cout << "main() exception caught\n";		// you cannot catch this exception
	}
}

class Myclass {
public:
	Myclass()noexcept = default;	//cpp20, compiler will obey it
};