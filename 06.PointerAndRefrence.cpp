// Pointers are the var that store some memory address.
// Pointers can be initailzed as datatype* var_name = new datatype or &othervar or otherpointervar
// Refrence points to a memory address of a var.
// Reference can be initialized as datatype& var_name or to point var address use &var_name.
// Reference are used to prevent copying of data type or value.

// DoublePointer are the pointer that stores address of a pointer var.
// Explain: pointer stores some address but pointer var is also a var so it has its own address also, To points that address(pointer var address) we use double pointer.

#include <iostream>

#define LOG(x) std::cout<< x << std::endl

// If a class is accessed as pointer then to use its data members we use -> intead of .
// Ex- class* A; A->sum(); instead of A.sum();

void Increament(int* val) // pass by address
{
	(*val)++; // dereferencing than increamenting
}
void Increament2(int& val) // pass by reference
{
	val++;
}

class Entity {};

void MainPointer() 
{
	// NOTE : Refrence or other pointer has to be assigned during pointer initializing, if not use heap address like (new int) 
	// NOTE: *varname is used to access the value of pointer var or can say that defrence the pointer var
	// NOTE: If we use pointer var without * (like - varname) it will points or give the address of var not the actual var value
	// NOTE: &is used to refrence or points the address of normal var

	//here p is a pointer var which stores the address of other n.
	int n = 5;
	int* p = &n; // store or points the address of n
	*p = 3;
	
	int* j = new int; // new address
	int* x, *y, *z;// To initialize multiple pointer

	// print the same address
	LOG(p);
	LOG(&n);
	// print the same value
	LOG(*p);
	LOG(n);

	Increament(&n);
	Increament2(n);

	// Class Pointer
	Entity e;
	Entity* e2 = &e;
	// to access the value of e2 pointer we need to derefrence it
	(*e2).(class_method); // normal derefrence
	Entity& entity = *e2; // another way of derefrence
	e2->(class_method); // or using arrow operator

	// Double Pointer
	
	int* a = new int; // new address points to a but a have its own address because it is also a var.
	*a = 9; // dereferencing a and setting its data value.
	int* c = a; // pointing or storing the value of a (which is some address a points to).
	int** b = &a; // storing actual address of a by using double pointer.

	std::cout << "a pointer address: " << a << std::endl;
	std::cout << "b pointing a's pointer address: " << *b << std::endl;

	std::cout << "a's own address: " << &a << std::endl;
	std::cout << "b pointing a's own address: " << b << std::endl;
	
	std::cout << "b's own address: " << &b << std::endl;

	std::cout << "a pointer address value: " << *a << std::endl;
	std::cout << "b pointer address to pointer address value: " << **b << std::endl;
}