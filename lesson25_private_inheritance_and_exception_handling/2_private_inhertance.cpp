
/*
private inheritance:
	in private inheritance, for client codes, there is no is a relationship
		meanly there is no implicit conversion from derived class to base class for client codes
		but there is still is a relationship within derived class's member functions
			and friend functions of derived class; so implicit conversion is still possible for those
*/

class Base {
public:
	void foo();
	void f();
};

class Der : Base {
public:
	void func() {
	}
	// there is still is a relationship within derived class's member functions:
	void bar() {
		Der myder;
		Base* baseptr = &myder;
		Base& baseref = myder;
	}
	friend void neco();
};

// there is still is a relationship for friend functions of derived class
void neco() {
	Der myder;
	Base* baseptr = &myder;
	Base& baseref = myder;
}

int main() {
	Der myder;
	Base* baseptr = &myder;		// no is a relationship
	Base& baseref = myder;		// no is a relationship

}