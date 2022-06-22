// Implicit Conversion is a automatic conversion by compiler if possible.
// only one conversion can be done at a time or at 1 operation.

// Explicit is a keyword used to stop the impicit functionality, i.e. compiler can't convert implicitly,
// you have to convert manually

#include<iostream>
#include<string>

class Entity {
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(const std::string& name)
		: m_Name(name) {}
	explicit Entity(int age)
		: m_Age(age){}
};

explicit void Printable(const Entity& e) {
	// Printing
}

int main() 
{	
	// before explicit

	Entity entity(18); // initialization with constructor
	Entity entity2 = 18; // This is implicit conversion, same as above
	Entity entity3 = Entity(18); // without conversion

	Entity e("manav"); // initialization with constructor
	Entity e2 = Entity("manav"); // without conversion
	Entity e2 = "Manav";// This will not work because we are passing const char* so first compiler has to convert const char* into 
						// string then in Entity, So here two conversion require but only one can be done
	Entity e2 = (std::string)"manav"; // This will work coz we are manually converting it into string so compiler has to done only one conversion from string to class contructor.

	Printable(9); // This will work because compiler will automatically convert this impicitly and pass as an parameter of constructor
	Printable("manav");  // not work 2 conversion required
	Printable(std::string("Manav")); // work only one conversion

	// After Explicit

	Entity e3 = (std::string)"manav"; // not work cause implicit conversion not allowed
	Entity e3 = Entity("Manav"); // Will work cause manually converting

	Entity entity3 = 18; // not work cause implicit conversion not allowed
	Entity entity3 = Entity(18); // Will work cause manually converting

	Printable(std::string("Manav")); // This will not work coz implicit not allowed
	Printable(Entity("manav")); // This will work cause manually converting

	std::cin.get();
}