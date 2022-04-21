#include <memory>
#include <iostream>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	weak_ptr:
		but we have operator bool for shared_ptr, still why we need weak_ptr?
			due to cyclic reference
		cyclic reference:
			for some specific scenarios where we have two shared_ptrs but if they both gives reference to each other's objects, resource won't be deleted
			in this scenario use weak_ptr
*/

struct B;

struct A {
	shared_ptr<B> bptr;
	//weak_ptr<B> bptr; // solution is to change one of the shared_ptr to weak_ptr (note that before using it you need to check !!!)
	~A() {
		cout << "A's dtor\n";
	}
};

struct B {
	shared_ptr<A> aptr;
	~B() {
		cout << "B's dtor\n";
	}
};

int main() {
	shared_ptr<B> pb{new B};
	shared_ptr<A> pa{new A};
	
	pa->bptr = pb;
	pb->aptr = pa;
	// after this point we won't see dtors called due to cyclic reference

		// when shared pointers in class's show each other, they won't be destructed as both have use count of 2
	// for A to be destroyed B must be destroyed first, and vice versa
	cout << pb.use_count()<<"\n";
	cout << pa->bptr.use_count() << "\n";
	cout << pa.use_count()<<"\n";
	cout << pb->aptr.use_count() << "\n";
	(void)getchar();

}

