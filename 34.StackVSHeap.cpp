// Our Program usually divided into two memories - Stack and Heap.
// These both memories uses or located in ram.
// Stack has predefined size usually around 2mb.
// Heap has also kind of predefined size but can be increased.

// Difference?
// These both are stored in same location(ram) and work same but the difference is memory allocation.
// Stack works faster than Heap.
// How?
// Stack stores memory address stack wise meaning the variables stored serial wise so stack pointer just shift bytewise which is
// literally one cpu instrution.
// And also stack memory gets freed out of the scope so stack pointer automatically points where it starts.
// Where as Heap stores memory random or based on requsting size it finds free memory or space where it can give requested size
//  so the pointer has to find correct or matching memory address in heap to get specific address value.
// And also heap memory gets freed if we use delete keyword untill then it fills space.

int main() 
{
	{
		// Stack Memory
		// int is of 4 bytes and cc cc cc cc means address isn't allocated.
		int value = 5; // lets say it stores at address 50 00 00 00 cc cc cc cc ..............

		// Now array is 12 bytes so it stacks 12 bytes + 8 byte for spacing (cc cc cc cc X 2).
		int array[3];// address will be cc cc cc cc cc cc cc cc cc cc cc cc (cc cc cc cc X 2) 05 00 00 00 cc cc cc cc ........
		array[0] = 2;// address will be 02 00 00 00 cc cc cc cc cc cc cc cc (cc cc cc cc X 2) 05 00 00 00 cc cc cc cc ........
		array[1] = 4;// address will be 02 00 00 00 04 00 00 00 cc cc cc cc (cc cc cc cc X 2) 05 00 00 00 cc cc cc cc ........
		array[2] = 3;// address will be 02 00 00 00 04 00 00 00 03 00 00 00 (cc cc cc cc X 2) 05 00 00 00 cc cc cc cc ........

		// 8 byte for spacing(cc cc cc cc X 2) for every new var.
		int another = 8;// address will be 08 00 00 00 (cc cc cc cc X 2) 02 00 00 00 04 00 00 00 02 00 00 00 cc cc cc cc 05 00 00 00 cc cc cc
						//cc ........

	} // After Out of scope stack pointer automatically points to initial(starting) address.

	// Heap Memory
	int* hvalue = new int; // Random Address
	*hvalue = 5;

	int* harray = new int[3]; // Random Address
	*harray[0] = 2;
	*harray[1] = 4;
	*harray[2] = 3;

	delete hvalue;
	delete harray[];

	std::cin.get();
}