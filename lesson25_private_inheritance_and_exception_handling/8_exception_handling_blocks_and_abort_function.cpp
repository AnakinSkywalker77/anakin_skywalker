#include <iostream>

using namespace std;
/*
exception handling:
	due to an unexpected situation, the code block (or function) which cannot do its job properly,
		creates an object and sends it to upper layer codes (calling functions) to inform them
	
	throw statement has two types:
		throw expr;
			compiler creates an object using this expr like: auto compiler_generated_object = expr;
			this expr determines the object type to be created
				if it is integer type, compiler creates an object of integer type
				if it is a class type, compiler creates an object of that class type 
			there will be special class types to throw exception, and they will be in a polymorphic class hierarchy
		throw;		// this is called rethrow statement
	try block:
		try{
			if an error object thrown from the codes here, I will be willing to catch it
			throw statement can be here directly or in the functions called from here:
				throw 1;
				foo();
		}
	catch block:
		catch block or blocks can come after a try block
		catch blocks are like only-one-parameter functions with no-return value
		you have to have a new catch block for each error object type
			try{
				//
			}
			catch(int x){
				//
			}
			catch(dobuble y){
				//
			}
	uncaught exception:
		if the error thrown is not cought, the program is terminated by "void terminate()" function
			if you want your program to continue running you need to catch the exceptin thrown
		terminate() calls abort() function and terminates the program (
			abort(): abnormal program termination function
			exit(): normal program termination function
		why terminate() calls abort() and why not we call abort() directly?
			because we have set_terminate() and can set which function to be called instead of abort()

*/

void f3() {
	cout << "f3 is called \n";
	throw 1;
	cout << "f3 is ended \n";
}
void f2() {
	cout << "f2 is called \n";
	f3();
	cout << "f2 is ended \n";
}

void f1() {
	cout << "f1 is called \n";
	f2();
	cout << "f1 is ended \n";
}

int main() {

	cout << "main() is started \n";
	f1();
	cout << "main() is ending \n";
}