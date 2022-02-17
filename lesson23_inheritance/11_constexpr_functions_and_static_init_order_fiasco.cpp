#include <iostream>

/*
	constexpr functions: it depends on the parameters whether const or not
		constexpr function, if called by constant parameters will return constant expression and can be used
			wherever a constant expression is needed (this will be calculated during compile time)
		if called by non-constant parameter it's return value is not constant expression
*/

constexpr int foo(int x) {
	return x * x;
}

int x = foo(10);		// static init only as calling value is constant

/*
	compiler may allocate a memory for y, and static init it
		if y is not used with address like& y, then compiler won't even allocate a  memory for it
		can just use it as constant
*/
constexpr int y = 10;


/*
	sometimes compiler can static init z as func()'s code is seen on that line (even if func is not constexpr)
*/
int func(int x) {
	return x * 5 + 7;
}
int z = foo(3);


/*
	same thing can be valid for class objects
*/
class Myclass {
public:
	constexpr Myclass(int val) : mx{ val } {}
private:
	int mx;
};
Myclass m{ 12 };	// dynamic init won't be done for this global object as Myclass ctor is defined with constexpr
					// so this object does not cause any static init order fiasco problem

/*
options to stay away from static init order fiasco:
	there is no static order init fiasco in following situations:
		1. do not use any globals
		2. all global objects can be immutable and init with constant values
		3. all globals can be mutable but init with constant value
*/
int main() {


}