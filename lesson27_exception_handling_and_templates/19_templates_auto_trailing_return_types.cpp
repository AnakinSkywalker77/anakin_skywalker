#include <iostream>
#include <string>
/*
templates:
	function return type can be auto or trailing return type
*/

template <typename T>
auto func(T x) -> decltype(x + 1.3);		// trailing return type

template <typename T>
auto func2(T x) -> T;		// trailing return type same with decltype(T);

template <typename T>
auto foo(T x) {
	return x + 5;		// auto return type: compiler will deduce return type by return expression
}

template <typename T>
T sum(T x, T y) {
	return x + y;
}

template <typename T, typename U>
T sum2(T x, U y) {
	return x + y;
}

template <typename R, typename T, typename U>
R sum3(T x, U y) {
	return x + y;
}

using namespace std;
int main() {

	string s1 = "James";
	string s2 = "Jensen";
	auto x = sum(s1, s2);
	// auto x = sum(1.2, 3.4);
	std::cout << "x = " << x << '\n';

	// auto y = sum(10, 3.5);		// ambiguity
	auto y = sum2(10, 3.5);		// now the ambiguity is fixed but there is data loss for return value...
	std::cout << "y = " << y << '\n';
	// you can fix this data loss by explicit template argument in sum3
	auto z = sum3<double>(10, 3.5);		// first parameter will be double, 2nd and 3rd will be deducted
	std::cout << "z = " << z << '\n';



}
