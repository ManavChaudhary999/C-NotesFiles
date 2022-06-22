// Array is a Data Structure which stores some data.
// Arrays is a collection of variable of same type.
// It is just a pointer.

// Arrays are of two types - Static Arrays and Dynamic arrays.
// Static Arrays are those whose size is static means u can't increase the size once it is filled.
// Dynamic arrays are those whose size can dynamically change based on the usage.
// Dynamic arrays are called vector in C++, and javascript and python have only dynamic arrays not static.

// Arrays are stored serially in memory address.
// Ex- If we want to store 5 int data var in an static array like - int arr[5];
// Then compiler will look 5 X 4(int size) = 20 bytes free memory to store data serially(close to each other).
// You can't store more than 20 bytes of data or can say you can only store upto last memory shell(17-20 bytes)

// Similar in dynamic array compiler will look upto double the initailzed size.
// Ex - if we have dynamic array like - std::vector<int, 5> arr;
// Then compiler will look 5 X 2 X 4(int size) = 40 bytes(double) free memory.
// If these 40 bytes( 5X2=10 shell) filled then compiler will look new 10 X 2 X 4 = 80 bytes(double) free memory.
// Then copy all the data of 40 bytes shell to these new 80 bytes shell and then delete previous 40 bytes shell.

// So array is a pointer which points to first shell or can say 0th index address.
// SO we can also traverse array like -
// *(arr + 1) -> arr[1]
// *(arr + 2) -> arr[2]
// *(arr + 3) -> arr[3]

#include<iostream>
#include<Array> // for standard array

void ArrayMain() 
{
	// 1.  Raw Arrays (c style arrays)

	int Example[5]; // Initializing with 5 size means total bytes will be 5 x 4 = 20 (1 int = 4 byte)

	int* p = Example; // Array is just a pointer, here p refrence to Example 0th index address

	Example[0] = 4; // setting value at index 0

	//Example is of 20 byte , each index is of 4 byte so 0 index starts from - 0 byte, 1 index - 4 byte, 2 - 8 , 3 - 12, 4 - 16.

	// here p is a int pointer and points to the address of 0th index of example that is 0th byte
	// p + 2 means p's address(which is Example 0th index address) + 4 x 2 which is 8 byte and 8th byte refrencing 2nd index
	*(p + 2) = 3; // means Example[2] = 3;

	//char is of 1 byte so (char*)p+8 = 0 + 1 x 8 which is 8 byte and 8 byte refrencing 2 index then casting to int coz array is of int then derefrencing
	*(int*)((char*)p + 8) = 4;// this is same as Example[2] = 4;

	//Initializing an array
	int Ex[5]; // It will be deleted automatically out of the scope coz it takes stack memory
	int* ptr = Ex[5]; // This is also same

	int Ran = new int[5]; // this will be alive till lifetime of a program coz it takes heap memory
	delete[] Ran; // to delete manually

	// Size of array
	// There is no method in C++ like other languages to get the size of raw array, but u can find out manually

	int Example[5];
	int count = sizeof(Example) / sizeof(int); // sizeof(Example) = 20(5 x 4) / sizeof(int) = 4

	// but u can't use this method to find out size of array initalized by new means int xyz = new int[5];

	static const int size = 5; // array only takes static const value as a size
	int Example[size];

	// 2. Standard Array

	std::array<int, 5> xyz;

	// Note- This takes only pointer reference of non primitve types.
	std::array<Player*, 5> players;
	xyz.size(); // to check the size of array
}