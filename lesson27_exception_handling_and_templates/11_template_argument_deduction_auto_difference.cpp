#include <iostream>
/*
templates: (meta code, or code formula)
	template argument deduction:
		template argument deduction is same with auto deduction except:
			auto x = {1,2,3,4,5};
			here auto is initializer_list<int>
			

*/

template <typename T>
void func(T x) {
}

int main() {

	// 	it can be tested like following:
	using mytype = int&;
	// mytype& x;			// syntax errror

	int x = 5;
	mytype& y = x;

	using mytype2 = int&&;
	mytype&& z = 10;		// syntax errror

	
	// same rules are applied here:
	// that is why following is not mentioned before. here auto is going to be int as 10 is R value reference, t is int&&
	auto&& t = 10;
	auto&& t = x;		// same rule applies, t is int&

	// difference:
	auto list = { 1, 2, 3, 4, 5 };		// auto is initializer_list<int>
	func({ 1, 2, 3, 4, 5 });			// syntax error, and this is the proof auto is not same with template argument deduction
}
