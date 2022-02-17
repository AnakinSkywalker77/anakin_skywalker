#include <iostream>
#include <vector>
/*
exception handling:
	noexcept operator: unevaluated context, compile time operator like sizeof
		for the classes you write:
			dtor is already noexcept even if you do not write
			move ctors should be noexcept as much as possible
			all swap functions should be noexcept as much as possible

*/

class Person {
public:

	Person(const char* ptr)
	{
	}
	Person(const Person&)
	{
		std::cout << "COPY\n";
	}
	// Person(Person&&)noexcept;	// when you use this all will be moved, not copied
	Person(Person&&)
	{
		std::cout << "MOVE\n";
	}
};

int main() {
	std::vector<Person> pvec{ "Jon", "Jack", "Jason" };
	pvec.push_back("necati");
}