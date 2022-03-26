#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	capture clause, how it is done?
	
	compiler written operator()(){} is const by default, and cannot alter class's data member, if you need to
		do so, you need to use "mutable"
		mutable removes const
		and if you are going to use mutable keyword, even if lambda does not get any paramater you have to
			provide parameter paranthesis []()mutable{}
	so if you are going to capture some objects by copying them, and need to alter them in the lambda's code
		area, then make it mutable to remove default const

*/

class nec13 {
public:
	nec13(int x) :x(x) {}
	int operator()(int a)const { return x * a; };
private:
	int x;
};

int main() {

	int x = 10;
	auto f = [x](int a) {return x * a; };
	cout << f(20) << '\n';

	// following is completely same with above lambda expression:
	cout << nec13{10}(20) << '\n';

	// here [x] x is local x and it is copied to data member x. but  x in {} is data member of the class
	// auto f2 = [x]() {return ++x; };// hence this is syntax error as compiler written operator()() is const
									// it cannot alter anything...
	// similarly syntax error:
	string s{"necati"};
	// assign is non-const function, and tries to alter data member s in const function operator()(){}
	// [s]{s.assign(5, 'A')};

	// mutable:
	int x = 5;
	[x](int a)mutable {x = 5*a; };

}