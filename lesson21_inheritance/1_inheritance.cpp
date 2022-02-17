#include <iostream>

/*
inheritance:
	1. code reuse: you can use another class's code without rewriting same codes
	2. is-a relationship:
		new created class is the type of the main class as well, so you can use it as main class whenever necessary
	when used with runtime polymorphism, inheritance becomes very powerful
	inheritance types: public, private, and protected inheritance
		in most languages and mostly public inheritance is used, and general term inheritance refers to public inheritance
		private and protected inheritance are used for some other purposes, not to inherit a class
	the inherited class is called super class, parent class, or base class (we use base class in cpp)
		new class created by inheritance is called sub class, child class, or derived class (we use derived class in cpp)
	base class must be complete type, you cannot inherit from an incomplete type

*/

class Base {
};
// for class if you do not specify any keywords, private inheritance is done by default
class Der : Base {

};

// for struct if you do not specify any keywords, public inheritance is done by default
struct Der : Base {

};
