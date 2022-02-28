// Dynamic Array are the arrays whose size can be changed based on the requirement dynamically.
// These are called vector in c++.
// Vector is a template provided in standard library.
// When using Vector we can pass any data type (primitive or non) in C++.
// But in java we can't pass primitve type(int, float) so we have to pass class types of these like INTEGER

#include <iostream>
#include <vector>

struct Vertex {
	int x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) 
{
	stream << vertex.x << " : " << vertex.y << " : " << vertex.z;
	return stream;
}

// Also if u want dynamic array in function then always pass by refrence
void Function(const std::vector<Vertex>& vertices) {}

int main() 
{
	Vertex vertices = new Vertex[5]; // here it is a static array as we cant increase the size of vertices;

	std::vector<Vertex> vertices; // dynamic array

	vertices.push_back({ 1, 2, 3 });
	vertices.push_back({ 4, 5, 6 });

	for (int i = 0; i < vertices.size(); i++)
		std::cout << vertices[i] << std::endl; // using ostream operator overload

	for (Vertex& vertex : vertices) // using refrence to avoid copy
		std::cout<<vertex<<std::endl;

	// Vector has various methods also

	vertices.clear(); // delete all the values
	vertices.erase(vertices.begin() + 1); // delete the value at specific index

	std::cin.get();
}