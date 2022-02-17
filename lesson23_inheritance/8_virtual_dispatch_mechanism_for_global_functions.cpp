#include <iostream>
#include "car.h"
using namespace std;

/*
	virtual dispatch mechanism for a global function
*/

void game(Car& r) {

/*
lets pretend you want to write like "I am a Bmw !" with cout << r << "\n";
you want to enable virtual dispatch mechanism here but
	operator<< function cannot be a class member function, must be a global one
	and virtual dispatch mechanism is not valid for global functions
		how can you do that?
	global function can call a virtual function right?

*/
	
	cout << r << "\n";
	r.start();
	r.run();
	r.stop();

}

int main() {
	for (int i = 0; i < 10; i++)
	{
		auto p = createRandomCar();
		game(*p);
		delete p;
		(void)getchar();
	}
}