// Stack is a memory storage that stores data or memory in form of stack.
// In stack memory data is limited to scope, i.e. u can't access the stack memory data outside of the scope.

#include<iostream>
#include<string>

class Entity {
public:
	Enity()
	{
		std::cout << "Entity Created" << std::endl;
	}
	~Enity()
	{
		std::cout << "Entity Destroyed" << std::endl;
	}
};
class ScopedPtr {
public:
	Entity* e;

	ScopedPtr(Entity* entity)
		: e(entity)

	~ScopedPtr()
	{
		delete e;
	}
};

int* CreateArray() 
{
	int arr[40]; // created in stack memory
	return arr; // Not gonna work cause array lifetime is only in this scope.
}

int main() 
{
	{
		Entity e; // Here Entity Created will print as we created entity instance here
		
		Entity e1 = new Entity(); // Here Entity Created will print as we created instance e1 here
	
		ScopedPtr e2 = new Entity(); // here although we are using new but ScopedPtr is created in Stack memeory and new Entity() is basically a implicit conversion.
	}

	// here Entity destroyed will print for instance e as e created and stored in stack so out of scope it is deleted.
	// But here Entity destroyed will not print for instance e1 as e1 created and stored in heap so it will not be deleted.
	delete e1; // we have to manually delete the e1.
	std::cin.get();
}