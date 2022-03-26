#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	if you need to capture several local objects

*/

int main() {

	int a = 5;
	string s{ "ahmet" };
	int* ptr{&a};

	// you can capture above objects in two ways:
	[a, s, ptr]() {cout << "first style\n"; }();
	// [=] means, in lambda, you can use all automatic lifetime object at this point
	[=]() {cout << "second style: "<< s << a << *ptr; }();

}