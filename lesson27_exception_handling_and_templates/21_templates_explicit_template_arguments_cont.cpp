#include <iostream>
#include <string>
#include <memory>
/*
templates:
	explicit template arguments
		why we use them?
			1. when compiler cannot deduce (like in make_unique or make_shared)
			2. when you want a different type than deduced type
*/

template <typename R, typename T, typename U>
R sum(T t, U u) {
	return t + u;		// compiler cannot deduce R type, so you can provide explicitly
}


// or we could do it like this:
template <typename T, typename U>
auto sum2(T t, U u) {
	return t + u;
}

template <typename T, typename U>
auto sum3(T t, U u) -> decltype(t * u)		// t and u are in scope can be seen, if we put decltype instead of auto it won't work
{
}


int main() {

	auto x = sum<int>(12, 'A');
	auto y = sum<double>(1.2, 23);

	sum2(1.2, 12);		// return type will be double
	sum2(1u, 12);		// return type will be unsigned int
}
