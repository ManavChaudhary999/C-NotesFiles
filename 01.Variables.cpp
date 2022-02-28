#include<iostream>

// Variables are the memory adress that store some value based on data type.
// These memory address can be stored on Stack or Heap memory.
// Data Types can be primitive or non-primitive
// Primitive Data Types have some default byte size like int - 4, char - 1, long - 4(usually), short - 2, long long - 8, float-4, double-8, bool-1
// But These byte size depend on compiler
// Int is of 4 byte means 32 bits, 1 bit is used for signed(+,-) so 2^31 value can be stored which is approx 2 billion
// we can use unsigned before any data type to remove signed bit usage like
// using unsigned int to store 32 bit value meaning 2^32 2billion X 2.
// To check size of any data type we can use sizeof data type or sizeof(datatype).

int main() 
{
	// We normally think we can only assign some specific value to primitive data type like 
	char variable = 'A';
	// But we can assign any value to any primitive data type like
	char var = 65;

	// Both have output same becoz cout will read value as char
	std::cout << variable << std::endl; // OP: A
	std::cout << var << std::endl;// OP: A

	int a = 65;
	std::cout << (char)a << std::endl;// OP: A, cout will read value as char

	// Both are double even though we use float data type, to technically define float we have to use f or F at the end of the value
	float b = 5.5;
	double c = 5.8;

	bool is = false; 
	std::cout << is << std::endl;// OP: 0, coz there is no such thing as true or false so compiler only read false as 0
								// true as anything greater than 0 but under 1 byte (generally 1)
	return 0;
}