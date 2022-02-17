#include <iostream>
#include <exception>
using namespace std;
/*
exception handling:
	note for catch parameters, there is no conversion, parameter must exactly be same (except polymorphic classes)
		catch block is called exception handler block as it is handling it
		note try{}, catch(int x){}, and any other catch(doble y){} have different scopes
	what happens when an exception is caught in catch block?
		code in catch block is run and then program flow goes out of all catch blocks and continues from there
			like switch - case - break
*/

void my_terminate() {
	cout << "my_terminate() is called, and I am calling abort() \n";
	// exit(EXIT_FAILURE);
	abort();
}
void f3() {
	cout << "f3 is called \n";
	// throw 1;
	throw 3.2;
	cout << "f3 is ended \n";
}
void f2() {
	cout << "f2 is called \n";
	f3();
	cout << "f2 is ended \n";
}

void f1() {
	cout << "f1 is called \n";
	f2();
	cout << "f1 is ended \n";
}

int main() {
	try {
		f1();
		int a = 30;
	}
	catch (int x) {		// exception handler
		cout << "exception caught... catch(int x), x: " << x << '\n';
		// a = 20;			// syntax error: try and catch blocks have different scopes
		int b = 5;
	}
	catch (double d) {
		cout << "exception caught... catch(double d), d: " << d << '\n';
		// b = 10;			// syntax error: each catch block has different scope
	}

	cout << "main() continues \n";
}