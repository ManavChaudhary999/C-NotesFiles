// new is a operator used as a keyword to allocate data in heap memeory.
// new returns void pointer(void*) with allocating size in heap memory based on data type.
// delete is a operator used to delete the data in heap memory.
// delete is also called destructor 
// Always or must use delete keyword to deallocate the memory of the var created by using new keyword.
#include<iostream>

class Entity {
	int a, b;

public:
	Entity() : a(0), b(0) {} // default Construtor
	Entity(const int& newA, const int& newB) // setter Constructor
		: a(newA), b(newB) {}
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
	// new basically calls the malloc function passing the sizeof data_type to create memory of some byte size
	// and then malloc returns void* which is typecast by new into datatype we passed, so we can manually do this like below 
	// The only difference is that with new we can call the constructor but not with malloc
	Entity* e2 = (Entity*)malloc(sizeof(Entity));

	// This is called placement new, here we are manually allocating memory address in heap memory
	// So e3 will be allocated to a memory address of 'a' in heap
	// but e3 size must be smaller or equal then 'a' size which is int(4 byte) to allocate memory address of a.
	Entity* e3 = new(a) Entity();

	// Exercise
	int a[2] = { 1,3 };

	Entity* player3 = new(a) Entity(5, 10); // this will set a[0] = 5 and a[1] = 10;

	std::cout << sizeof(Entity) << std::endl; // 8
	std::cout << sizeof(a) << std::endl; // 8
	std::cout << sizeof(player3) << std::endl;// 4 because player3 is a pointer points to address of a[0] which is of 4 bytes.
	std::cout << a << std::endl; // a address
	std::cout << player3 << std::endl;// player address same as a
	std::cout << a[0] << " : " << a[1] << std::endl; // 5 : 10
	std::cout << *player3 << std::endl; //5 : 10

	std::cin.getline();
}