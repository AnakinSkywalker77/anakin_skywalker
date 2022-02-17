#include <iostream>

/*
scope is the programmers point of view, name-lookup is compiler's point of view
	if the name is qualified like used with ->, ., or ::
	der.x; derptr->x; Der::x; first it is searched in Der class, if not found then in Base class

	!!!! Der and Base classes have different scopes
	compiler does followings in order:
		1. name lookup, if found 2nd is done one the found one
		2. context control, whether it can be called properly like number of arguments etc
		3. access control, do we have access to do so?
*/
int x = 10;
class Base {
public:
	void foo(int);
	void func(int, int);
	void anotherfunc(int);
	int x;
};

class Der : public Base {
public:
	void foo(double);  // this is not a function overloading !!!
	void func(int);
	void anotherfunc(double) {
		int x;
		
		// unspecified name x will be searched in {}, then class Der, then Base, and then global namespace
		x = 4;			// local x
		this->x = 10;	// Der::x
		Der::x = 20;	// Der::x
		Base::x = 30;	// Base::x
		::x = 40;		// x in namespace scope (here it is global namespace)

		anotherfunc(10);	// this is a recursive call
	}
	int x;
};

int main() {
	Der myder;
	myder.foo(12);		// Der foo() is called here
	myder.func(12, 12); // syntax error as with name lookup func is searched in Der and found
						// but parameter mismatch!
	myder.Base::func(1, 3); // this is valid
}