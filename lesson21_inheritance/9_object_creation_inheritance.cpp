#include <iostream>
/*
object creation:
	when you careate/destory a derived object, a base object will be created/destroyed as well
	if compiler writes derived class's default ctor, it calls base's default ctor always
	(if compiler can't write due to an error, then it deletes derived class's default ctor)

*/
using namespace std;

class Base {
public:
	// if you only define Base(int) then Der's default ctor will be deleted
	// same thing happens when you put default ctor in private interface
	Base() {
		cout << "Base dafault ctor\n";
	}

	~Base() {
		cout << "Base dtor\n";
	}
};

class Der : public Base {

};

int main() {
	Der myder;
}
