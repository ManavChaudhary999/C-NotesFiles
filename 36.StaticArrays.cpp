// There are two ways we can define or use static arrays.
// 1. Raw Arrays or C literal Arrays(discussed in 17.Arrays) 2. Standard Arrays

// Both are same in proccessing.

#include <iostream>
#include <Array>

// So how do we pass the size argument in array<int , size> like this
void PrintArray(std::array<int ,5>& arr)
{
	for(int i = 0; i< arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

// There are following solutions below-
// 1. Use Initializer list or can say that default argument value
void PrintArray(std::array<int, 5>& arr = {1,2,3,4,5})
{
	for(int i = 0; i< arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
// 2. Using Template
template<typedef T, int size>
void PrintArray(std::array<T, size>& arr)
{
	for(int i = 0; i< arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}
// 3. Using auto keyword
void PrintArray(const auto& arr)
{
	for(int i = 0; i< arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

int main() 
{
	std::array<int, 5> arr;

	// If use Template
	PrintArray<int, arr.size()>(arr);

	// If use auto keyword
	PrintArray(arr);

	std::cin.get();
}