#include <iostream>
/*
templates:
	template argument deduction:
*/

// substitution:
template <typename T>
T func(T);		// int func(int)

template <typename T>
T* foo(T*);		// int* foo(int*)

int main() {
	func<int>(10);
	foo<int>(10);
}