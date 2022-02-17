#include <iostream>
#include "car.h"
using namespace std;

/*
covariance: variant return type
		prior info: virtual function overriding can be done with a function with same signature and return type
	but:
		if base class's vfuncs have A& or A* return types, derived classes can have B& or B* return types as long
			as B is a child class of A. this is called covariance or variant return type
	
	why we have such a thing?
		because otherwise we had to do a conversion from base ptr to derived ptr which is not exist !!!
		Mercedes* p = bp.travel(); // error C2440: 'initializing': cannot convert from 'Car *' to 'Mercedes *'
			to fix: you had to Mercedes* p = static_cast<Mercedes*>(bp.travel());
	
	so now we can go to car.h and change all clone(), create() function's return type in derived classes

*/

class Person {
public:
	virtual Car* travel();
};

class BusinessPerson : public Person {
public:
	// virtual Car* travel()override;
	virtual Mercedes* travel()override;
};

int main() {
	BusinessPerson bp;
	// Mercedes* p = static_cast<Mercedes*>(bp.travel());
	Mercedes* p = bp.travel();
}