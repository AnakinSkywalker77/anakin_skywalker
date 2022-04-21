#include <memory>
#include <iostream>
#include "person.h"

using namespace std;

/*
smart pointers cont:
	weak_ptr:
		but we have operator bool for shared_ptr, still why we need weak_ptr?
			due to cyclic reference
		cyclic reference:
			for some specific scenarios where we have two shared_ptrs but if they both gives reference to each other's objects, resource won't be deleted
			in this scenario use weak_ptr
*/

// lets pretend there is a cat game and each cat can have a friend

class Cat {
public:
	Cat(const string name) : m_name{name} {
		cout << m_name << " named cat is created in the game\n";
	}
	~Cat() {
		cout << m_name << " named cat exist from game\n";
	}
	string get_name() {
		return m_name;
	}
	void cry() {
		cout << m_name << " is meowing\n";
	}
	void display_friend_status() {
		if (m_friend) {
			cout << m_name << " has a friend and her friend's name is " << m_friend->get_name() << "\n";
		// use this code for solution as m_friend will be a weak_ptr we can only lock and use it:
		//if (auto sp = m_friend.lock()) {
		//	cout << m_name << " has a friend and her friend's name is " << sp->get_name() << "\n";
		}
		else {
			cout << m_name << " does not have a friend\n";
		}
	}
	void make_friends(shared_ptr<Cat> cat) {
		m_friend = cat;
		cout << m_name << " becomes friend with " << cat->get_name() << "\n";
	}
private:
	string m_name;
	shared_ptr<Cat> m_friend;
	// weak_ptr<Cat> m_friend;	//  solution is to use this
};

int main() {
	auto pcat1 = make_shared<Cat>("ginger");
	auto pcat2 = make_shared<Cat>("white angel");

	pcat1->display_friend_status();
	pcat2->display_friend_status();
	(void)getchar();

	pcat1->make_friends(pcat2);
	pcat1->display_friend_status();
	pcat2->display_friend_status();
	(void)getchar();
	pcat2->make_friends(pcat1);		// when you add this line you will create cyclic reference and no one cat is going to exit the game
	pcat1->display_friend_status();
	pcat2->display_friend_status();
	(void)getchar();

	

}