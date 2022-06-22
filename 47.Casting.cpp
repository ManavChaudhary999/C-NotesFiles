// Casting is a method or process of converting one data type to another.
// There are two types of casting or conversion - 1. Implicit Conversion 2. Explicit Conversion
// Implicit is automatically done by compiler.
// Explicit means we have to done explicitly.
// We can convert types in two ways - 1. C style  2. C++ Style
// C++ style cast are same as c style cast, just a syntax different but dynamic cast is little bit different and also c++ style cast
// have some additional benefit like they can restrict some type of conversion which isn't allowed.
// Various C++ style cast type are - 
// 1. static_cast<data_type>(var), 2. const_cast<data_type>(var) , 3. dynamic_cast<data_type>(var), 4. reinterpret_cast<data_type>(var)

#include <iostream>

class Base {
public:
	Base() { }
	virtual ~Base() { }
};

class Derived : public Base {
public:
	Derived() { }
	~Derived() { }
};

class AnotherClass : public Base {
public:
	AnotherClass() {}
	~AnotherClass() {}
};

int main() 
{
	// Implicit Conversion

	int a = 5.5; // a will be 5 cause implicitly conversion by compiler.
	double value = a; // value will be 5 cause implicitly conversion of int to double

	double x = 2.5;
	int ans = x*2 + 5;	// ans will be 10 by implicit conversion (2.5*2 + 5 = 10)
	// But by explicit conversion
	double x = 2.5;
	int ans = (int)x * 2 + 5;	// ans will be 9 by explicit conversion (2*2 + 5 = 9)
	
	// C++ Style Explicit Conversion
	
	double x = 2.5;
	int ans = static_cast<int>(x) * 2 + 5;	// ans will be 9 by c++ explicit conversion (2*2 + 5 = 9)

	int value = static_cast<AnotherClass*>(&x); // this wont be allowed using static_cast
	int value = reinterpret_cast<AnotherClass*>(&x); //

	// Useful Case of C++ Style Cast

	Derived* derived = new Derived();
	Base* base = derived; // Now base is a derived instance meaning it is of type derived

	// Another Class inherits base class not derived class so it is of only AnotherClass and BaseClass Type not derived class type
	// but here we are converting base(derived instance) into Another Class which isn't possible
	// So ac will be null.
	AnotherClass ac = dynamic_cast<AnotherClass>(base); 

	std::cin.get(0);
}