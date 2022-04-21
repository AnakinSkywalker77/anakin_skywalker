#include <memory>
#include <iostream>

using namespace std;

/*
smart pointers cont:
	enable_shared_from_this()
		can be used in function to clone shared_ptr
*/

// our main problem was actually copying/cloning a shared_ptr of the calling object and it is done using CRTP
class Nec : public enable_shared_from_this<Nec> {
public:
	void func() {
		// function says: I am going to clone the shared_ptr of my callee (which is spnec here)
		// shared_ptr<Nec> x(this);	// this does not work as it "creates" another shared_ptr for the same object, and their ref counts are different
		auto sp = shared_from_this();
		// proof that use count is 2
		cout << "func sp.use_cout(): " << sp.use_count() << "\n";
	}
};


int main() {
	auto spnec = make_shared<Nec>();

	cout << "main spnec.use_cout(): " << spnec.use_count() << "\n";
	spnec->func();
	cout << "main spnec.use_cout(): " << spnec.use_count() << "\n";		// as sp is not copied, when func() call ends it will be destructed...
}

