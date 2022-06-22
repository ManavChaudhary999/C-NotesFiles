// Functions are just CPU instruction stored in binary when we compile our program.
// But with Function Pointers we can assign functions to varaibles.
// Or also pass function as parameter into other function.

// Usage
// Whenever we want function to be called at some specific point, function pointer works well with lambdas.

#include <iostream>
#include <vector>

void HelloWorld(int a) 
{
	std::cout << "hello World with a: " << a << std::endl;
}

// Useful Case of function pointers

// Lets Say we have function ForEach which take array and do something with that array.
// Now that something is defined by any function.
void PrintValue(int a) 
{
	std::cout << "Value: " << a << std::endl;
}

void ForEach(const std::vector<int>& arr, void(*PrintFunction)(int)) 
{
	for (int x : arr)
		PrintFunction(x);
}

int main() 
{
	// Type of this Function var is void(*Function)(int);
	auto Function = HelloWorld; // This is similar to &HelloWorld but we dont have to use & as it will implicitly be converted.
	Function(8); // O/P- hello World with a: 8

	// So we can also use like this
	void(*Manav)(int) = HelloWorld;
	
	// OR like this
	void(*Manav)(int);
	Manav = HelloWorld;
	Manav(7);

	// Or also using typedef
	typedef void(*HelloWorldType)(int);
	HelloWorldType x = HelloWorld;
	x(6);

	std::vector<int> arr = { 2,4,5,12,3,4 };
	ForEach(arr, PrintValue);

	std::cin.get();
}