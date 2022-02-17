#include <iostream>
#include "car.h"
#include <vector>
using namespace std;

/*
runtime polymorphism allows us to keep different types of object (which are implementing the same interface)
	in a single container

	lets pretend you have a document application which includes details about a document
		and document items can be a pictures, paragraphs, a titles etc and lets say they are
		created from base documentItem class by inheritance. and upper layer codes can use
		this documentItem interface to do some operations on any document items
		and later even if some new types are added we do not need to change old codes


here is a vector container sample:
*/

int main() {
	vector<Car*> cvec;

	for (int i = 0; i < 100; i++) {
		cvec.push_back(createRandomCar());
	}

	for (auto p : cvec) {
		cout << *p << '\n';
		p->start();
		p->run();
		p->stop();
		getchar();
	}

	// we have to delete them as we haven't used smart pointers
	for (auto p : cvec) {
		delete p;
	}
}
