#include <memory>
#include <iostream>

using namespace std;

/*
smart pointers cont:
	aliasing ctor:
		a member function can copy/clone the shared_ptr of the calling object
		but this shared_ptr is also the holder of class's object which is the function caller !!!
			here class needs to have an aliasing ctor idiom/technique
			CRTP: curiously recurring template pattern
			we can inject some behaviours into our child classes by using CRTP
			one usage area: it is an alternative for runtime polymorphism (virtual functions) but this one is done during compile time (statically)
			but CRTP is generally used to provide a function to child classes
			study these most important idioms: pimpl, fast pimpl, type erasure, crtp
*/

template<typename Der>
class Myclass {
public:
	void foo() {
		static_cast<Der*>(this)->func();
	}
};

// creating a class from its own specialization:
class Nec : public Myclass<Nec> {
	//class Nec {
public:
	void func() {
		// function says: I am going to clone the shared_ptr of my callee (which is spnec here)
		// shared_ptr<Nec> x(this);	// this does not work as it "creates" another shared_ptr for the same object, and their ref counts are different
		cout << "Nec::func()\n";
	}
};

// now for Erg class there is no problem but once it's func() is called problem occurs
class Erg : public Myclass<Erg> {

};

int main() {
	//auto spnec = make_shared<Nec>();
	//spnec->func();

	Nec mynec;
	mynec.foo();

	Erg myerg;
	// myerg.foo();

}

