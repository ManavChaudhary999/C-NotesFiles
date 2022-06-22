// Namespace are used to avoid naming conflict.
// Let say we are using some standard library and it have function print()
// And we want to write our own print() function then because of same name compiler will throw error
// But we can use namespace to distinguish b/w standard library print() or our own print().

#include <iostream>

// We can also use nested namespaces
namespace Manav {
	namespace Data 
	{
		void Values() {}
		void Keys() {}
	}
	void Print(std::string& text) 
	{
		std::cout << "Manav::" << text << std::endl;
	}

	void Print_Again() {}
}

namespace Lisa {
	void Print(const char* text) 
	{
		std::cout << "Lisa::" << *text << std::endl;
	}
}


int main() 
{
	// Using namespace can cause problem
	// If we want to use Print() function of Manav namespace then compiler dont know which namespace function we are calling.
	using namespace Manav;
	using namespace Lisa;

	// Compiler dont know which namespace function it is, so it will automatically find best matching function which is Lisa namespace
	// because we are passing const char*
	Print("Manav"); 

	// That's why it is better to not use using namespace std; also

	// Now there are many ways we can implement namespaces.
	// Lets say we are using upper namespace method but we want to specify some function to be used only of that namespace.
	using namespace Manav;
	using namespace Manav::Data; // Nested Namespace
	using namespace Lisa;

	Print("Manav");
	Manav::Print_Again();
	Values();
	Keys();

	// Another Way of namespace implementation.
	using Manav::Print;
	using Manav::Data; // Nested Namespace

	Print("Manav");
	Manav::Print_Again();
	Data::Values();
	Data::Keys();

	// Also define aliases like-
	namespace M = Manav;
	namespace D = Manav::Data;

	M::Print();
	M::Print_Again();
	D::Keys();
	D::Values();

	// Or without namespace initialization
	Manav::Data::Keys();

	std::cin.get();
}