#include <iostream>
#include <string>
#include <memory>
/*
templates:
	explicit template arguments
		why we use them?
			1. when compiler cannot deduce (like in make_unique or make_shared)
			2. when you want a different type than deduced type
*/

template <typename T, typename U, typename W>
void f(T, U, W) {}


template <typename T>
T foo() {
	///
	return 0;
}

template <typename T>
void func(T x) {
	std::cout << "func() name: " << typeid(T).name() << '\n';
}


using namespace std;
int main() {
	
	f<int, int, int>(1, 1.2, 4L);	// all are going to be int
	f<int, int>(1, 1.2, 4L);		// all but W will be deduced to long

	// foo();		// syntax error, cannot deduce
	foo<double>();	// now explicit, ok


	// each func call will create another function:
	func(1.2);
	func<double>(12.f);
	func<double>(5L);
	func<double>('A');
	//func(12.f);
	//func(5L);
	//func('A');
}
