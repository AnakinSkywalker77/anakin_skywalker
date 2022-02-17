#include <iostream>
/*
templates:
	template argument deduction:
		function parameters can be any type
*/

template <typename T>
T foo(T x, int y);

template <typename T>
void func(T x, T* p);

template <typename T>
void func2(T x, T&&);


void func3(int&);	// must be called with L value expr
void func4(int&&);	// must be called with R value expr
// but unlike normal functions, func5() function has universal reference as you can call with const, or non const; R or L value
// this is used in move semantics (we have already studied) and perfect forwarding (we will study)
template <typename T>
void func5(T&&);

int main() {

	int x = 10;
	func(3, &x);		// ok

	func2(10, 20);		// ok, T is int 
	int ival{ 10 };
	func2(ival, ival);	// error int, int&
}