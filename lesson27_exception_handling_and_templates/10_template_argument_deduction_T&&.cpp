#include <iostream>
/*
templates: (meta code, or code formula)
	template argument deduction:
	func(T &&)
		type of T depends on the calling type's value category:
		R -> T
		L -> T&
	when the parameter's value category is L value then:
		in cpp there is no reference to reference:
			so in some context like template argument deduction or due to using/typedef declarations, if reference to reference
				happens then the type is decided by reference collapsing rules
		reference collapsing rules:
			T&		to		&		==>		T&
			T&		to		&&		==>		T&
			T&&		to		&		==>		T&
			T&&		to		&&		==>		T&&

*/

template <typename T>
class Typeteller;

template <typename T>
void func(T &&param)	// forwarding reference or universal reference, it is mostly used for perfect forwarding
{						// use universal reference name as it is better
	Typeteller<T> y;
}

int foo(int x) {
	return x * x;
}


template <typename T>
void bar(T&& param) {
	T x;
}

int main() {

	int x = 5;
					// T			param
	func(5);		// int			int &&
	func(x);		// int &		int &	reference collapsing

	bar(x);			// as x has L value category so type is T& and int& x; is syntax error, references must be inited
					//  error C2530: 'x': references must be initialized
}

