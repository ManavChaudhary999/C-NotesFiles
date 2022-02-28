// this is the pointer to a current object instance that a method belongs to.
// this can be only used in member function, i.e. class method.

#include<iostream>
#include<string>

void PrintWithPointer(const Entity* e);
void PrintWithRefrence(const Entity& e);

class Entity {
public:
	int x, y;

	// How c++ compiler done this
	Entity(int x, int y) 
	{
		// When we use this keyword then thats what it means
		Entity* e = this; // this is a pointer
		e->x = x; // -> arrow operator are used by pointer var

		// This is actually how we use
		this->x = x; // same as above two line
		(*this).x = x; // or can also use like this way
		this->y = y;
		(*this).y = y;

		// Useful case of this
		PrintWithPointer(this); // As this is a pointer
		PrintWithRefrence(*this); // derefrencing this to pass as a refrence
	}
	// As we discussed in const lecture , const method dosn't allow non const var
	int GetX() const  
	{
		// Other Useful case of this
		// Entity* e2 = this; // can't be done cause not const var aren't allowed
		const Entity* e = this; // only const allowed
		e->x = x;// can't be done as e is const
		return x;
	}
};

void PrintWithPointer(const Entity* e) {// Printing}
void PrintWithRefrence(const Entity& e) {// Printing}