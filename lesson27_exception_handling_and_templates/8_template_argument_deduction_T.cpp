#include <iostream>
/*
templates: (meta code, or code formula)
	compiler:
		1. does an overall syntax checks on template code
			name lookup for names which are not depended to typename, and checks like "()" ";"
		2. when compiler learns T type it does actualy syntax checks
		3. 

	template argument deduction:
		rules are completely same with auto type deduction
			compiler is trying to find what to put instead of auto, here compiler is trying to find what to put instead of T
		a trick to find type:
			inferring from compiler's error
*/

template <typename T>
void foo(T x)
{
	// the legality of following codes depend on the type of x
	x.foo();
	++x;
	x = 56;
}

template <typename T>
void func(T x)
{
}

// when you hover over the type but IDE does not show type name then you can do following trick to find type:
template <typename T>
class Typeteller;

template <typename T>
void bar(T)
{
	Typeteller<T> y;
}

int func2(int x) {
	return x * x;
}

int main() {
	
	const int x = 5;
	func(x);		// T is int, const drops


	bar(10);	// see compiler error and type name is there !!!
	//  message : see reference to function template instantiation 'void bar<int>(T)' being compiled
	int& r = x;
	int a[5]{};
				// T is:
	bar(x);		// int
	bar(r);		// int
	bar(a);		// int*				// array decay
	bar(func2);	// int(*)(int)		// function to pointer conversion, even though you sent int(int)
	bar("ali");	// const char*		// array decay
}

