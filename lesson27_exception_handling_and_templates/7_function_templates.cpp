#include <iostream>
/*
templates: (meta code, or code formula)
	function templates:
		you can only declare or define function or class templates

*/

// a function template declaration:
template <typename T>
void func(T);


// a function definition:
template <typename T>
void foo(T x)
{
	//
}


int main() {

	foo(10);		// template argument deduction
	func<int>(10);	// explicit template argument
}