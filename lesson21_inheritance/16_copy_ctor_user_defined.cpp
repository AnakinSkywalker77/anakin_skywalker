#include <iostream>
/*
copy ctor:
	if you provide copy ctor for derived class then you are responsible to copy base class with CIL
		if you do not provide copy ctor in CIL, then default ctor is called automatically !!!

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
};

class Der : public Base {
public:
	Der() {
		cout << "Der default ctor\n";
	}
	// Der(const Der& other) : Base(other) {
	Der(const Der& other){
		cout << "Der copy ctor\n";
	}
};

int main() {
	Der x;		// first two default ctors are called for this
	Der y = x;	// then base default ctor for this one is called !!!
}
