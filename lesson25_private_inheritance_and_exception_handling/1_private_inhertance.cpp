
/*
private inheritance:
	base class's public and protected interfaces are added to derived class's private interface
		so client codes cannot access from base class's public interface through derived class
		base class's private interface is still closed to derived class
		there is no difference in private or protected inheritance if derived class is not going to be inherited
*/

class Base {
public:
	void foo();
protected:
	void f();
private:
	void fpriv();
};

// when you change inhertance from private to protected, f() and foo() are going to be accessible from Sder
// class Der : protected Base {
class Der : Base {
public:
	void func() {
		foo();
		f();
		fpriv();	// access error as fpriv() is private
	}
};

class Sder : public Der {
public:

	void fder() {
		foo();		// access error if Base is private inherited by Der
		f();		// same as foo()
	}
};

