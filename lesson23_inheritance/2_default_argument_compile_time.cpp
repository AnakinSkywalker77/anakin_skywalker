#include <iostream>

/*
default argument is related to static type, so it is checked during compile time
	default argument is not related to runtime
*/


using namespace std;
class Base {
public:
	virtual void vfunc(int x = 99) {
		cout << "Base vfunc x= " << x << "\n";
	}

};

class Der : public Base {
public:
	virtual void vfunc(int x = 100) {		// normally yo do not do this, but it is for example
		cout << "Der vfunc  x= " << x << "\n";
	}
};

void foo(Base& baseref) {
	baseref.vfunc();		// move your mouse over func() here and see which default value it is having
						// at compile time
}

int main() {
	Der myder;
	foo(myder);		// output is gonna surprize you !!!
}