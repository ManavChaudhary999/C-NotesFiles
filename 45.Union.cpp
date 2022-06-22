// Union are the non-primitive type like class and struct.
// Union are the multiple ways to show same data.
// The differnce is if struct or class have 4 int data members then total size will be 16 bytes
// But with union it only holds one member size meaning 4 bytes for 4 member sharing same memory address.
// They can basically used as giving two differnt ways to address same memory.
// And also Unio can be anonymous(dont have to provide name).

#include <iostream>

struct Vector2 
{
	int a, b;
};

//struct Vector4
//{
//	int x, y, z, w;
//};

struct NewVector4 
{
	union
	{
		struct
		{
			int x, y, z, w;
		};
		struct 
		{
			// here first Vector2(a, b) share x and y memory address
			// and second Vector2(a, b) share z and w memory address
			Vector2 first, second;
		};
	};
};

// Now this function only prints for vector 2, what if we want to print for vector4 without creating new function,
// Here comes Union
void PrintVector2(const Vector2& vector) 
{
	std::cout << "x: " << vector.a << ", y: " << vector.b << std::endl;
}

int main() 
{
	//*********************	Example 1 *****************************************
	union A
	{
		// Sharing same memory address
		// if we change one then other will also change
		float a;
		int b;
	};

	//*********************	Example 2 *****************************************
	// They can also be anonymous
	union
	{
		// Now both struct Sharing same memory address
		// if we change a of first struct then c will chnage of other other struct, similar for rest members.
		struct 
		{
			int a, b;
		};
		struct 
		{
			int c, d;
		};
	};

	//*********************	Example 3 *****************************************
	Vector4 color = { 1, 2, 3, 4 };
	PrintVector2(color.first); // O/P - x:1 , y:2
	PrintVector2(color.second); // O/P - x:3 , y:4
	
	color.z = 50;
	color.w = 7;

	PrintVector2(color.first); // O/P - x:1 , y:2
	PrintVector2(color.second); // O/P - x:50 , y:7

	std::cin.get();
}