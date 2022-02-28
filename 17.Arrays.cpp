#include<iostream>

//#include<Array> // for standard array

//Arrays is a collection of variable of same type, it is just a pointer;

void ArrayMain() 
{
	// 1.  Raw Arrays

	int Example[5]; // Initializing with 5 size means total bytes will be 5 x 4 = 20 (1 int = 4 byte)

	int* p = Example; // Array is just a pointer, here p refrence to Example 0th index address

	Example[0] = 4; // setting value at index 0

	//Example is of 20 byte , each index is of 4 byte so 0 index starts from - 0 byte, 1 index - 4 byte, 2 - 8 , 3 - 12, 4 - 16, 5 - 20

	// here p is a int pointer and points to the address of 0th index of example that is 0 byte
	// p + 2 means p's address(which is Example 0th index address) + 4 x 2 which is 8 byte and 8 byte refrencing 2 index
	*(p + 2) = 3; // means Example[2] = 3;

	//char is of 1 byte so (char*)p+8 = 0 + 1 x 8 which is 8 byte and 8 byte refrencing 2 index then casting to int coz array is of int then derefrencing
	*(int*)((char*)p + 8) = 4;// this is same as Example[2] = 4;

	//Initializing an array
	int Ex[5]; // It will be deleted automatically out of the scope coz it takes stack memory
	int* ptr = Ex[5]; // This is also same

	int Ran = new int[5]; // this will be alive till lifetime of a program
	delete[] Ran; // to delete manually

	// Size of array
	// There is no method in C++ like other to get the size of raw array, but u can find out manually

	int Example[5];
	int count = sizeof(Example) / sizeof(int); // sizeof(Example) = 20(5 x 4) / sizeof(int) = 4

	// but u can't use this method to find out size of array initalized by new means int xyz = new int[5];

	static const int size = 5; // array only takes static const value as a size
	int Example[size];

	// 2. Standard Array
	
	std::array<int, 5> xyz;

	xyz.size(); // to check the size of array
}