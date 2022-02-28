#include <iostream>

int main() 
{
	for (int i = 0; i < 5; i++) 
	{
		std::cout << "Hello World" << std::endl;
	}

	int j = 0;
	bool condition = true;
	// This will also print 5 times
	for (; condition; ) 
	{
		std::cout << "Hello World" << std::endl;
		i++;
		if (!(i < 5))
			condition = false;
	}
}