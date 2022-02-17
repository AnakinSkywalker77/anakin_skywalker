#include <iostream>

using namespace std;

/*
private inheritance is another way of code reuse but it does not always work
*/


class A {

};

class B {
private:
	A a1, a2;		// you cannot do this with private inheritance
};

class X {

};
class Y {

};
// public inheritance for X, but private inheritance is used for Y !!!
class Z : public X, Y {

};