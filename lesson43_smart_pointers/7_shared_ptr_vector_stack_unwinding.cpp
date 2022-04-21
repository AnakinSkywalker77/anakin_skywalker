#include <memory>
#include <iostream>
#include <string>
#include "person.h"
#include "nutility.h"
#include <vector>
#include <list>

using namespace std;

/*
smart pointers cont:
	shared_ptr:
*/

/*
what can you do with a shared_ptr?
	1. you can hold shared_ptr objects in a container just like unique_ptr
		even you can hold it in several containers as they can be copied...
	2. you can make it a class data member
		compiler written copy ctor will copy shared_ptr's thus they will all show the same resource

*/


using PersonPtr = shared_ptr<Person>;
void func();
int main() {
	
	vector<PersonPtr> pvec;

	for (int i = 0; i < 10; i++)
	{
		pvec.emplace_back(new Person{rname(), rfname()});
	}
	for (const auto &sptr : pvec)
	{
		cout << *sptr << "\n";
	}
	// here ofc when vector's lifetime ends it will be destroyed and the element/objects it is holding will be destroyed
	// so shared_ptr object will be deleted once the last shared_ptr holding the object is called

	// lets now copy them to list container:
	std::list<PersonPtr> plist{pvec.begin(), pvec.end()};
	// change in vector:
	for (const auto& sptr : pvec) {
		cout << sptr.use_count();	// all are 2
		sptr->change_person();		// changes names and surnames
	}

	(void)getchar();
	// now print list
	for (const auto &sptr : plist )
	{
		cout << *sptr << "\n";
	}
	(void)getchar();

	// the smart pointer's aim is to delete the object held once the pointer is deleted
	// for the following Person objects, they won't be deleted automatically, it is your responsibility to delete them
	
	cout << "\npvec2 \n";
	cout << "holding objects in normal pointers which won't be deleted automatically: \n";
	(void)getchar();
	vector<Person *> pvec2;
	for (int i = 0; i < 10; i++)
	{
		pvec2.emplace_back(new Person{ rname(), rfname() });
	}
	for (const auto& sptr : pvec2)
	{
		cout << *sptr << "\n";
	}

	cout << "\npvec3 \n";
	cout << "holding objects in normal pointers which won't be deleted automatically 2: \n";
	(void)getchar();
	vector<Person*> pvec3;
	// vector<PersonPtr> pvec3;
	// when smart pointers are used, if you catch exception then stack unwinding will be done
	// if you do not catch exception stack unwinding is not guaranteed
	for (int i = 0; i < 10; i++)
	{
		pvec3.emplace_back(new Person{ rname(), rfname() });
	}
	for (const auto& sptr : pvec3)
	{
		cout << *sptr << "\n";
	}
	// func();		// uncomment and see as this function is throwing exception still following delete code won't run
	// comment out this part when PersonPtr is used
	for (const auto& sptr : pvec3) {
		delete sptr;
	}
	// try like this too:
	try
	{
		// func();
	}
	catch (const std::exception&e)
	{
		cout << "exception caught: " << e.what() << "\n";
	}
	

}

void func() {
	throw std::runtime_error{ "func is throwing exception" };
}
