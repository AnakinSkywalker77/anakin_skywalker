#include <iostream>
/*
creation order:
first base class's object is created and then derived's class's ctor is run and object is created
if you write derived class's dtor, compiler calls base dtor just before derived's dtor is exiting...
	
	order: (for ctors/dtors always FILO)
		Base ctor, Member ctor, Der ctor, Der dtor, Member dtor, Base dtor
*/
using namespace std;

class Base {
public:
	Base() {
		cout << "Base() ctor: \n";
	}
	~Base() {
		cout << "Base() dtor: \n";
	}
};

class Member {
public:
	Member() {
		cout << "Member() ctor: \n";
	}
	~Member() {
		cout << "Member() dtor: \n";
	}

};

class NextMember {
public:
	NextMember() {
		cout << "NextMember() ctor: \n";
	}
	~NextMember() {
		cout << "NextMember() dtor: \n";
	}

};

class Der : public Base {
public:
	Der() {
		cout << "Der() ctor\n";
	}
	~Der() {
		cout << "Der() dtor\n";
	}
	Member mx;		// members are always created in order of their definition regardless of CIL order
	NextMember nx;
};

int main() {
	Der  myder;
}
