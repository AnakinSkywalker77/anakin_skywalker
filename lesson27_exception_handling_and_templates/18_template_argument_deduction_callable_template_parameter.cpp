#include <iostream>
/*
templates:
	template argument deduction:
		callable template parameter
*/

template <typename F>
void bar(F f)
{
	f();	// here F can be a function pointer, or a class which overloads operator()
}

template <typename F>
int func(F f)
{
	return f(5);
}

int foo(int x) 
{
	std::cout << "foo is called: " << x << '\n';
	return x * x;
}

// this is called functor class
class Myclass {
public:
	int operator()(int x)const {
		std::cout << "Myclass::operator()(int) \n";
		return x + 5;
	}

};


int main() {

	auto x = func(foo);
	auto y = func(Myclass{});
}