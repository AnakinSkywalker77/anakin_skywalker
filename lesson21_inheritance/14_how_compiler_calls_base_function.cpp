#include <iostream>
/*
	how we can call a base class function with derived object?
	when a non-static member function is called, remember there is a this parameter implicitly passed
		so compiler calls func() with the base object's address which is created in myder object
	this base object in myder object does not have to be at the top of the myder object,
		meanly myder object and included base object do not have the same address

	note: with public inheritance:
	a 2nd or 3rd level derived object can call eevryting it's base class's public interfaces
		
*/

class Base {
public:
	void func() {
		// base members used
	
	}
};

class Der : public Base {


};

int main() {
	Der myder;
	myder.func();
}