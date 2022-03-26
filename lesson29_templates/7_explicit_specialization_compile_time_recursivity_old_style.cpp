#include <iostream>

using namespace std;

/*
templates:
	explicit specialization: or full specialization
		meta programming sample using compile time recursivity

		this sample is about how this compile time recursivity was done before cpp11 (modern cpp) using class
			templates like following

*/

template <int n>
struct Factorial {
	static const int value = n > 1 ? n * Factorial<n - 1>::value : 1;
	/*
	note that here it looks like as if when n is 1, recursivity stops automatically as n>1 is false and value will be 1 and
		it won't continue
	but it is not like that, even if "n * Factorial<n - 1>::value" won't be selected still it runs, and we have	to stop it
	*/

};

// class's explicit specialization is same with function's explicit specialization
template <>
struct Factorial<0>
{
	static const int value = 1;
};

int main()
{
	int a[Factorial<7>::value] = {0};	// see a is an array of 5040 lenght

}