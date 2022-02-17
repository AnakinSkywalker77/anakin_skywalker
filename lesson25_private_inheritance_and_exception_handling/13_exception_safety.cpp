#include <iostream>
#include <exception>
#include "car.h"
using namespace std;
/*
exception handling:

	note if you do not know what to do with the exception caught
		most probably you should not be catching it at all !!! ahaha
		let the other decider codes, which has the proper information, to catch it and handle

	the code causing exception and the code catching it are in different places in call stack

	exception safety: catching all exceptions (is your code exception safe?)
		upon an exception is caught there are two ways to handle it in catch block:
			1. terminative (ending program)
			2. resumptive (continues if there is no resource leak including memory leak)

*/

void game(Car& car) {
	auto a = dynamic_cast<Volvo&>(car);
}

int main() {

	try {
		Mercedes m;
		game(m);
	}
	// catch (const std::exception& ex) {
	catch (const std::bad_cast& ex) {
		cout << "exception caught : " << ex.what() << '\n';
	}
}


