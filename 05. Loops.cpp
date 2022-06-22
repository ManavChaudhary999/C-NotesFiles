#include <iostream>

int main() 
{
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Hello World" << std::endl;
	}

	// This will also print 5 times
	int j = 0;
	bool condition = true;
	for (; condition; ) 
	{
		std::cout << "Hello World" << std::endl;
		j++;
		if (!(j < 5)) // j >= 5
			condition = false;
	}

	// another for loop
	int values[5];
	for (int value : values)
		std::cout << value << std::endl;
}