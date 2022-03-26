#include <iostream>
#include<string>

using namespace std;

/*
lambda expressions:
	syntax:
										->type		// trailing return type
			[]<typename T>(parameters)	mutable		{code}
										constexpr
										noexcept

	noexcept is the guarantee that no exception will be thrown
		noexcept(expression); returns true if expression is noexcept

	trailing return type has the same functionality of functions
		it is used:
			when the return statement type, if deduced, is not the one we wanted
			or if there are more than one return statements which are deduced to different types (it is
				syntax error), so use trailing return type


*/

class Myclass {

public:
	// void operator()() const {};
	void operator()() const noexcept {};
};

// write auto instead of return value, and put return value after ->
auto foo()->double {

}

int main(){

	Myclass m1;
	constexpr auto b =  noexcept(m1());		// uncomment operator()() and see b's result

	// similarly in lambda:
	// auto f = []() {};
	auto f = []()noexcept {};
	constexpr auto a = noexcept(f());

	// trailing return type
	auto f2 = [](int x) { return x + 5.; };	// return type is deduced from x+5 and it is int
	// auto f2 = [](int x) { return x + 5.; };	// return type is deduced from x+5. and it is double
	auto val = f2(10);		// hover on val and see it is int

	// but if we write like this, it won''t be deduced
	auto f3 = [](int x)->double { return x + 5.; };
	auto val = f3(10);

	// auto f4 = [](int x) {
	auto f4 = [](int x)->double {
			if (x > 10)
			return x;
		return x * 1.5;		// syntax error due to ambiguity (if trailing return type is not used)
	};

}