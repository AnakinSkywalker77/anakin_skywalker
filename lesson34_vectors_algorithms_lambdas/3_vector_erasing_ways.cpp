#include <iostream>
#include <vector>
#include <string>



using namespace std;

/*
vector functions:
	erasing a vector using different ways:

*/

int main() {

	vector<string> svec{"ali", "nur", "deniz", "ferhan"};
	cout << svec.size() << '\n';
	// any of the following ways can be used to erase a vector
	// svec.clear();
	// svec.resize(0);
	// svec.erase(svec.begin(), svec.end());
	// svec = vector<string>{};	// assigning a default inited vector
	// svec = {};	// assigning an initialazer_list
	svec.assign({});
	cout << svec.size() << '\n';
	
}


