#include <iostream>

/*
exception handling:
	function try block:
		in ctor, how can we catch the exception thrown from the object initialized with CIL?

*/

class Member {
public:
	Member(int x) {
		if (x % 2 == 0)
			throw 1;
	}

};

class Myclass {
public:
	Myclass()try :m(12) {
		/*
		you can not catch the exception like this:
		try
		{
				// because code is not in try block
		}
		catch (int)
		{
			std::cout << "Myclass ctor exception caught";
		}
		*/
	}
	catch (int) {
		std::cout << "function try block exception caught\n";
	}
private:
	Member m;
};

int main() {
	Myclass mx;
}