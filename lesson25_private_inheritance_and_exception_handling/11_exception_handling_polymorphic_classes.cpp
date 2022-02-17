#include <iostream>
#include <exception>
using namespace std;
/*
exception handling polymorphic classes:
	note for catch parameters, there is no conversion, parameter must exactly be same (except polymorphic classes)
	
	in catch() block "is a relationship" is still affective
	
*/

class Base {

};
class Nec : public Base {

};
class Der : public Base {

};
class Sder : public Der {

};

void my_terminate() {
	cout << "my_terminate() is called, and I am calling abort() \n";
	abort();
}
void f3() {
	cout << "f3 is called \n";
	// throw Der{};
	// throw Nec{};
	throw Sder{};
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
	}
	// catch (Der &x) {		// exception handler
	catch (Base& x) {		// exception handler
			cout << "exception caught... catch(Base&) \n";
	}
	cout << "main() continues \n";
}