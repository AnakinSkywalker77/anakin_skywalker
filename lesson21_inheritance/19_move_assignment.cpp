#include <iostream>
/*
move assignment:
	if compiler writes move assignment operator for derived class, during an assignment it calls
		base move assignment operator
	if you provide move assignment operator for derived class then you are responsible to call
		base's move assignment operator

*/
using namespace std;
class Base {
public:
	Base& operator=(const Base& other) {
		cout << "Base copy assignment\n";
		return *this;
	}
	Base& operator=(const Base&& other) {
		cout << "Base move assignment\n";
		return *this;
	}
};

class Der : public Base {
public:

	Der& operator=(Der&& other) {
		cout << "Der move assignment\n";
		Base::operator=(move(other));		// if you do not provide this line base object is not moved
		// Base::operator=(other);			// copy assignment is called
		return *this;
	}
};

int main() {
	Der d1, d2;
	// d2 = d1;
	d2 = move(d1);
}
