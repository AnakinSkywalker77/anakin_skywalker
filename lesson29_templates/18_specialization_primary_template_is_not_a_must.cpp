#include <iostream>
#include <type_traits>

using namespace std;

/*
templates:
	specialization:

	note: to create specialization, function or class template does not have to be defined
		you can do specialization against an incomplete type
		so if you are going to use only specialization, you do not need to define primary template
*/

// forward declaration
template <typename T>
struct Nec;

// explicit:
template<>
struct Nec<int> {
	Nec() {
		cout << "explicit specialization\n";
	}
};

// partial:
template<typename T>
struct Nec<T*> {
	Nec() {
		cout << "partial specialization\n";
	}
};

int main() {
	Nec<int> mynec;
	Nec<int*> mynec2;
}