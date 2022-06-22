// Optimizing of a code is most important thing.
// To Optimize a code 3 things are important - 1. Know your Enviornment 2. What need to do 3. Whats gonna reflect or output
// In case of Vector class-
// Things cause in slowing the program are -
// 1. When we push_back our object or new value, Vector just copy that object into new address and delete old address.
// 2. If there is no enough size and we push-back then it reallocate the size(or can say create new array of increasing size) by 
// allocating all the previous values to new address.
// Fix-
// 1. We can avoid copying by directly allocate to that specific address where vector puts in.
// 2. Can Initially set the value of array.

#include <iostream>
#include <vector>

struct Vertex {
	int x, y, z;

	Vertex(const int& newX, const int& newY, const int& newZ)
		: x(newX), y(newY), z(newZ)
	{}

	// Copy Constructor
	Vertex(const Vertex& vertex)
		: x(vertex.x), y(vertex.y), z(vertex.z)
	{
		std::cout << "Copied Constructor" << std::endl;
	}
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) 
{
	stream << vertex.x << " : " << vertex.y << " : " << vertex.z;
	return stream;
}

int main() 
{
	std::vector<Vertex> vertices;

	Vertex vertex = { 1,2,3 };
	vertices.push_back(vertex); // so here copy constructor called beacuse vector is copying the object
	vertices.push_back(Vertex(1, 2, 3)); // Copied Constructor will be called 2 times- 1 for copying and other for reallocating vector
	//size by setting above vertex into new address.
	vertices.push_back(Vertex(1, 2, 3)); // Copied Constructor will be called 3 times- 1 for copying and other for reallocating vector
	//size by setting above two vertex into new address.
	//So total 6, 3 for copying and 3 for reallocating size.
	// 
	// To fix above copying problem we can use
	vertices.reserve(2); // here we are manually reserving or Initializing size of 2, so untill this filled there will be no reallocating to new address.
	vertices.emplace_back(1, 2, 3); // it need constructor value directly so copying constructor will not be called. 
	vertices.emplace_back(4, 5, 6);
	vertices.emplace_back(4, 5, 6);// here copied constructor will be called for above two to reallocate size because initiali size is filled.

	std::cin.get();
}