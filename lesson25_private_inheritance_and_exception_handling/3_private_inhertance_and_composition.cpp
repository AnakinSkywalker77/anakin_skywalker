#include <iostream>

using namespace std;

/*
private inheritance:
	why we need it? where it is used?
		private inheritance is an alternative to composition with containment
			like class X has a private class Y type object
			class X is private inherited from class Y
		similarities:
			client codes cannot access Y's member functions, or data members
			for client codes there is no is a relationship
				there is no implicit conversion from derived class to base class
		differences:
			you cannot override base class's virtual functions with composition
				virtual dispatch mechanism can be used with any inheritance types
			is a relationship cannot be used with composition
	so:
		if you are using composition but need to have restricted polymorphism
			restricted polymorphism:
				override the base class's virtual function
				use is a relationship (in derived class's member functions or friend functions)
		then use private inheritance
*/

class Y {
public:
	void yfunc() {
		cout << "yfunc() is called \n";
	}
	virtual void vfoo();
};

// containment:
class X {
public:
	// clients can access by a forwarding function
	//void yfunc() {
	//	yx.yfunc();
	//}

	void vfoo() override;		//  Y's virtual vfoo() can't be overridden
private:
	Y yx;
};

// private inhertance:
class X : Y {
public:
	// clients can access by using declaration (forwarding function is also possible here)
	// using Y::yfunc;
	void vfoo() override;		// Y's virtual vfoo() can be overridden
};

int main() {
	X x;
	x.yfunc();		// client codes cannot access Y's member functions
	Y* y = &x;		// for client codes there is no is a relationship
}