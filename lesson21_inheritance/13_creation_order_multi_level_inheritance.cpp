#include <iostream>
/*
	creation order in multi-level inheritance

	note:
		Car <- BMW <- BMW Coupe
		(Car is indirect base class of BMW Coupe, Car is direct base class of BMW)
		you can call direct inherited ctor only
*/

using namespace std;
class Base {
public:
	Base() {
		cout << "Base() ctor: \n";
	}
	Base(int) {
		cout << "Base(int) ctor: \n";
	}
	~Base() {
		cout << "Base() dtor: \n";
	}
};

class Der : public Base {
public:
	Der() {
		cout << "Der() ctor\n";
	}
	~Der() {
		cout << "Der() dtor\n";
	}
};

class Nec : public Der {
public:
	// note that you cannot call Base(int) ctor here with CIL: Nec() : Base(5) syntax error
	Nec() {
		cout << "Nec() ctor\n";
	}
	~Nec() {
		cout << "Nec() dtor\n";
	}
};

int main() {
	Nec  mynec;

	// additional notes:
	// upcasting is done automatically
	Base* baseptr = &mynec;
	// downcasting is not, you need a keyword to do so
	// Nec* necptr = &mybase;
}
