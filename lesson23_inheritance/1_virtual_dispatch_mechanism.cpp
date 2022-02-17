#include <iostream>

/*
public, private, protected keywords are related to static types, considered during compile time
	but dynamic polymorphism (virtual dispatch mechanism) is related to runtime

Derived class's virtual override function can be private
	and calling this vfunc from a global foo() by Base ref is not a syntax error as compiler does not
		see the body of that global func
	and during runtime it runs properly calls Der vfunc
*/


using namespace std;
class Base {
public:
	virtual void vfunc() {
		cout << "Base vfunc \n";
	}

};

class Der : public Base {
	virtual void vfunc() {	// even this overridded func() is private it can be called by Base& or Base*
		cout << "Der vfunc \n";
	}
};

// compiler does not see the body of the function, so does not give any errors
void foo(Base& baseref) {
	baseref.vfunc();
}

int main() {
	Der myder;
	foo(myder);		// related to dynamic polymorphism

	myder.vfunc();	// but client codes cannot call func(), it is is syntax error
}