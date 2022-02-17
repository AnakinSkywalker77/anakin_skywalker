#include <iostream>
/*
derived object can be used as a base object:
	there is implicit conversion from derived object to base object

improper inheritance: if you use public inheritance to only use base class's some of its public interface
	you must not use public inheritance to use only some of the base class's public interface,
	all or nothing!
		class Car{public: void run(); void start(); void open_sunroof();};
		if you want Fiat class derive from Car but without open_sunroof() function,
		you must not use inheritance, you can use composition

multiple inheritance: if you derive a class from more than one base class
*/


class Base {
};

class Der : public Base {
};

// multi - level inheritance: class hierarchy is the inheritance tree
class Nec : public Der {
};

void foo(Base*);
void func(Base&);

int main() {
	Der myder;
	
	Base* baseptr = &myder;	// upcasting: casting from derived class to base class
	Base& baseref = myder;	// upcasting
	Base mybase = myder;	// (object slicing) is legal but do not use it
}
