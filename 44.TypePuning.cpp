// Type Puning is a process of manuplation or modifying data type or data set.
// There are two types - implicit conversion or explicit conversion.

#include<iostream>

struct Vector2 {
	int x, y;

	int* GetXPositon() 
	{
		return &x;
	}
};

int main() 
{
	int a = 50; // byte allocation at ath address will be 32 00 00 00 (4 bytes)(32 is a hexadecimal value of 50)

	// It will implicitly convert int to double but the byte allocation will be different because it is converting 'a' value not address
	double b = a; // byte allocation at bth address will be 00 00 00 00 00 00 49 40(8 bytes) which is weird.
	std::cout << b << std::endl; // O/P - 50

	// So to convert address of a not only value
	// here conveting ath address into double pointer and then dereferencing to get value
	double& value = *(double*)&a; // byte allocation at bth address will be 32 00 00 00 cc cc cc cc(8 bytes).
	std::cout << value << std::endl; // O/P - 9.9... some weird

	// but here we just convert 4 byte int memory address into 4 byte double address
	// So it will cause problem if we set value greater then 4 byte like
	value = 5.6;

	// Non - Primitives
	Vector2 v = { 4, 5 }; // byte allocation at vth address will be  04 00 00 00 05 00 00(4+4 bytes).

	// Conveting into arrays because arrays are also the collection of data stored serially in memory address.
	// And here struct also have byte allocated in same address of two data types.
	int* arr = (int*)&v;
	std::cout << arr[0] << " , " << arr[1] << std::endl; // O/P- 4 , 5

	// here convering address of v in char* then adding 4 to get 2nd byte address or can say 2nd index,
	// then converting char* into int* then dereferencing it to get value.
	int value = *(int*)((char*)&v + 4);
	std::cout << value << std::endl; // O/P - 5

	int* position = v.GetXPositon();
	position[0] = 2; // changing value of x
	position[1] = 10; // changing value of y
	position[2] = 1; // stack overflow error because there is no third var of struct

	std::cin.get();
}