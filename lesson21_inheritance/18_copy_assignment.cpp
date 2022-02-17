#include <iostream>
/*
copy assignment:
	if compiler writes copy assignment operator for derived class, during an assignment it calls
		base copy assignment operator
	if you provide copy assignment operator for derived class then you are responsible to call
		base's copy assignment operator

*/
using namespace std;
class Base {
public:
	Base& operator=(const Base& other) {
		cout << "Base copy assignment\n";
		return *this;
	}
};

class Der : public Base {
public:

	Der& operator=(const Der& other) {
		cout << "Der copy assignment\n";

		// use this
		Base::operator=(other);		// if you do not provide this, base objects won't be assigned

		// do not use but there are some other ways:
		// static_cast<Base&>(*this) = other;
		// static_cast<Base*>(this)->operator=(other);

		// operator=(other);		// wrong, causes recursive call
		// *this = (other);			// wrong, causes recursive call
		return *this;
	} 
};

int main() {
	Der d1, d2;
	d2 = d1;
}
