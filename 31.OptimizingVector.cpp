// Optimizing of a code is most important thing.
// To Optimize a code 3 things are important - 1. Know your Enviornment 2. What need to do 3. Whats gonna reflect or output
// In case of Vector class-
// Things cause in slowing the program are -
// 1. When we push_back our object or new value, Vector just copy that object into new address and delete old address.
// 2. if there is no enough size and we push-back then it reallocate the size.
// Fix-
// 1. We can avoid copying by directly allocate to that specific address where vector puts in.

#include <iostream>
#include <vector>

struct Vertex {
	int x, y, z;

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

	// This basically similar to Vertex vertex = {1,2,3}; so here copy constructor called beacuse vector is copying the object
	vertices.push_back(Vertex(1, 2, 3)); // Copied Constructor will be called
	vertices.push_back(Vertex(1, 2, 3)); // Copied Constructor will be called 2 times- 1 for copying other for reallocating vector size
	// So total 3 - 2 for copying, 1 for reallocating size

	// To fix above copying problem we can use
	vertices.reserve(3); // here we are manually reserving or creating size of 3
	vertices.emplace_back(1, 2, 3); // it need constructor value directly and avoid copying directly initialize object in vector address
	vertices.emplace_back(4, 5, 6);

	std::cin.get();
}