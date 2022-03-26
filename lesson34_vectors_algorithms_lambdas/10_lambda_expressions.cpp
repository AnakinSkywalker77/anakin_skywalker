#include <iostream>
#include <vector>
#include<algorithm>
#include<list>
#include "nutility.h"
#include<iterator>


using namespace std;

/*
lambda expressions:
	as the resulting statement is a function it is also called as lambda function as well
	compiler is defining a local class against the lambda expression and then creating a temporary object of
		that class, and calling its operator()() function
		all of this is done in one statement
	the class created by compiler is called closure type, and the temporary object (PR value expression)
		created is called closure object (or only "closure")
		and you can name that temporary object:
			auto f = [](){return 2;};
			auto f{[](){return 2;}};
			f();	// then you can call it whenever you need
		you can even call that function right away:
			 [](){return 2;}();
			 auto x = [](){return 2;}();	// function is called and returned value is kept in x
			 auto x = [](int x){return x*x}(10);	// x will be 100

	syntax:
										->type		// trailing return type
			[]<typename T>(parameters)	mutable		{code}
										constexpr
										noexcept
		note "->type" is trailing return type

	must have syntax: [](){code}
		the code will be called by the class's operator()(parameters){code}, function call operator's code
			and operator()()const{} is const if you do not specify anything specifically
		{code}, in code area you can use objects with static lifetime
			but you can only pass local objects in the code area with capture_clause, because local objects are
				not visible in the class's operator()(){code}'s code area...
		[] is called lambda introducer
			[capture_clause] the statements written in [] are called capture clause
			you can capture statements in [m_x, m_y, m_z] which are going to be local class's data members
				and class's default ctor will assign values/statements to data members by CIL which sent by
				[capture_clause] on each loop
	note that if lambda expression is not using any parameters, and type names afterwards, the parameter 
		paranthesis, "()" , can be ommited
			[x]{return x*x};

	IIFE idiom: immediately invoked function expression:[x]{return x*x}(); 
	lambda expressions are great alternatives to local functions (which we do not have in c and cpp as you 
		cannot create a function in another one)
		thanks to lambda you are actually using a nested function!!!


*/

int main() {

	cout << [](int x) {return x * x; }(10) << '\n';
	// note that even if you write exactly same lambda expression twice, they have different types:
	cout << typeid([](int x) {return x * x; }).name() << '\n';
	cout << typeid([](int x) {return x * x; }).name() << '\n';

	int n;
	cout << "\n enter a number to square: ";
	cin >> n;
	// using IIFE:
	cout << [n] {return n * n; } (); // we do not need parameters so we omitted parameter paranthesis: ()
	// in this case it is like no return value: void operator()()const{cout << "\nthis is an IIFE too\n";}
	[] {cout << "\nthis is an IIFE too\n"; }();

	// the things you can do with a lambda expression: [](const string& s) {return s.length(); }
	[](const string& s) {return s.length(); }("ali");	// you can call it
	auto f = [](const string& s) {return s.length(); };	// you can name it to call it several times, or
														// to simplify (the complexity of) the code


}