#include <iostream>
/*
calling base class's ctor by CIL:
	you can use Der(): Base{10} as well with modern cpp
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
	Der() : Base(4.5) {
		cout << "Der() ctor\n";
	}
	Der(int x) : Base(x, x) {
		cout << "Der(int) ctor: x= " << x << "\n";
	}
};

int main() {
	Der myder;
	Der myder2(5);
}
