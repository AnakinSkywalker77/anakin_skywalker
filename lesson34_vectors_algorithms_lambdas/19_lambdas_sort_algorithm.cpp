#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
lambda expressions:
	why and where we use lambdas?

	sort() algorithm:

*/

int main() {
	vector<int> ivec;
	rfill(ivec, 100, Irand{ -500, 500 });
	print(ivec);

	sort(ivec.begin(), ivec.end());	// sorts from smaller to bigger
	print(ivec);

	// sort's other overload expects a predicate: above is actually done like this by default
	sort(ivec.begin(), ivec.end(), [](int x, int y) {return x < y; });
	print(ivec);

	// reverse
	sort(ivec.begin(), ivec.end(), [](int x, int y) {return x > y; });
	print(ivec);

	// abs
	sort(ivec.begin(), ivec.end(), [](int x, int y) {return abs(x) < abs(y); });
	print(ivec);

	// sort odds first and then evens
	vector<int> ivec2;
	rfill(ivec2, 100, Irand{ 0, 500 });
	print(ivec2);
	sort(ivec2.begin(), ivec2.end(), [](int a, int b) {
		return a % 2 != 0 && b % 2 == 0 || a % 2 == b % 2 && a < b; });
	print(ivec2);

}