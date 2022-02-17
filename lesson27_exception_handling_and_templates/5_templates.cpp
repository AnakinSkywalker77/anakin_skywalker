#include <iostream>
/*
templates: (meta code, or code formula)
	starting generic programming paradigm with templates
	cpp compiler is a program which can write code for us
		c compiler is compiling the code and translating it to assembly code
		cpp compiler is not only doing that, also writing codes for user, using templates
	why we have this tool?
		to create a generic function:
			algoritihms are type independent, like swapp() uses same way abstractly (regadless of swapped types)
			so why not just give a swap template to compiler and whenever a new type is gonna be swapped, compiler can write a
				function (using our template) to swap according to the new type?
		cpp's templates (generic structure) is neither related to c's void* nor base object like in Java
			type independent template is compiled and turned into concrete codes which are type depended
	templates are very important as STL is a template library
	STL and cpp standart library are differnt things, STL is a part of the cpp standart library,
		but they are used in the same meaning
		with modern cpp:
			resrtictions are loosened, and new tools are added to templates
			added two new types: variable templates, alias templates
			and variadic templates are added, it is not a template type, templates can be variadic or not
	advantages: code reuse,
	disadvantages: template codes are complex
		compilers were giving errors 200-300 lines, but with cpp20 concept is added, errors are shorter and understandable

	template types:
		1. function templates
		2. class templates
		3. variable templates (cpp11)
		4. alias templates (cpp11)
			and any template type can be variadic

	syntax: template (it is a keyword) <(template parameters)>
	template parameters can be:
		1. type parameters
		2. non-type parameters (constant parameter)
		3. template template parameters (very rarely used won't be taught here)
	
	!!! type independent template is compiled and turned into concrete codes which are type depended
	
	type parameters: this name is a type name
		template <class T> here T does not have to be class type, it means it is a type. and T is an identifier, can be anything
			same with template <typename T>
		can be like template <class T, class U>
			note template <class T,U> is not allowed
			template <class T, typename U> is ok too, but do not use it, use typename always
		typename keyword is used in other places as well, do not mix that with class keyword used here, here both are same
	
	non-type parameter: this name is a constant
		but does not have to be integral types, can be double or literal types (with cpp20)
		can be used together with type parameters: template<typename T, int x>

*/

template <class T>		// type parameter
class Myclass {

	double a[x];
};

template <typename T, int x> // type and non-type parameter
class Nec {

	T a[x];
};

template <double x>		// cpp20
class A {

};

// T and U dont have to be different can be same like int, they are used to differentiate types in template code if necessary
template <typename T, typename U>
class Anyclass {

};