// Struct is a is a collection or group of data and functionality.
// It is a non-primitive data type and name must be unique.
// Struct is also same as classes the only differnce is visibilty of data.
// Class default visibilty of a data type is private where as in struct it is public.

// When to use which one?
// Ans - Struct can be used where there isn't much functionality like vector 2 struct.
// Use struct like just the sructure of data.
// Ans - Classes can be used where there is more functionality or data demand like Player Class.
// Tip - Never use inheritance with struct

#include<iostream>

class Entity 
{
	int a;
};

struct Beta 
{
	int a;
};

void StructMain() 
{
	Entity e;
	e.a = 5; // this will not

	Beta b;
	b.a = 5; // this will run
}