#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:

	lets pretend we have a member function and we would like to deduce it's parameter from the called value
		we need to make it a template then
	and we can make operator()(){} a template as well

	generalized lambda expression: [](auto x){}
		it is a lambda expression that has a template operator()(){} function
		and it is done by auto type parameter: [](auto x){}
		this is generally used when lambda is used as argument to algorithms

*/
class Myclass {
public:

	//void foo(int x) {
	//}
	template <typename T>
	void foo(T x) {
	}

	// we can write operator()(){} with a template too !!!
	template <typename T>
	void operator()(T x) {
	}

};

int main() {

	Myclass m;
	m.foo(12);	// compiler will write a function foo with int parameter
	m.foo(1.2);	// compiler will write a function foo with double parameter

	// similarly for opeator()(){} compiler will write deduced functions accordingly
	m(12);
	m(1.2);
	m("ali");

	// generalized lambda expression:
	auto f = [](auto x) {return x + 5; };	// hover about auto x and see how parameter is bec
	auto y = f(10);		// y and z's type will be deduced from the function parameter
	auto z = f(1.2);
}