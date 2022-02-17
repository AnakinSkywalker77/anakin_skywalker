

/*
constinit: cpp20 constant initialized (not const !!!)
	dynamic init depends on expr here: if constant only static init
		int g = expr;
	but if you use constint keyword it must be inited by constant value (means only static init), if otherwise then 
	syntax it will be error:
		constint int g = expr;
*/

class Myclass {
public:
	constexpr Myclass(int val) : mx{ val } {}
	void set(int x);
	// Myclass(int val) : mx{ val } {}
private:
	int mx;
};
constinit Myclass m{ 12 };	// this way you can be sure it is static inited only
// constinit const Myclass m{ 12 };		// if you make it const as well, then m.set(10); will be syntax error

int main() {

	m.set(10);		// you can call a function with m, as m object is not constant, only constant inited!!!
}