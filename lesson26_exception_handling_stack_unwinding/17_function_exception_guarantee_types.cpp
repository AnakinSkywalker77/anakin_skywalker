#include <iostream>

/*
exception handling:
	function's exception guarantees:
		not acceptable one:
			if object.func(), if func() has resource leak because it is throwing an exception,
				this is not acceptable !!! code is not exception-safe !!!
		basic (exception) guarantee:
			even if an exception is thrown, no resource leakage is guaranteed
			you cannot provide less than this one, you must not provide less than this guarantee
			keeping the object state is not the guaranteed, object state may change, but object is still usable
		strong (exception) guarantee:
			even if an exception is thrown, no resource leakage is guaranteed and commit or rollback guaranteed
			so basic exception guarantee & commit or rollback guaranteed
				this means the state of the object must not change either, if it will be, rollback of everything
					is guaranteed
		no throw guarantee:
			no exception will be throwed out of this function
				it can use exceptions and throw exceptions, but does not emit or propagate
			this helps compiler to make better optimization in generic programming codes, can generate better
				source codes (compiler can optimize assembler code too, but it is different, here compiler is
				writing codes for ourselves using class/function templates)
			for instance vectors can be moved when vector's objects have no throw guarantee, compiler checks move
				ctor() to understand no throw guarantee
*/
