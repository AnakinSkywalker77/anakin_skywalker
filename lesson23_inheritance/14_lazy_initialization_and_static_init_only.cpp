
/*
if you do not want to take risk of a not-inited global which is used in another source file there are two ways:
	1. init only static
		if a global variable only static inited (not inited dynamically) then this global variable, if used in any
			other source file, there is no risk of not-initialized
	2. lazy initialization or construct on first use:
			Myclass & get(){static Myclass m; return m;}
*/

class A {};

class Myclass {
public:
	A& foo();

};

Myclass& get_instance() {
	static Myclass m;	// this static object will be inited on the first call of the get_instance() functions
						// on the second call, it will return the same object
	return m;
}
/*
advantages:
	Myclass object m won't be initialized if get_instance() is not called
		to dynamic init object get_instance() must be called
	cpp11 even if get_instance() is called from multithreads it will be only inited once
*/


// in another source file:
A ax = get_instance().foo();	// here there is no risk of using object without it's initialization !!!
								// even you can use get_instance() in ctors in other source files


int main() 
{

}
