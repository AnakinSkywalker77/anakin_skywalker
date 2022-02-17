#include <iostream>
/*
	by public inheritance, public interface of the base class can be used by the derived
		class which is done as if by an object inside the derived class

*/

class Base {
public:
	void foo();
	int mx;
	static int ms;
	class Nested {

	};
};
class Der : public Base {
};

int main() {

	Der myder;
	myder.foo();
	myder.mx = 10;
	Der::ms = 20;

}
