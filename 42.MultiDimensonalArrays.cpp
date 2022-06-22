// Multi-Dimensonal Arrays are the collection of arrays.
// like 2-D Arrays are the arrays of arrays.
// like 3-D Arrays are the arrays of arrays of arrays.
// So basically we have multiple pointer address in buffer memory which points to a particular array.

#include<iostream>

int main() 
{
	int* arr = new int[50]; // this is an actual array of 200(50 X 4) bytes.
	arr[2] = 4;

	// 2D ARRAYS
	// this is an pointer or address in memory having 4 bytes of each, (total 200 bytes).
	// This is pointing to address of actual arrays.
	// Like [0] is first array, [1] is second array, [2] is third array.....so on.
	int** arr2d = new int*[50]; 
	for (int i = 0; i < 50; i++)
		arr2d[i] = new int[50]; // now we are setting actual arrays to specific address where 2d array points.
	// Setting or Getting
	// here first[n] is address of particular(one of the 50 arrays) not a integer value.
	// and second[m] is actual address of integer value.
	arr[0][0] = 2;
	arr[0][1] = 2;
	arr[0][2] = 2;
	arr[1][3] = 4; // setting second array's third index value
	
	// Deleting or Freeing memory
	// this will delete pointers holding address of actual arrays not actual arrays.
	// So we still have 10000 bytes(200(50 X 4)  X 50) of memory.
	// we only deleted 200 bytes of pointer memory
	delete[] arr2d;

	// So to delete 2d arrays fully, we use
	for (int i = 0; i < 50; i++)
		delete[] arr2d[i]; // deleting actual arrays
	// and then
	delete[] arr2d;


	// 3D ARRAYS
	int*** arr3d = new int**[50]; // 3 pointers - pointer to pointer to pointer
	for (int i = 0; i < 50; i++)
	{
		arr3d[i] = new int*[50]; // here setting new address which 3d array points 
		for (int j = 0; j < 50; j++) 
		{
			//arr3d[i][j] = new int[50]; // here setting actual arrays
			// another way
			int** ptr = a3d[i]; 
			ptr[j] = new int[50];
		}
	}

	
	// Setting or Getting
	// here first[n] is address of particular(one of the collection(50 array) of arrays) not a integer value.
	// and second[n] is address of particular(one of the 50 arrays) not a integer value.
	// and third[n] is actual address of integer value.

	arr3d[0][0][0] = 2;
	arr3d[0][0][1] = 2;
	arr3d[0][1][1] = 2; // sets value 2 at 1st index of, 1st array out of 50 of, 0th out of 50 collection.
	arr3d[1][2][2] = 3; // sets value 3 at 2nd index of, 2nd array out of 50 of, 1th out of 50 collection.

	// Now there is a performance problem with multi dimensonal arrays.
	// As multi arrays uses heap memory, and we alreadt know heap memory acllocates memory address in random location unlike stack
	// so lets take ex of 2d arrays
	int** a2d = new int* [5];
	for (int i = 0; i < 5; i++)
		arr2d[i] = new int[5];

	// here after first i iteration we are accessing another address which points to actual address.
	// So after i iteration complete compiler have to access address presented at some random memory address not in serial manner like
	// stack, so here it slows down the performance
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			a2d[i][j] = 3;
		}
	}
	
	// Solution - use normal arrays instead of multi arrays like-
	int* arr = new int[5 * 5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			// (j * 5) will give 0, 5 ,10, 15, 20 th adress
			// i + will give 0-4, 5-9, 10-14, 15-19, 20-24
			// hence working like 2d arrays.
			arr[i + j * 5] = 2;
	}

	std::cin.get();
}