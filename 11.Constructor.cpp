// Constructor is a special type of method which is called everytime we instantiate object.
// Constructor must match the name with class.
// Classes have default constructor already but there functionality differs by language type.
// Like in java or C# primitive type have constructor like this-
	//construtor() 
	//{
	//	X = 0;
	//	Y = 0.0f;
	//}

// But in C++ default constructor is like this - it didn't initialize anything
	//constructor()
	//{
	//}

// So we have to manually initailze default constructor for all primitive types in C++.

#include<iostream>

class Player() 
{
public:
	int X, Y; // if any instance of this class try to access them then error occurs that u can't access uninitialized vars

	void Print() 
	{
		std::cout << X << " : " << Y << std::endl; // this will print "address allocated" to these vars coz we didn't initialize them
	}
}
// To overcome above problem constructor are used, to initalize the vars.
class Entity() 
{
	public:
		int X, Y;

		Entity() // Constructor type 1 (default with no arguments)
		{
			X = 0;
			Y = 0;
		}

		/*Entity(int x, int y) // Constructor type 2 (passed arguments)
		{
			X = x;
			Y = y;
		}*/

		~Entity() {} // Destructor - called after the object is destroyed or out of scope

		void Print() 
		{
			std::cout << "X: " << X << " Y: " << Y << std::endl;
		}
};

//let say we want only static fucn to be used by class members and we don't want its instances to be created 
// then we dont need constructor, So there are two ways to delte default constructor
// make private constructor or delete default constructor
class Log()
{
	private:
		Log() {} // make constructor private

	public:

		Log() = delete; // delete the default constructor

		static void Write()
		{
		
		}
};

void MainConstructor()
{
	Entity e1;
	e1.Print();
	//Entity e2(5, 10);

	Log::Write(); // access of static method without creating multiple instances
	//Log l; //Now this will not work coz we deleted the default constructor
}