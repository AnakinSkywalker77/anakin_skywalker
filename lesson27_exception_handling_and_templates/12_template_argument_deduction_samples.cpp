#include <iostream>
/*
templates: (meta code, or code formula)
	template argument deduction:
			

*/

template <typename T>
// void func(T x) {		// T is int*
void func(T *x) {		// T is int
	T y = nullptr;		// when T* x this is syntax error
}

template <typename T>
// void foo(T** x){	// T is int
// void foo(T *x) {	// T is int*
void foo(T x){	// T is int**
}


template <typename T, int size>
void f1(T(&)[size]) {
}

template <typename T>
void f2(T &) {
}

int main() {

	int ival{};
	func(&ival);

	int x = 10;
	int* p = &x;
	int** ptr = &p;
	foo(ptr);

	int a[5]={};
	f1(a);		// T is int, size is 5
	f2(a);		// T is int[5]
}
