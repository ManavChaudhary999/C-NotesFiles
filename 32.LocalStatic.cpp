// local static means the var will have lifetime of whole program and access only in scope(locally).

#include <iostream>

int j = 0;

void Function() 
{
	static int i = 0;

	i++;
	j++;
	std::cout << i << std::endl;
	std::cout << j << std::endl;
}

int main() 
{
	Function(); //i = 1 , j = 1
	Function(); //i = 2 , j = 2
	Function(); //i = 3 , j = 3
	i = 7; // can't access
	j = 8;
	Function(); //i = 4 , j = 9
	Function(); //i = 5 , j = 10

	std::cin.get();
}