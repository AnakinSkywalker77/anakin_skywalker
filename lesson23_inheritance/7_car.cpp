#include "car.h"
#include <iostream>

using namespace std;

Bmw* Bmw::clone()
{
	return new Bmw(*this);		// we will copy ctor to have the clone existing one
}

Bmw* Bmw::create()
{
	return new Bmw;
}

// -------------------------------
void Bmw::start() {
	cout << "Bmw has started \n";
}

void Bmw::run() {
	cout << "Bmw is running \n";
}

void Bmw::stop() {
	cout << "Bmw has stopped \n";
}

BmwCoupe* BmwCoupe::clone()
{
	return new BmwCoupe(*this);
}

BmwCoupe* BmwCoupe::create()
{
	return new BmwCoupe;
}

// -------------------------------
void BmwCoupe::start() {
	cout << "BmwCoupe has started \n";
}

void BmwCoupe::run() {
	cout << "BmwCoupe is running \n";
}

void BmwCoupe::stop() {
	cout << "BmwCoupe has stopped \n";
}

Volvo* Volvo::clone()
{
	return new Volvo(*this);
}

Volvo* Volvo::create()
{
	return new Volvo;
}

// -------------------------------
void Volvo::start() {
	cout << "Volvo has started \n";
}

void Volvo::run() {
	cout << "Volvo is running \n";
}

void Volvo::stop() {
	cout << "Volvo has stopped \n";
}

Audi* Audi::clone()
{
	return new Audi(*this);
}

Audi* Audi::create()
{
	return new Audi;
}

// -------------------------------
void Audi::start() {
	cout << "Audi has started \n";
}

void Audi::run() {
	cout << "Audi is running \n";
}

void Audi::stop() {
	cout << "Audi has stopped \n";
}

Mercedes* Mercedes::clone()
{
	return new Mercedes(*this);
}

Mercedes* Mercedes::create()
{
	return new Mercedes;
}

// -------------------------------
void Mercedes::start() {
	cout << "Mercedes has started \n";
}

void Mercedes::run() {
	cout << "Mercedes is running \n";
}

void Mercedes::stop() {
	cout << "Mercedes has stopped \n";
}

Car* createRandomCar() {

	switch (rand() % 5) {
	case 0: return new Bmw;
	case 1: return new Volvo;
	case 2: return new Audi;
	case 3: return new Mercedes;
	case 4: return new BmwCoupe;
	}
	return nullptr;
}