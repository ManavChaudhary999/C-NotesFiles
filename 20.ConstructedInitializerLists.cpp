#include<iostream>
#include<string>

class Example {
private: 
	int x;
public:
	Example() 
	{
		std::cout << "Created Without X" << std::endl;
	}

	Example(const int y) 
	{
		x = y;
		std::cout << "Created X:" << x << std::endl;
	}
};

class Entity {
private:
	int m_Score;
	std::string m_Name;
	Example ex;

public:
	//Entity() // 1 way, default value constructor
	//{
	//	m_Name = "Unknown";
	//	ex = Example(8); // this will create two objects one in private during initializing and second here, so to overcome that we use member
	//	intializer lists
	//}

	//list should be in order equal to their initalizing order
	Entity()
		: m_Score(0), m_Name("Unknown"), ex(Example(8)); // other way, Member(Constructor) Initializer Lists 
	{
	}

	/*Entity(const std::string& name) 
	{
		m_Name = name;
	}*/

	Entity(const std::string& name)
		: m_Name(name)
	{
	}

	const std::string GetName() const
	{
		return m_Name;
	}
};

int MainMemeberLists() 
{
	Entity e1;
	std::cout << e1.GetName() << std::end;

	Entity e2("manav");
	std::cout << e2.GetName() << std::endl;

	return 0;
}