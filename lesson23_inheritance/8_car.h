#ifndef CAR_H
#define CAR_H

#include <ostream>



// -------------------------------
class Car {
public:
	friend std::ostream& operator<<(std::ostream& os, Car& c) {
		c.print(os);
		return os;
	}
	virtual void print(std::ostream&)const = 0;
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
	virtual void print(std::ostream&)const override;
	virtual Bmw* clone()override;
	virtual Bmw* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

class BmwCoupe : public Bmw {		// new 2nd level derived class
public:
	virtual void print(std::ostream&)const override;
	virtual BmwCoupe* clone()override;
	virtual BmwCoupe* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Volvo : public Car {
public:
	virtual void print(std::ostream&)const override;
	virtual Volvo* clone()override;
	virtual Volvo* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Audi : public Car {
public:
	virtual void print(std::ostream&)const override;
	virtual Audi* clone()override;
	virtual Audi* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Mercedes : public Car {
public:
	virtual void print(std::ostream&)const override;
	virtual Mercedes* clone()override;
	virtual Mercedes* create()override;
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
Car* createRandomCar(void);

#endif