#include <iostream>

/*
access control:
	in case of public inheritance; only public interface of the base class is added to derived class's public
		interface and derived class cannot access base class's private interface.
		base class's protected interface is accessible from derived class, but not client codes!!!
	ofc you can use friend to access private members
*/

class Base {
private:
	void foo(int);
	int bx;
protected:
	void func();
public:
};

class Der : public Base {
	void foo2() {
		foo(10);		// these both are access control errors, not name lookup, names are found
		auto dx = bx;

		func();			// protected members are accesible
	}

};

int main() {
	Der myder;
	myder.func();		// client code access control error of protected Base class
}