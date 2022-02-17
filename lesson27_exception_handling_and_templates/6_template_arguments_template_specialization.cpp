#include <iostream>
/*
templates: (meta code, or code formula)
	template arguments:
		when compiler resolves template parameter T and writes int instead, then it becomes a template argument
	how compiler resolves parameter T?
		1. deduction mechanism
		2. explicit template argument
			they can be combined too
	
	template specilization:
		compiler's code written against templates, but the process is called template instantiation
			vector<int> is vector class's specialization, func<double> is func's specialization
		compiler needs to see template's code so that it can produce source code, so generally templates are put in header files,
			and template codes do not have cpp files ofc you can use it in cpp files if it is used locally only
			but templates written for client codes must be in header files
			templates does not violate ODR one definition rule
*/
template <typename T>
void func(T x)
{
	//
}

int main() {
	func(12);			// template argument deduction (compiler does type deduction and uses int for T)
	func<double>(12);	// explicit template argument
}