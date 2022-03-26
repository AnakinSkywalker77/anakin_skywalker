#include <iostream>
#include <vector>
#include "date.h"
#include "nutility.h"


using namespace std;

/*
vector functions:
	.swap()
		never ever write a code like this to swap two containters:
				Con x;
				Con y;
				auto temp = x;
				x = y;
				y = temp;
				because you will cause copying 3 times here.
			as containers are hold by three pointers, why not only swap them by either swap member function or
				swap algorithm?
	
	previously you could not shrink a vector's capacity, and it was done by a swap trick...
		but you can now do with shrink_to_fit()

*/

int main() {

	vector<int> ivec(100'000);

	cout << "ivec.size()= " << ivec.size() << '\n';
	cout << "ivec.capacity()= " << ivec.capacity() << '\n';
	
	ivec.erase(ivec.begin() + 5, ivec.end());
	cout << "\n\nivec.size()= " << ivec.size() << '\n';
	cout << "ivec.capacity()= " << ivec.capacity() << '\n';
	
	// swap trick:
	// create a temp vector with copy ctor using ivec's elements and then swap it with original ivec
	//vector<int>{ivec}.swap(ivec);
	ivec.shrink_to_fit();
	cout << "\n\nivec.size()= " << ivec.size() << '\n';
	cout << "ivec.capacity()= " << ivec.capacity() << '\n';


}
