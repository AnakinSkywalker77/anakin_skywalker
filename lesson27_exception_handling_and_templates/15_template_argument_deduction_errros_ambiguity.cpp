#include <iostream>
/*
templates:
	template argument deduction:
		sometimes compiler cannot deduce the type of the template argument from parameters
		sometimes ambiguity happens
*/

template <typename T>
T foo();

template <typename T>
void func() {
	T x;
}
template <typename T>
void bar(T x, T y);


int main() {
	
	// compiler cannot deduce the type for followings:
	foo();
	int x = foo();
	func();


	bar(10, 2.0);		//  error C2782: 'void bar(T,T)': template parameter 'T' is ambiguous
	bar<int>(10, 2.0);	// this is ok, narrowing conversion happens
}