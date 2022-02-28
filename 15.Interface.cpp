// Pure Virtual Function are called Inteface in c++
// Pure Virtual Function are called Abstract or Interface method in java or C#.
// Pure virtual func cant be implemented in base class and has to be instantiated in sub-class.
// Why Use?
// Ans - Some Function can't be described in base class they may differ in different sub-classes.

#include <iostream>
#include <String>

class Printable() // Interface
{
public:
	virtual std::string GetClassName() = 0; // = 0 means pure virtual func
};

class Entity : Printable {
public:
	std::string GetClassName() override // Interface so that must be implemented
	{
		return "Entity";
	}
};

class Player : public Entity
{
public:

	std::string GetClassName() override // this may inherited func from entity class but it is a pure virtual func of printable class so that it must be implemented in this class also.
	{
		return "Player";
	}
};

class A : Printable 
{
public:
	std::string GetClassName() override // Interface so that must be implemented
	{
		return "A";
	}
};

// Lets Say we have a function which only take argument of a class instance which must have GetClassName()
void Print(Printable* obj) 
{
	std::cout << obj->GetClassName() << std::endl;
}

int main() 
{
	Entity e;
	std::cout << e.GetClassName() << std::endl; // output: Entity
	Print(e); // Output - Entity

	Player p;
	std::cout << p.GetClassName() << std::endl; // output: Player
	Print(p); // Output - PLayer

	A a;
	Print(a); // Output - A
}