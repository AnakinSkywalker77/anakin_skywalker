#include <memory>
#include <iostream>

using namespace std;

/*
smart pointers cont:
	enable_shared_from_this()
*/

class Nec : public enable_shared_from_this<Nec> {
public:
	void func() {
		auto sp = shared_from_this();
		cout << "func sp.use_cout(): " << sp.use_count() << "\n";
	}
};

int main() {

	Nec *pnec = new Nec;
	try
	{
		pnec->func();	// if we do not call with a shared_ptr then this function throws an exception
	}
	catch (const std::exception& ex)
	{
		cout << "exception caught: " << ex.what() << "\n";
	}

}

