#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <errno.h>
#include <string.h>

using namespace std;
/*
exception handling:
	unlike other OOP languages exception handling in cpp is mostly used for runtime error handling
		not used to change programm's flow control

	exception here means unexpected situations
	exception happens, during runtime, if a function (due to unfulfilled conditions) can't do whatever it should do
		in this case what this function should do? throwing an exception? or returning an error?
	exception handling is a perfect alternative for traditional error handling mechanisms
	in cpp, conventional = traditional error handling mechanisms have advantages and disadvantages
		disadvantages:
			1. they are not enforcing, meanly you do not have to do a check for error handling (it is optional
				to check the return value etc)
				if it is forcing then if an exception happens it can abort the program and exit to
					force you implement it
			2. using return value to report error creates complexity (in c)
				because normal codes are mixed with error handling codes like:
					statement; // do smth
					statement; // error handling
					statement; // do smth
					statement; // error handling
				if functionailty providing codes are seperated from error handling codes, it would be better
			3. in c, on error, it returns to the caller function f1 => f2 => f3 ... f9
				upon f9 error, whoever the deciding authority on error?
					it will keep returning back till that function like f1, so many returns
				if we could jump from f9 to f1 with a direct link during runtime, it would be better 
			4. constructor functions do not have return value, how are we gonna return an error in ctors?
	advantages of exception handling:
		1. enforcing
		2. program flow can jump from wherever it needs to
			so that program flow can jump from function has error to function has error handling code
		3. error handling codes are seperated from normal codes
			we do not have to add "if" checks to check each error
		4. compiler can use these advantages and create a better optimized code

	note that exception handling is handling of unexpected situations during runtime
		if the problem can be fixed by changing code then it is not an exception, it is programming error
		exception handling is not "coding error" handling !!!
	coding errors are handled with assertion codes, assertion functions
		in cpp we have dynamic assertion to catch runtime coding errors: assert(p!=NULL);
			and static assertion to detect compile time errors: static_assert(sizeof(int) > 4);
		both related to the coding errors, only the checks are done at different time: runtime or compile time
	
	note that if an exception happens > %3-4 then it is not an exception, it is something normal
		it is something about the logic of your program

*/

int main() {
/*
 classic error handling in c:
	 1. return an error in function return
	 2. create a global error variable and set it in function's error situations
*/
	printf("errno: %d \n", errno);
	FILE* f = fopen("nofile.txt", "r");
	printf("errno: %d \n", errno);

	// printing text of errno
	perror("error text ");
	puts(strerror(errno));
	errno = 0; // you need to reset errno so that you can reuse it, otherwise it keeps the last value
}