#include <iostream>
/*
copy ctor:
	if you do not provide derived class's copy ctor
		compiler writes a copy ctor which copy construct base class's object in derived objects
		(just like it does for members)

*/
using namespace std;
class Base {
public:
	Base() = default;
	Base(const Base&) {
		cout << "Base copy ctor";
	}
};

class Der : public Base {

};

int main() {
	Der x;
	Der y = x;
}
