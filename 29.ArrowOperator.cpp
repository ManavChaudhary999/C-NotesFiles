// Arrow operator is used to derefrence the class pointer to access data members.

#include<iostream>

class Entity {
public:
	int x;

	void Print() const { std::cout << "Hellod World" << std::endl; }
};

class ScopedPtr 
{
private:
	Entity* m_Obj;

public:
	ScopedPtr(Entity* entity)
		: m_Obj(entity)
	{}

	~ScopedPtr() 
	{
		delete m_Obj;
	}

	Entity* GetObject() { return m_Obj; } // one way returning object pointer

	Entity* operator->() const // Better way
	{
		return m_Obj;
	}
};

int main() 
{
	Entity e;
	Entity* ptr = &e;
	ptr->Print(); // using arrow operator

	ScopedPtr entity = new Entity();
	entity.GetObject()->Print(); // If using method, but we can write our own arrow operator so that we dont have to do this

	entity->Print(); // arrow operator overload

	std::cin.get();
}