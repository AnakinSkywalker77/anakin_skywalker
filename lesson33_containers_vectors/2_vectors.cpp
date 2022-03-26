#include <iostream>
#include <vector>

using namespace std;

/*
vectors:
	is a dynamic array container and widely used (implements dynamic arrays)
	dynamic array advantages:
		holds object contiguous (one after other) in memory
		you can access an object in constant time O(1)
		and it is easy to access and sometimes if it is used very frequently a vector or a part of vector can be put in cache
		because contiguousness, cache miss is very low
		push back is done in constant time O(1) (before size reaches capacity)
			note push front, or middle are not, all elements are moved, linear complexity O(n)
	you need 3 pointers to impement a dynamic array, vector: start, size, capacity
		you do not have direct access those pointers
	size is the number of the elements in vector
	capacity is the max number elements that this vector can hold
		when you add more items and vector's size reaches its capacity, upon next addition request,
			vector is copied or moved to a new larger location by reallocation (1.5x or 2x larger depends on compiler)
				moving or copying is decided during compile time by whether the move ctor is noexcept
			too many reallocations reduce performance, so try to avoid as much as possible, but ofc you have to do it
			so pushing back an element is done actually in amortized constant time (due to reallocation)
		no new reallocation is done as long as capacity is not reached
		capacity can increase automatically but does not shrink, you can not shrink it by changing size
			ofc you can reduce it by shrink_to_fit
	vector is the fundamental container used so its implementation shows compiler's quality
	vector reallocation is done by x1.5 or x2 of previous size
		size does not shring by removing vector's elements, you need to resize
	move ctor's noexcept is very important when reallocating the vectors holding your objects!!!
	STL's vector class does not do small buffer optimization (unlike boost)

*/

int main() {

	vector<int> ivec(10);

	int cap = ivec.capacity();
	for (;;) {
		ivec.push_back(0);
		if (ivec.capacity() > cap) {
			cout << "size: " << ivec.size() << " capacity: " << ivec.capacity() << '\n';
			cap = ivec.capacity();
			(void)getchar();
		}
	}

}