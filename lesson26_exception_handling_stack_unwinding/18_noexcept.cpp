#include <iostream>

/*
exception handling:
	exception specification:
		used before modern cpp, not included in modern cpp !!!
	noexcept: handled during compile time
		noexcept keyword is overloaded: it is a specifier, and an operator
	noexcept specifier:
		if used right after function (global or class memeber function) declaration, means no throw guarantee
			if not used it means that function may throw an exception
			it must exist both in declaration and definition
		conditional noexcept:
			in void f()noexcept(constant_expression);
				if constant_expression is true means no throw guarantee, 
					so void f()noexcept(true); is same with void f()noexcept;
				if constant_expression may throw exception,
					void f()noexcept(false); is same with void f();
	noexcept operator: unevaluated context, compile time operator like sizeof
		noexcept(expr): if expr throws an exception then expr is true otherwise false
*/

void func(int)noexcept;
void foo(int); // may throw exception

class Myclass {
public:
	int size()const noexcept;
};

int Myclass::size()const noexcept {
	std::cout << "foo() does not throw exception \n";
	return 0;
}


class Yourclass {

};
/*
during compile time if std::is_nothrow_default_constructible_v<Yourclass> is TRUE it means Yourclass ctor gives
nothrow guarantee, then bar is givin nothrow guarantee
*/
void bar(int)noexcept(std::is_nothrow_default_constructible_v<Yourclass>) {
}


/*
as Neco's default ctor will be written by compiler, compiler can calculate whether it can give noexcept guarantee
	and as there are no members it is noexcept guaranteed by compiler
*/
class Neco {
};

class A {
public:
	A();
};
class B {
private:
	A ax;
};
void foo2(int)noexcept;
int main() {

	/*
		noexcept(foo2(5)) is a constant expression as it is legal to assign it to a constexpr 
		and b's value is decided during compile time
	*/
	constexpr auto a = noexcept(foo2(5));		// a is true as foo2 is noexcept
	constexpr auto b = noexcept(std::cout<<"ali");	// b is false as expression may throw an exception

	constexpr auto nx = noexcept(Neco{});	// true
	constexpr auto bx = noexcept(B{});		// false as we provided A's ctor as it can throw exception, so
											// as B has a data member of A, it can too...
}

