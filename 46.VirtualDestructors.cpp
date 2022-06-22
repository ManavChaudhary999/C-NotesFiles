#include <iostream>

class Base {
public:
	Base() { std::cout << "Base Constructor Called\n"; }
	virtual ~Base() { std::cout << "Base Destructor Called\n"; }
};

class Derived : public Base {
public:
	Derived() { std::cout << "Derived Constructor Called\n"; }
	~Derived() { std::cout << "Derived Destructor Called\n"; }
};

int main()
{
	Base* base = new Base(); // O/P - Base Constructor Called
	delete base; // O/P - Base Destructor Called

	std::cout << "--------------------------------\n";

	Derived* derived = new Derived();// O/P - Base Constructor Called and Derived Constructor Called
	delete derived; // O/P - Base Destructor Called and Derived Destructor Called

	std::cout << "--------------------------------\n";

	// Problem
	// Before Virtual Destructor
	Base* another = new Derived(); // O/P - Base Constructor Called and Derived Constructor Called
	delete another; // O/P - Base Destructor Called only
	// So here we are not destructing(freeing) Derived Class which cause Memory leak.

	// FIX - Virtual Destructor this will destruct both Base and Derived because virtual means ovveriding

	std::cin.get();
}