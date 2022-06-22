// Lambdas are anonymous functions.
// Lambdas are used as a function without having to define the function.

// Usage
// Wherever you using function pointer.

#include <iostream>
#include <vector>
#include <functional>

// Using Raw Pointer Function.
void ForEach(const std::vector<int>& arr, void(*PrintFunction)(int))
{
	for (int x : arr)
		PrintFunction(x);
}
// Using Standard Function Library
void NewForEach(const std::vector<int>& arr, std::function<void(int)>& PrintFunction)
{
	for (int x : arr)
		PrintFunction(x);
}

int main()
{
	std::vector<int> arr = { 2,4,7,2,8 };

	auto lambda = [](int value) {std::cout << "Hello World with value: " << value << std::endl; };

	ForEach(arr, lambda); // 1 Way
	ForEach(arr, [](int value) {std::cout << "Hello World with value: " << value << std::endl; }); // 2 Way, or also use like this

	// Now in lamda expression, [] takes outside variables as an argument which we want to be used in lambda function
	int a = 10;
	int b = 20;

	// we can pass outside var as a value or by reference.
	auto random = [a, &b](int value) {std::cout << "Hello World with value And outside value: " << value + a + b << std::endl; };

	// Or we can pass = to pass every outside var as value
	auto random = [=](int value) {std::cout << "Hello World with value And outside value: " << value + a + b << std::endl; };
	
	// Or we can pass & to pass every outside var as reference
	auto random = [&](int value) {std::cout << "Hello World with value And outside value: " << value + a + b << std::endl; };

	// Note - This wont work because we are using void(*function)(int) or can say raw pointer function in ForEach Parameter.
	ForEach(arr, random); // Wont Work.

	// To make sure it will work then we have to use standard function library.
	NewForEach(arr, random); // Now this will work.

	// Also we can use mutable to modify outside var.
	auto random = [&](int value) mutable {
		std::cout << "Hello World with value And outside value: " << value + a + b << std::endl; 
		a = 10; // Modifying outside variable.
	};

	// Best Use Case of Lambdas
	// Lets say we want a no > 3 in arr vector;
	// We can use standard library function std::find_if which takes first index and last index and then function to define behaviour.
	// So here we can use lambda function instead of normal function define then declare it here.
	auto it = std::find_if(arr.begin(), arr.end(), [](int value) { return value > 3; }); // This will return first matching value
	// This will return iterator or can say pointer value, So have to derefernce this.
	std::cout << *it << std::endl; // o/p - 4;
	std::cin.get();
}