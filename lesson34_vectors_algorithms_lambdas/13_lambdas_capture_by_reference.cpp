#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	so far our samples were using capture clause which is for copy capture
	but what if I want to alter the local object in the {code} part?
		local object is sent to class and you want to change it in operator()(){code}'s code part
	
	[&] to capture all by reference

*/

// if we do that we would have a reference data member
class nec123_ {
public:
	nec123_(int &x ) :x(x) {
	}
	void operator()()const{
		x = 999;
	}
private:
	int& x;
};

int main() {

	int x = 5;

	// when you use lambda like this, it does not change above local x
	auto f = [x]()mutable {x = 999; };
	f();					// if you do not call f2(), x remains to be 5 :)
	cout << "x = " << x << '\n';

	// but if we try to do with our own class our class will alter it properly:
	x = 5;
	auto f2 = nec123_{ x };
	f2();
	cout << "x = " << x << '\n';

	// to do the same with lambda we need to capture clause with reference:
	x = 5;
	auto f3 = [&x]{x = 999; };	//it does not even need to be mutable as we are not changing data member
	f3();
	cout << "x = " << x << '\n';
	// note that [&x] is not taking the address of x, it is capturing by reference

	// if you want to capture several local objects by reference, there two ways
	int a = 5, b = 5 , c = 5;
	[&a, &b, &c]{cout << a << b << c<<'\n'; ++a; ++b; ++c; }();
	// or
	[&] {cout << a << b << c << '\n'; }(); // [&] capture all by reference 

	// guess what it is going to print?
	int k = 5;
	auto f4 = [&k] {k = 999; };
	cout << "k = " << k << '\n';

}

// note on mutable:
int g = 45;
class Myclass {
public:
	void foo()const {
		*ptr = 34;		// not syntax error as *ptr is not const, but ptr is
		// ptr = &g;	// this is syntax error
		mr = 15;		// similarly this is not syntax error
	}
private:
	int* ptr;
	int& mr;
};