
/*
consteval: cpp20, means all calls must be const expression, will definitely be calculated during compile time

*/

constexpr int foo(int x){
	return x * 5;
}

consteval int func(int x) {
	return x * 5;
}

int main() 
{
	int x = 45;
	foo(x);
	int a[foo(10)];
	func(x);			// must be called with a constant expression
	int a[func(10)];

}
