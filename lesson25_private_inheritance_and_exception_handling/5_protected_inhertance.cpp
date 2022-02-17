#include <iostream>

using namespace std;

/*
protected inheritance:
	the difference from private inheritance is when you do another inhertance from derived class
	if you want 2nd level derived classes to access base class's public functions then use
		protected inheritance not private inheritance

*/

class Base {
public:
	void basefoo();
};

// class Der : Base {
class Der : protected Base {

};

class Sder : Der {
public:
	void func() {
		basefoo();
	}

};