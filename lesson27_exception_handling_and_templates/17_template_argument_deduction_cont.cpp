#include <iostream>
/*
templates:
	template argument deduction:
		template argument deduction will be done when a template function is called within a template function
*/

template <typename T>
void foo(T x);

template <typename T>
void func(T x) {
	foo(&x);		// T in foo is int*
}

// this is not a recursive call, and this type of templates are being used
template <typename T>		// T is template (type) parameter
void bar(T x) {				// x is call parameter
	bar(&x);
}
// note that T and x can be different types when like bar(T& x), bar(T* x) etc

int main() {

	func(10);		// T in func is int

	bar(10);
}