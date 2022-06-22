// Inhertiance is used to derive methods or functionality of base class into sub-class(derived class)
// Sub Class can inhertis only public and protected members of Base class.
// It is used to remove code dulpication.
// How?
// Ans - we derive base class methods into sub class so we either gonna modify them or make them new, so we don't have to write 
// those functionality again and again.

// Note- When sub class extends base class then it become of both types - sub class type and base class type
//1. Sub class : public Base class means sub inherting base public and protected data members and making them public in its own class
//2. Sub class : private Base class means Sub inherting Base public and protected data members and making them private in its own class

#include <iostream>
#include<string>

class Entity{
	public:
		int X, Y;

		void Move(int x, int y) 
		{
			X += x;
			Y += y;
		}
};

// Extending Entity class non-private functionality into Player class and making public
class Player : public Entity
{
	public:
		char* Name;

		void Print()
		{
			std::cout << Name << std::endl;
		}
};

// Extending Entity class non-private functionality into Player class and making private
class Npc : private Entity
{
};

// Inherits Npc non-private data members but not entity as they were made private in npc
class AI : public Npc {}; 

void MainInherit() 
{
	Player p; // It is also a Entity and Player type
	p.Move(10, 20); // Entity move function in player
	p.Print();

	Entity e = new Player(); // Player is also Entity type

	// Not Gonna Work
	Player player = new Entity(); // Entity is not Player Type

	AI a;
	//a.X = 5; // this will not work as X is private in Npc
}