#include <iostream>
/*
move ctor:
	if compiler writes move ctor for derived class then base obj will be move constructed as well
	if you provide move ctor for derived class then you are responsible to move base class with CIL
		if you do not provide move ctor in CIL, then default ctor is called automatically !!!

	remember rule of zero!
*/
using namespace std;
class Base {
public:
	Base() {
		cout << "Base default ctor\n";
	}
	Base(const Base&) {
		cout << "Base copy ctor\n";
	}
	Base(Base&&) {
		cout << "Base move ctor\n";
	}
};

class Der : public Base {
public:
	Der() {
		cout << "Der default ctor\n";
	}
	Der(Der&& other) : Base(move(other)) {
	//Der(Der && other) {		// if you do not provide move ctor, base's default ctor will be called
			cout << "Der move ctor\n";
	}
};

int main() {
	Der x;
	Der y = move(x);
}
