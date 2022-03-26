#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	capture options:
		[x]			[x, y]		[x, y, z]
		[&x]		[&x, &y]	[&x, &y, &z]
		[&x, y]		[x, &y]
		[=]			[&]
		[=, &x]	: capture all by copy, but x by reference
		[&, x]	: capture all by reference, but y by copy

*/

template<typename F>
void foo(F f) {
	// int x = 10;	// uncomment and check result is same as on lambda definition it is already connected
					// to the local x in main(), never connects to x in foo()
	f();
}

int main() {

	int x =5;
	auto f = [&] {++x; };
	foo(f);
	cout << "x = " << x << "\n";

	// another sample:
	int y = 20;
	auto g = [&y] {++y; };
	y = 40;
	g();	// as data member is a reference to x wherever you call the g(), it will get value at that point
	cout << "y = " << y << "\n";
	y *=2;
	cout << "y = " << y << "\n";


}