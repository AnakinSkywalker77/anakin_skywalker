#include <iostream>

using namespace std;

/*
private inheritance:
	there is anothe reason to use private inheritance over composition:
		some classes do not have any data members
			but when you have an instance of them your class size is increasing by 4 Bytes (1 Byte and alignment)
		so how can we consume that class's functions but not increase our size?
			by private inherting from it !!!
		EBO: Empty Base (class) Optimization

*/


// compilers are allocating 1 Byte of memory so that when an empty class is instantiated to use it as address
class Empty {
public:
	void ef1();
	void ef2();
};

class Myclas {
public:

private:
	Empty e1;
	int x;
};

class Myclas2 : Empty {
public:

private:
	int x;
};

int main() {
	cout << "sizeof(Empty):" << sizeof(Empty) << '\n';		// 1 byte
	cout << "sizeof(Myclas):" << sizeof(Myclas) << '\n';	// 8 bytes due to alignment (padding)
	cout << "sizeof(Myclas):" << sizeof(Myclas2) << '\n';	// 4 bytes due to EBO
}