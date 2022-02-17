
class Base {
public:
	void func();
};

class Der : public Base {
private:
	void func();
};

int main() {

	Der myder;
	myder.func();		// error access control as func() in Der is private
	myder.Base::func();	// this is ok
}