#include <iostream>
#include "car.h"
using namespace std;

/*
ctors cannot be virtual, why?
	simple answer: for efficiency, and we have virtual constructor idioms instead
*/

void game(Car *p) {
/*
requirement: whichever car is here create a new car from the same type
this is called virtual constructor idioms (or clone idioms): 
	create(): default create is used if aim is to create a brand new one
	clone(): if the new car will be the same one, it is clone, like 5 years old red mercedes
some languages support this by some tools, in cpp we do not have it why?
	because those languages are created for programmers efficiency, fast code writing
	but cpp is created on efficiency: using system resources in the most efficient way
		that is why cpp is widely used in games, fintech, auido-video processing, real time control
			applications etc
cpp's main philosophy: if you do not use, you do not pay
	and UB undefined behavior is not a bug is a FEATURE so that compilers can do better optimization
		compilers rely on that UB won't happen, so they can do very good optimization

if something does not exist in cpp then:
	1. it will bring overhead even if you do not use like overhead
	2. it conflicts with existing tools
	3. otherwise it will be added soon :)
*/

/*
how to create objects dynamically?
	base class will provide two virtual functions, clone and create
*/


	Car* cp1 = p->clone();
	Car* cp2 = p->create();

	cp1->start();
	cp2->start();
	cp1->run();
	cp2->run();
	cp1->stop();
	cp2->stop();

}

int main() {
	for (int i = 0; i < 10; i++) {
		auto p = createRandomCar();
		p->start();		// call start function to see which car is created and then:
		game(p);		// this will clone() and create() two cars from same type and start, run, stop
		delete p;
		(void)getchar();
	}
}