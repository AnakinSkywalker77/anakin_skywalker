#include <iostream>
#include <string>
#include<cstring>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
*/

template <typename T>
void foo(T)
{
	cout << "1\n";
}

template <typename T>
void foo(T*)
{
	cout << "2\n";
}

template <>
void foo(int*)
{
	cout << "3\n";
}

int main() {

	int* p{ nullptr };
	foo(p);	
	/*
	3 will be selected because as explained below:
		1 and 2 are added to the function overload resolution and 2 is selected, and then because there is an explicit
			specialization of 2, and it is suitable, that is why 3 is called
		if there is overloading then, first, the template will be selected from function overload resolution and
			after template is selected, then if there is a suitable specialization of selected template, that
				specialization will be chosen

	*/
}