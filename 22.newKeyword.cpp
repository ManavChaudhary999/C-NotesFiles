// new is a operator used as a keyword to allocate data in heap memeory.
// new returns void pointer(void*) with allocating size in heap memory based on data type.
// delete is a operator used to delete the data in heap memory.
// delete is also called destructor 
// Always or must use delete keyword to deallocte the memory of the var created by using new keyword.
#include<iostream>

class Entity {
	int var;
};

int main() 
{
	int* a = new int; // 4 bytes
	int* arr = new int[50] // 200 bytes 
	Entity* entity = new Entity; // 4 bytes
	Entity* eArr = new Entity[50]; // 200 bytes

	delete a;
	delete[] arr; // if allocate using [] then also delete using []

	Entity* e = new Entity();
	// new basically calls the malloc function passing the sizeof data type to create memory of some byte size
	// and then returns void*, so we can manually do this like below 
	// The only difference is that with new we can call the constructor but not with malloc
	Entity* e2 = (Entity*)malloc(sizeof(Entity));

	// This is called placement new, here we are manually allocating memory address in heap memory
	// So e3 will be allocated to a memory address in heap
	// but e3 size must be smaller or equal then a size
	Entity* e3 = new(a) Entity();

	std::cin.getline();
}