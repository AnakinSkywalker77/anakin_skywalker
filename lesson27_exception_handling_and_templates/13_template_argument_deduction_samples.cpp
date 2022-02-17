#include <iostream>
/*
templates: (meta code, or code formula)
	template argument deduction:

*/

// function pointer with double parameter, int return type
void foo(int(*)(double)) {
}
int func(double);

template <typename T, typename U>
void bar(T(*)(U))
{
}

int main() {
	// we can call foo like:
	foo(&func);

	// this is type deduction, not like macros
	bar(&func);		// T int, U double

}