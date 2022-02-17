#include <iostream>
#include <stdexcept>

/*
exception handling:
	function try block:
		why we use it?
			to catch exceptions during object initializing by CIL syntax
			to catch and translate exception
			in a ctor try-catch block, even if you do not rethrow, exception will be rethrown (only in ctors)
				if exception is thrown in ctor, the object, which is being constructed, will be a zombie object
*/

class Member {
public:
	Member(int x) {
		if (x % 2 == 0)
			throw std::runtime_error{"error error!"};
	}
};

class Nec {
public:
	Nec() try : mx{ 20 } {
		/*
			here by this inner try-catch block, even if you put all code of ctor you cannot catch exception coming from
				data member inited by cil
			on this kind of exception, object becomes zombie and you cannot create it anymore,
				then why we are trying to catch this exception?
					to either rethrow or log and throw another exception (translate)
		*/
		//try {
		//}
		//catch (const std::exception& ex) {
		//	std::cout << "excepation caught inner try-catch " << ex.what() << '\n';
		//}
	}
	catch (const std::exception& ex) {
		std::cout << "exception caught by function try block: " << ex.what() << '\n';
		getchar();
		// even if you do not rethrow it will be rethrown anyway
		// throw;
		throw std::logic_error{"logic error"};
	}

private:
	Member mx;
};

int main() {

	/*
		here if you do not to catch the exception thrown by ctor, terminate() will be called here
		now we are catching it here:
	*/
	try {
		Nec mynec;
	}
	catch (const std::exception& ex) {
		std::cout << "main() exception caught: " << ex.what() << '\n';
	}
}