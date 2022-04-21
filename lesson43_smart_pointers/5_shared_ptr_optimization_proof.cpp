#include <memory>
#include <iostream>
#include <string>

using namespace std;

/*
smart pointers cont:
	shared_ptr:

*/

// we can override operator new function to see how many times it is called:
void * operator new (std::size_t sz) {

	std::cout << "operator new is called for the size: "<< sz <<"\n";

	if (sz == 0)
		++sz;
	if (void* ptr = std::malloc(sz))
		return ptr;

	throw std::bad_alloc{};
}

class Nec {
	char buf[1024];
};

void foo() {
	cout << "foo function is called\n";
	auto pn = new Nec;
	shared_ptr<Nec> sptr{ pn };
	cout << "\n";
}

void bar() {
	cout << "foo function is called\n";
	auto sptr = make_shared<Nec>();
	cout << "\n";

}

int main() {

	cout << "sizeof(Nec): " << sizeof(Nec) << "\n";

	foo();	// operator new will be called twice once for object second for control block
	bar();	// operator new will be called only once
}