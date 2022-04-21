#include "nec.h"
#include <iostream>
// classic pimpl:
#include "date.h"
#include "person.h"
#include <string>

using namespace std;


// classic pimpl:
struct Nec::Pimpl {
	Pimpl() : m_person("","") {}
	string m_str;
	Date m_date;
	Person m_person;

};
// Nec::Nec() : mp{ new Pimpl } {}
Nec::Nec() : mp{ make_unique<Pimpl>() } {} // modern implementation: you can use this ctor (note above is ok too)
// modern implementation: no need to dtor, you need it for classic pimpl
//Nec::~Nec() {
//	delete mp;
//}
Nec::~Nec() = default; // modern implementation

// following are same both for classic and modern pimpl as unique_ptr has . and -> operators
void Nec::nfoo() {
	// classic pimpl:
	mp->m_str += "...";
	cout << mp->m_person << "\n";
	cout << mp->m_date.month_day() << "\n";

	// normal usage:
	//m_str += "...";
	//cout<< m_person << "\n";
	//cout << m_date.month_day() << "\n";

}

void Nec::nfunc() {
	// classic pimpl:
	mp->m_str += "...";
	cout << mp->m_person << "\n";
	cout << mp->m_date.month_day() << "\n";

	// normal usage:
	//m_str += "...";
	//cout << m_person << "\n";
	//cout << m_date.month_day() << "\n";

}
