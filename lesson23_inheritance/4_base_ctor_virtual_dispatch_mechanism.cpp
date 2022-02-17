#include <iostream>
using namespace std;
/*
	virtual dispatch mechanish is not applied for the virtual function calls done
	in the base class ctor !!!

	calling derived class's vfunc in base ctor is a disaster as it's object has not yet been created !!!
	similarly calling derived class's vfunc in base dtor is a disaster as it is already destructed.

why we use virtual dispatch mechanism (runtime polymorphism)?:
	answer: due to following two SOLID principles:
	1. OCP open - closed prinsiple: open for extension, closed for modification:
		means old codes can use new codes, you do not change old codes, you only add new codes
	2. DIP dependency inversion principle:
		high layer codes won't depend on the low layer concrete classes 
		hence their implementations, high layer and low layer codes will depend on abstractions
		high layer codes: codes consumed by users like user interface codes, business logic codes etc
*/


class Base {
public:
	Base() {
		vfunc();		// here derived object has not been constructed yet
						// so derived vfunc cannot even be called
	}
	~Base() {
		vfunc();		// here derived object has already been destructed
						// so derived vfunc cannot even be called
	}
	virtual void vfunc() {
		cout << "Base vfunc\n";
	}
};

class Der : public Base {
public:
	virtual void vfunc()override {
		cout << "Der vfunc \n";
	}
};

int main() {
	Der myder;		// this line first creates the base object per its default ctor
					// to create base object in myder, myder's only necessary parts are created
					// after base object is created completely then ctor() of myder will run and object 
					// will be created
}