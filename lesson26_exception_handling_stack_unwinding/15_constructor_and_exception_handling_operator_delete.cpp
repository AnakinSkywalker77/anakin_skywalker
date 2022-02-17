#include <iostream>

/*
exception handling:
	constructor and exception handling:
		operator delete:
		operator delete will be called properly in case of an exception:
*/

void* operator new(std::size_t sz) {
	std::cout << "operator new is called for the size: " << sz << '\n';

	if (sz == 0)
		++sz;
	if (void* ptr = std::malloc(sz))
		return ptr;
	throw std::bad_alloc{};
}

void operator delete(void* ptr)noexcept {

	std::cout << "operator delete is called for address: " << ptr << '\n';
	std::free(ptr);
}

class Myclass {
public:
	Myclass(){
		std::cout << "Myclass ctor \n";
		throw 1;
	}

	~Myclass() {
		std::cout << "Myclass dtor\n";
	}
private:
	unsigned char buffer[1024];
};

int main() {
	try
	{
		/*
		here first operator new is called and storage (which is sizeof(Myclass)) for object is allocated on heap
			and then this storage's address is sent to ctor, and ctor uses it as "this" address
		*/
		Myclass* p = new Myclass;

	}
	catch (int)
	{
		std::cout << "main() exception caught\n";
	}


	/*
	delete p;
	when you delete it, first dtor is called, then operator delete function is called and storage allocated by
		operator new is returned
	note that returning of this storage is guaranteed, even if ctor throws an exception and hence dtor is not
	*/
}