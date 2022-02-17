#include <iostream>
#include <exception>
using namespace std;
/*
exception handling:

	terminate() is defined like :
		typedef void(terminate_handler)();		// in c and cpp
		using terminate_handler = void(*)();	// in cpp11
		terminate_handler set_terminate(terminate_handler);

	if you want terminate() to call abort(), you need to set which function to call by set_terminate()
		by the address of the function
		the return value of set_terminate() is the function addrress of the previously set function
			you can call set_terminate() again to return to the previous settings
*/

void my_terminate() {
	cout << "my_terminate() is called \n";
	exit(EXIT_FAILURE);
}
void f3() {
	cout << "f3 is called \n";
	throw 1;
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
	cout << "abort()'s address: " << abort << '\n';
	// set_terminate(my_terminate);
	auto fp = set_terminate(my_terminate);
	cout << "set_terminate()'s return value: " << fp << '\n';

	cout << "main() is started \n";
	f1();
	cout << "main() is ending \n";
}