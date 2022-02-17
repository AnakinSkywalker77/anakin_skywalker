#include <iostream>
/*
templates: (meta code, or code formula)
	template argument deduction:
*/

template <typename T>
class Typeteller;

template <typename T>
void func(T&)			// <--- now we have reference !!! const does not drop, and no array decay
{
	Typeteller<T> y;
}

int foo(int x) {
	return x * x;
}

int main() {

	int x = 5;
	const int y = 10;
	int a[5]{};
	
					// T			func parameter
	func(x);		// int			int&
	func(y);		// const int	const int&
	func(a);		// int[5]		int(&r)[5]
	func("ali");	// const char[4]	const char(&r)[4];
	func(foo);		// int(int)		int(&r)(int)
}

