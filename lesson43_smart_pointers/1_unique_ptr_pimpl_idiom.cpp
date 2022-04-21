#include <iostream>
#include "nec.h"

using namespace std;

/*
smart pointers cont:
	one thing about unique_ptr
	pimpl idiom: pointer implementation
		other names used for this idiom:
			opaque pointer idiom
			handle body idiom
			chesire-cat idiom
		it is realted to hiding private members, why?
			1. reduce dependency
				dependency increases if weinclude 3 *h files but they include 10 each which include 20 each etc...
					those have to be recompiled etc.
				with this way we are not injecting our dependencies to our client codes which are going to include our nec.h file
			2. reduce compile time:
				compile time will be longer with added header files
			3. data hiding
				as we do not include data members in *.h file, hiding implementation details
		but if weuse unique_ptr instead, and hide private members wedo not need to include header files
			this is done by a forward declaration for non-complete type, and holding a pointer to that one
			and function's parameters and return value can be an incomplete type too, they just need a forward declaration
			ofc wehave to include required *h files in our*cpp but weare not giving our*cpp files to ourclient !!!
			with raw pointer, whenever an exception occurcs before deleting ourdynamically created object, it won't be deleted !!!
		when weuse unique_ptr instead of raw pointer (when we make our opaque pointer unique_ptr), wedo not need to write delete code
			once unique_ptr's life is over the object it holds will be deleted
				thus it will be exception safe, and no need to write Nec's dtor, we can default it
			if welet compiler write dtor by only declaring, it will be a non-static public inline function, it means it is defining in the header file
				and it is calling pointer's delete (which calls Pimpl struct's dtor) which causes syntax error
				even if wedefault dtor in header, it is same as incomplete type can not be deleted
				problem is deleting an incomplete type
			weneed to default dtor in ourcpp file which is legal
		when wechange ourcpp impmelentation other modules which are including ourheader file do not need to be compiled again
		disadvantages:
			1. dyanmic object cost
				we have a pointer and created a dynamic object which is costly (to fix this wecan use fast pimpl idiom and placement new etc)
			2. dereferencing (indirection) cost
				whenever weneed to use a data member we need to dereference it, as we are holding object in a pointer

*/

int main() {

	Nec mynec;
	mynec.nfoo();
	mynec.nfoo();

}