#include <iostream>
using namespace std;
/*
virtual dtor:
	in a case where derived object is created on heap and used by base pointer, and when that pointer
		is deleted, if base dtor is not virtual only base dtor is called and base object is destroyed.
	to destory derived object properly you have two options:
		1. virtual base dtor to enable virtual dispatch mechanism for dtors
			so that the proper dtor can be called for the object held in base pointer or reference
		2. not using dynamic objects by base pointers or refs
	
	note that normally polymorphic class's dtor should either be public virtual or protected

ctors cannot be virtual !!! syntax error, why? explained in 6_**.cpp

*/
class Base {
public:
	virtual void vfunc() {
		cout << "Base vfunc \n";
	}

// when base dtor is protected then client codes cannot delete a base ptr which is holding a der object
// protected:
	virtual ~Base() {		// virtual base dtor can be defaulted too
	// ~Base() {
			cout << "Base dtor \n";
	}
};

class Der : public Base {
public:
	virtual void vfunc() {
		cout << "Der vfunc \n";
	}
	~Der() {
		cout << "Der dtor \n";
	}
};

int main() {
	
	Base* ptr = new Der;
	// if base dtor is not virtual then: Der myder; Base* ptr = &myder; and no need to delete ptr
	ptr->vfunc();
	delete ptr;		// when base virtual dtor is protected this becomes syntax error
					// so you have to use Der* ptr = new Der;
}
