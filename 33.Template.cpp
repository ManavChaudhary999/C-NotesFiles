// Template function or class or any behaviour wouldn't exist untill we call it or instantiate it.
// So basically template are executed on compile time.

// NOTE - Dont use tempate too often, only for specific things.

#include <iostream>

// To Make Print function take argument of any type we have to make its overload but with template we dont have to do that because
// compiler will do that for us.
// If we call template function with different argument types then it will be defined or copied or overloaded for that type.

// To create Template, use template keyword with typename(generic type).
template<typename T>
void Print(T value) // This Print function wouldn't exist untill we call it because it is just a template.
{
	std::cout << value << std::endl;
}

// Many C++ Classes are written with templates.
// Here we are creating our own Array class.

template<typename T, int N>
class Array {
private:
	T array[N];
public:
	int GetSize() { return N; }
};

int main() 
{
	// Use like this if we know that by passing any value function will work.
	Print(6);
	Print("manav");

	Print<int>(7);
	Print<std::string>("Manav");
	Print<std::string>(20); // not work show error

	Array<int, 5> a;
	Array<std::string, 5> b;

	a.GetSize();
	b.GetSize();

	std::cin.get();
}