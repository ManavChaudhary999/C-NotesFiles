// There are two types of programing 1. Mathematical 2. Logical
// Logical use if else conditions but may be slow
// Mathermatical is faster but that doesn't mean we shouldn't use if else
// Every Project use if else but use as few as you can because it slow down proccessing
// Condition Always work with 0(false) or 1(true).

#include <iostream>

int main() 
{
	int x = 6;
	bool isfive = x == 5;
	if (isfive) 
	{
		// then do this
	}
	if (x) // means x is not 0 
	{
		// then do this
	}
	if (0) // not gonna run ever
	{
		// then do this
	}
	if (1) // run always
	{
		// then do this
	}
	if (10) // not gonna run
	{
		// then do this
	}

	// Nested if else
	if(x > 7)
	{
			// do something
	}
	// This and below this are same , there is no such else if combine keyword they are just else and if
	else if(x > 5)
	{
			// do something
	}
	else 
	{
		if (x > 3) 
		{
				// do something
		}
	}
	else 
	{
	}

	std::cin.get();
}