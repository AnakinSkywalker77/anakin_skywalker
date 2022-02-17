
#include <iostream>

class Base {
public:
	int x, y;
};
// Der class here actually has a Base object inside
class Der : public Base {		// is a inheritance
	int a, b;
};

class HasAClass {
	Base bx;	// has a member of Base
	int a, b;
};

// nested class is something completely different
class NestedClass {
	class InnerClass {
		int x, y;	// these are not the members of the NestedClass
	};
	int a, b;
};

int main() {

	Der myder;
	myder.x = 10;	// valid

	NestedClass nes;
	nes.x = 10;		// error: x is not in NestedClass

	HasAClass has;
	has.x = 10;		// error: x is Base's member not HasAClass's

	std::cout << "sizeof(Base): " << sizeof(Base) << "\n";
	std::cout << "sizeof(Der): " << sizeof(Der) << "\n";
	std::cout << "sizeof(HasAClass): " << sizeof(HasAClass) << "\n";
	std::cout << "sizeof(NestedClass): " << sizeof(NestedClass) << "\n";
}
