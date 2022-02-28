// Objects are the Instance of a class.
// Objects need some memory to instantiate the class, even if the class is empty(no data types or methods)
// Objects take atleas 1 byte of memory.
// So based on the memory type (stack or heap) Objects can be Instantiated
// delete keyword is used to manually delete the data which is stored in heap memory.

#include <iostream>
#include<string>

using string = std::string

class Entity {
	string name;
public:
	Entity: name("Unknown") {} // Constructed Initializer (Default Constructor)
	Entity(const string& name) : this.name(name) {} // Constructed Initializer (Constructor with arguments)

	const String& GetName() const { return name; }
};

int main() 
{
	//There are three ways to instantiate object
	// 1. Stack Memory Instantiation
	Entity entity1;
	std::cout << entity.GetName() << std::endl;
	Entity entity2("Manav");
	std::cout << entity3.GetName() << std::endl;

	// 2. Stack memory Instantiation
	Entity entity3 = Entity("Manav");
	std::cout << entity3.GetName() << std::endl;

	// Now There is a problem with stack memory instantiation as below
	Entity* e;
	{ // This is a scope like conditional or loops or functional scope
		Entity e2("Manav");
		e = &e2; // here e will refrence to address of e2 
		std::cout << (*e).GetName() << std::endl; // O/p - Manav
	}
	// Here the scope of e2 ends so e will still refrence to e2 address but not value of e2
	std::cout << (*e).GetName() << std::endl; // O/p - Null

	// 3. Heap Memory Instantiation
	Entity* entity4 = new Entity("Manav");

	// Now that above problem will be solved as heap memory intantiation means object will remain takes memory untill
	// we manually delete that object by using delete object_name
	Entity* e3;
	{
		Entity* e4 = new Entity("Manav");
		e3 = e4;  
		std::cout << (*e3).GetName() << std::endl; // O/p - Manav
	}
	// Here the scope of e4 ends but still e4 takes memory so e3 still refrence e4 address as well as value
	std::cout << (*e3).GetName() << std::endl; // O/p - Manav
	delete e3;
	
	std::cin.getline();
}