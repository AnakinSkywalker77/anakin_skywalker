#include <iostream>

/*
exception handling:
	noexcept operator: unevaluated context, compile time operator like sizeof
		in derived classes noexcept function in base class must be noexcept as well:
			promise no less, require no more
		noexcept cannot be used to overload a function
		in function pointers, noexcept is part of its type
*/

class Base {
public:
	virtual void func()noexcept;

	void foo()noexcept;
	void foo();				// syntax error

};

class Der : public Base {
public:
	void func()noexcept override;
};

void func(Base& r) {
	r.func();
}


void func()noexcept;
void foo();

int main() {
	Base b;
	func(b);

	void (*fp1)()noexcept = func;
	void (*fp2)()noexcept = foo;
}