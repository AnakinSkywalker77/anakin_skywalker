extern A ax;

/*
if we do not haev a documented guarantee we should be using class A's object neither in B's ctor, nor
	C's instantiation

*/

class B {
public:
	B() {
		ax.foo();
	}

};

class C {

};

C cx = ax.func();