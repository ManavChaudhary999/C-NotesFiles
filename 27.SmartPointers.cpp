// Smart Pointers are type of pointers used to wrap the code for memory scope
// if we have to create data in heap memory we have to use new and delete keyword for deletion.
// But by using smart pointers we don't have to write that.
// Based on type of smart pointer the lifetime or memory of data is automatically freed.
// 
// Type of smart pointers -
// 1. unique smart pointers - it is a scoped pointer, i.e. it automatically calls delete when goes out of scope.
// As name suggests unique pointer must be unique, i.e. no other pointer should refrence same memory address, so that whenever
// the object or data goes out of scope that must be deleted hence no other pointer can refrence that address.

// 2. Shared Pointer - it makes counting of no of copy of same address or counts no of refrence of same address and when a one refrence
// dies or deleted or freed  then it minus that from ref count and once the counting becomes zero then the memory address gets freed.
// So basically, if one shared pointer copied to other shared pointer it increase the red count.

// 3. Weak Pointer - It doesn't increase the ref count if shared pointer copied to weak pointer.

#include <iostream>
#include <memory>

class Entity {

public:
	Entity() {
		std::cout << "Objet Created" << std::endl;
	}

	~Entity() 
	{
		std::cout << "Object Destroyed" << std::endl;
	}

	void Print() 
	{
	}
};

int main() 
{
	// unique pointer
	{
		// We can't do like this coz unique pointer constructor is explicit(i.e. no implicit conversion) but here we using new Entity()
		// and saying to compiler to implicitly convert this into unique pointer.
		std::unique_ptr<Entity> entity = new Entity(); 
		
		std::unique_ptr<Entity> entity(new Entity()); // Will work
		std::unique_ptr<Entityt> entity = std::make_unique<Entity>(); // But this is a prefered way for throw exception
		std::unique_ptr<Entity> entity2 = entity; // Not Work cause u can't copy unique pointer

		(*entity).Print(); // Or
		entity->Print();
	}
	// here Entity destroyed will print for instance entity pointer as it was created and stored in stack so out of scope it is deleted.

	// Shared Pointer
	{
		std::shared_ptr<Entity> e;
		{
			std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
			e = e2; // copying one shared pointer to other shared pointer hence increasing the ref count to 2 
		}
		// ref count become 2-1 = 1.
		// here Entity destroyed will not print for shared pointer e2 coz ref count still is 1 not zero.
	}
	// ref count become 1-1 = 0
	//here Entity destroyed will print for shared pointer e
	
	// Weak Pointer
	{
		std::weak_ptr<Entity> e; 
		{
			std::shared_ptr<Entity> e2 = std::make_shared<Entity>();
			e = e2; // this will not increase ref count
		}
		// ref count become 1-1 = 0
		//here Entity destroyed will print for shared pointer e
	}

	std::cin.get();
}