#include <iostream>
#include <string>
#include <vector>
#include "nutility.h"

using namespace std;

/*
lambda expressions:
	why and where we use lambdas?
		as argument statements to algorithms


*/

class lenpred {
public:
	lenpred(size_t len) : m_len(len) {}
	bool operator()(const string &s) {return s.size() == m_len;}
private:
	size_t m_len;
};

int main() {
	vector<string> svec;
	rfill(svec, 1000, rname);
	size_t len;
	cout << "provide name lenght: ";
	cin >> len;

	int result1 = count_if(svec.begin(), svec.end(),lenpred{ len });
	cout << "\nfound1: " << result1 << "\n";

	// do the same thing with lambda:
	int result2 = count_if(svec.begin(), svec.end(), [len](const string &s) {return s.size()==len; });
	cout << "\nfound2: " << result2 << "\n\n";

	// another sample:
	vector<string> svec2;
	rfill(svec2, 100, rname);
	print(svec2);
	vector<size_t> lenvec(svec2.size());
	transform(svec2.begin(), svec2.end(), lenvec.begin(), [](const string& s) {return s.size(); });
	print(lenvec);
	/*
		you can do it with auto parameter and afterwards if you change your vector type from string to
			lets say wstring, you do not have to change transform, it will still run as expected with auto
			type deduction and you will have a template operator()(){} function
		and the other advantage of auto is it frees you from writing long type names
	*/
	transform(svec2.begin(), svec2.end(), lenvec.begin(), [](auto& s) {return s.size(); });
	print(lenvec);

	// like this:
	vector<pair<string, int>> pvec;
	rfill(pvec, 10000, [] {return pair{ rname(),rand() }; });
	// print(pvec, "\n");
	// lets find if pair's second is 555
	auto iter = find_if(pvec.begin(), pvec.end(), [](const std::pair<std::string, int> &x) {return x.second == 555; });
	// generalized lambda expression simplifies type names
	auto iter2 = find_if(pvec.begin(), pvec.end(), [](auto& x) {return x.second = 555; });


	if (iter != pvec.end())
		cout << "\nfound: " << *iter;	// normally you cannot print a pair like this but we have a function
										// template in nutility that allows this
	else
		cout << "\nnot found\n";
}