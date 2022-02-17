#ifndef CAR_H
#define CAR_H

#include <ostream>



// -------------------------------
class Car {
public:
	virtual Car* clone() = 0;		// note that we will use smart pointers to keep dynamic objects
	virtual Car* create() = 0;
	virtual void start() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual ~Car() = default;		// viortual dtor
};

// -------------------------------
class Bmw : public Car {
public:
	// tip to create definitions by vs
	// select virtual function(s) -> Quick Actions and refactroings -> click Create Declaration / Definition
	virtual Bmw* clone()override;
	virtual Bmw* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

class BmwCoupe : public Bmw {		// new 2nd level derived class
public:
	virtual BmwCoupe* clone()override;
	virtual BmwCoupe* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Volvo : public Car {
public:
	virtual Volvo* clone()override;
	virtual Volvo* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Audi : public Car {
public:
	virtual Audi* clone()override;
	virtual Audi* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Mercedes : public Car {
public:
	virtual Mercedes* clone()override;
	virtual Mercedes* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
Car* createRandomCar(void);

#endif