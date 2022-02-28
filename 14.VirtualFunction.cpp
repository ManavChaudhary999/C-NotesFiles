// Virtual Function allow us to ovveride the function
// It is used in the concept of inheritance.
// Virtual function of base class can be ovverided in sub class.
// Keyword: virtual and ovveride(not required but use for conviction).
// How it Works?
// Ans - virtual keyword mark the function of base class in V-table(records).
// ovveride keyword check the function of sub-class in V-table so that it can match.
// Note- Due to these two steps virtual funtion can cause performance issues but negligble.

#include <iostream>
#include<string>

// Without Virtual Function
/*class Entity {
public:
	
	void Print()
	{
		std::cout << "Entity" << std::endl;
	}
};

class Player : public Entity
{
public:
	char* Name;

	void Print()
	{
		std::cout << Name << std::endl;
	}
};

int main() 
{
	Entity* e;
	e->Print(); // Print "Entity"

	Player* p; // It is also a entity type
	p->Name = "Manav";
	p2->Print(); // inherited Function of Entity which modified in Player

	Entity* e2 = p; // p is also a entity type
	e2->Print(); // Print "Entity"
}*/

// Using Virtual Function
class Entity{
public:

	virtual void Print()
	{
		std::cout << "Entity" << std::endl;
	}
};

class Player : public Entity
{
public:
	char* Name;

	void Print() override
	{
		std::cout << Name << std::endl;
	}
};

int main() 
{
	Entity* e;
	e->Print(); // Print "Entity"

	Player* p; // It is also a entity type
	p->Name = "Manav";
	p2->Print(); // inherited virtual Function of Entity which is override in Player

	Entity* e2 = p; // p is also a entity type
	e2->Print(); // Print "Manav" because overrided in player.
}