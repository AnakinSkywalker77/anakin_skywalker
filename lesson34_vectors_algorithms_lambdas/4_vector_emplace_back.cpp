#include <iostream>
#include <vector>
#include <string>
#include "date.h"
#include "nutility.h"


using namespace std;

/*
vector functions:
	with modern cpp apart from copying moving is added but:
	.emplace():
		with perfect forwarding mechanism and R value references, to create an object with some parameters
			you can send ctor parameters to emplace() functions and create the object right in the vector
			(this is not creating first and then coptying or moving this is creating right at the
			vector's indexed location)
		previously you had to create the object and use push_back() to add it to vector.

*/

// how perfect forwarding was done? just to remember:
template <typename T>
void func(T&& t) {
	foo(std::forward<T>(t));		// here func perfect forwards t to foo()
}
// using two parameters:
template <typename T, typename U>
void func(T&& t, U&& u) {
	foo(std::forward<T>(t), std::forward<U>(u));
}
// using any number of parameters with variadic template:
template <typename ...Ts>
void func(Ts &&...args) {
	foo(std::forward<Ts>(args)...);
}

int main() {

	vector<Date> dvec;
	rfill(dvec, 5, Date::random);
	print(dvec, "\n");

	// add a new date with 5 May 1987 value
	// dvec.push_back(Date{5, 5, 1987});		// old way
	dvec.emplace_back(Date{ 5, 5, 1987 });		// new way
	print(dvec, "\n");

	// if a name's lenght is 5, add another one with the same name, if 6 remove it
	
}


