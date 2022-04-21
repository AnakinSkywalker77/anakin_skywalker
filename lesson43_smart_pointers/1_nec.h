#pragma once

// modern implementation:
#include <memory>

// normal usage:
//#include "date.h"
//#include "person.h"
//#include <string>
using namespace std;


class Ali;
class Veli;
class Nec {
public:
	// classic pimpl:
	Nec();
	// ~Nec(); // modern implementation: only having declaration causes syntax error explained in main.cpp

	// modern implementation: syntax error explained in main.cpp, you must only declare here and then default it in cpp
	// ~Nec() = default;
	~Nec();

	void nfoo();
	void nfunc();

private:
	// classic pimpl:
	// when you include this header in your client code, main.cpp it compiles successfully as pointer's size is not depended on the pointer type
	struct Pimpl;		// this is an incomplete type, a forward declaration
	// Pimpl* mp;			// this is called opaque pointer
	unique_ptr<Pimpl> mp; // modern implementation:
	// parameters and return value can be incomplete type, you can forward declare them, do not have to include their header files
	Veli foo(Ali);

	// normal usage:
	//string m_str;
	//Date m_date;
	//Person m_person;
};