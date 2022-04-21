#include <memory>
#include <iostream>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	weak_ptr:
		is not a smart pointer class
		it is like an observer of the shared_ptr, but does not increase shared_ptr's ref count
		you can default init a weak_ptr but generally you will initialize with a shared_ptr
		why we use it?
			you can access shared_ptr's resource and check whether resource is deleted or not
			you can create a shared_ptr from a weak_ptr, that is why you need to learn whether it has a resource or not
		.lock() returns you a shared_ptr from weak_ptr
			if you do not check weak_ptr before creating a shared_ptr from it, exception is throwed
		.expired() gives you whether the resource is deleted already, check this and then use
		we cannot access object by weak_ptr, but can check whether it is still alive or not, and then can create a shared_ptr to access
*/

int main() {
	auto sp = make_shared<Person>("Nurullah", "Gulersoy");
	cout << *sp << "\n";
	cout << "sp.use_count() : " << sp.use_count() << "\n";

	weak_ptr<Person> wp{ sp };
	cout << "sp.use_count() : " << sp.use_count() << "\n";
	cout << "wp.use_count() : " << wp.use_count() << "\n";		// this shows the weak pointers holding this object

	// sp.reset();	// uncomment and see result with this
	auto spx = wp.lock();
	if (spx) {
		cout << "resource is still alive \n";
		cout << *spx << "\n";
	}
	else {
		cout << "resource is destroyed \n";
	}
	(void)getchar();

	// notes:	
	if (auto spx2 = wp.lock()) {}// note that dynamic cast is used with weak_ptr frequently
	if (auto spx2 = wp.lock(); spx2) {}	// same with this cpp17


	shared_ptr<Person> spx2{ wp };	// if you do not check weak_ptr before creating a shared_ptr from it, exception is throwed
									// so when sp.reset() is done exception will be throwed here
	// cout << *spx2 << "\n";			// here exception occurs, abort terminate is called
	
	// try this too and catch it
	/*try
	{
		shared_ptr<Person> spx2{ wp };	// if you do not check weak_ptr before creating a shared_ptr from it, exception is throwed
										// so when sp.reset() is done exception will be throwed here
		// cout << *spx2 << "\n";			// here exception occurs

	}
	catch (const std::exception&e)
	{
		cout << "exception caught: " << e.what() <<"\n";
	}
	*/


	if (!wp.expired())	// when sp.reset() is done wp will be expired. note that you can use use_count() too
	{
		cout << "expired() resource is still alive \n";
		shared_ptr<Person> spx3{ wp };		// now create it
		spx3->change_person();
		cout << *spx3 << "\n";
	}
	else {
		cout << "expired() resource is destroyed \n";
	}
}