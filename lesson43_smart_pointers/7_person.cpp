#pragma once
#include "person.h"
#include <iostream>
#include <ostream>

using namespace std;

ostream& operator<<(ostream &os, const Person &p) {
	return os << p.m_name << " " << p.m_surname;
}
Person::~Person() {
	cout << *this << " is being destroyed\n";
}

void Person::change_person() {
	m_name += "can";
	m_surname+="oglu";
}