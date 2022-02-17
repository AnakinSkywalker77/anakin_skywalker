#include <iostream>
using namespace std;

/*
	NVI: non-virtual interface
		says make base virtual functions private or protected
			but client (instead of calling virtual functions directly) shall call
			virtual functions by calling non-virtual member functions

	base class's private virtual function can be overriden by derived class, just like other public
		virtual functions. 
	but how can you call this?? by a base public non-virtual function !!!
	this is used very frequently !!!

	but why ???
		so that the base class has control over the called virtual function and can do some checks
		before and after virtual function call (pre-condition and post-condition etc)
			note base class has no control other than this, does not have control in its own virtual
			function asit may not be called at all
				i.e. if it is multithreaded you can use thread lock/unlock etc
*/

class Base {
public:
	void func() {
		// code
		vfunc();
		// code
	}
private:
	virtual void vfunc() {
		// base class neither have control here
		cout << "Base vfunc \n";
	}
};

class Der : public Base{
public:
	virtual void vfunc() {
		// nor here
		cout << "Der vfunc \n";
	}
};

void foo(Base& baseref) {
	// baseref.vfunc();		// this is syntax error as func() in Base is private !!!
	baseref.func();
}

int main() {
	Der myder;
	foo(myder);		// this one runs the virtual dispatch mechanism !!!
	
	Base mybase;
	foo(mybase);	// interesting hah?
}