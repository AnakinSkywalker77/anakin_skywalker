#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	remember when you define move members but not copy members, compiler deletes copy members

	lambda init capture: cpp14

*/

class A {
public:
	A() = default;
	A(A&&) = default;
	A& operator = (const A&&) = default;
};

// we could capture with move semantics like below:
class Myclass {
public:
	Myclass(A x) : m_ax(move(x)) {}

private:
	A m_ax;
};

int main() {
	A ax;
	// A ay(ax);		// syntax error as copy members are deleted by compiler
	A ay(move(ax));	// this is ok

	//auto f = [m1] {};		// similarly this is a syntax error as it is calling copy ctor

	// so how can I use m1 in code area
	auto f = [&ax] {};		// you can capture by reference

	int x = 5;
	[a = x + 3] { return a + 5; };	// lambda init capture
	// you can even use the same name:
	[x = x + 3] { return x + 5; };	// x's used instead of a are class's data members, x in x + 3 is local

	// so you can use like this and benefit from move semantics
	[ax = move(ax)] { ax; };	// local ax will be  moved from state

}