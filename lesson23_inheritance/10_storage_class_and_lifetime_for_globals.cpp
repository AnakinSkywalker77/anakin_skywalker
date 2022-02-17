#include <iostream>


/*
global objects issues:
	global objects, if external, can be accessed from all source files
	global objects will be created before main(), and can start using resources upon creation (before main)
		and if exceptions are throwed in global objects' constructors you can never catch them
		you can only catch exceptions after main() starts

storage class
	storage class and lifetime are different things
	storage duration: is related to memory allocation for objects
	storage duration types: automatic, static, dynamic, and thread_local storages
		every object has to have one of the above storage duration types
	static storage:
		static storage allocation is done for global variables, static local variables, class's static data members
			for those, storage will be allocated before main() is called, and deallocated after main() ends
lifetime:
	lifetime is about calling ctor() and dtor(), about when object is created and when it is destroyed
		the memory allocation (storage duration) for object is different than the lifetime of the object
	automatic objects:
		automatic objects are created on the line of definition, and when scope ends destroyed
	static objects:
		static objects are inited in two steps: static initialization and dynamic initialization
		static initialization is zeroing out object's memory storage, this is done during compile time
		after static initialization, dynamic initialization is done by calling object's ctor()
		if you init a static object with a constant expression value:
			for that object only static init is done, no dynamic init
			int x = constant expression - only static init
				int x = 10*20;
				note as constexpr variables must be inited with constant value, only static init is done
			int y = non-constant expression - static and then dynamic init is done
		
		static local objects:
			static init is done before main(), but dynamic init is done only when definition code line runs on
				first time. on later runs of this line nothing is done, no dynamic init etc
				its dtor will be called after main ends as we know already
		
		WARNING:
			if a global object is only static inited, using it in any other source file is not a problem
			BUT !!! for global objects defined in different translation units (cpp files) dynamic initialization
				order is not defined by cpp language
				this can cause runtime errors if you do not be careful about this "static initialization order fiasco"
			so in a global object's ctor (or when creating a global object) never use another global object if
				there is no documented guarantee
			but in the same translation unit, dynamic initialization order of global objects is defined
				and it is from top to bottom
		
			for cout, cerr, cin can be used in ctors as it is guaranteed (nifty-counter or Schwarts idiom)

			translation unit: is the source file after preprocessor has done its job
				and compiler works on translation units, not directly on source files

				
*/

class Myclass {};


void func() {
	static Myclass m; // static local object
}

int main() {

	// automatic storage:
	{					// storage for m will be allocated when program flow gets in to this block
		Myclass m;		// but lifetime for m object starts here (ctor() is called)
	}					// lifetime ends here (by calling dtor()); and storage for m will be deallocated once this block ends
	
	// dynamic storage:
	Myclass* p = new Myclass;		// storage for dynamic object is allocated on heap
	delete p;						// storage is deallocated


 }