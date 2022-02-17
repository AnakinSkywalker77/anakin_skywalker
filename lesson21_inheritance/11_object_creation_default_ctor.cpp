#include <iostream>
/*
if you define derived class's ctor but do not call any of Base class's ctors,
	compiler always calls Base's default ctor
*/
using namespace std;

class Base {
public:
	Base(int x) {
		cout << "Base(int) ctor: x= " << x << "\n";
	}
	Base(double x) {
		cout << "Base(double) ctor: x= " << x << "\n";
	}
	Base(int x, int y) {
		cout << "Base(int,int) ctor: x= " << x << " y=" << y << "\n";
	}
};

class Der : public Base {
public:
	// for both ctors it is syntax error because even if you do not write anything it is like
	// Der() : Base() and as Base does not have a default ctor, it is syntax error
	Der() {
		cout << "Der() ctor\n";
	}
	Der(int x) {
		cout << "Der() ctor\n";
	}
};

int main() {
	Der  myder;
}
