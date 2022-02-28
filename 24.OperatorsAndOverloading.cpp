// Operators are used to perform some function.
// There are many operators like +,-,*,/,%,^,&,=,{},new,this,<<,>>,',' and many more.
// Operator overloading means giving new meaning or changing the behaviour of opeartor.
// Operator are just a function with some behaviour.
// This is fully allowed in c++, partially allowed in c# and not allowed in java.

// Operator Overloading can be done in two places - 1. class method , 2. non-class method(function)

// Operator overloading method of class member must have either 0 or 1 argument.
// Operator overloading function of non-class must have either class as an argument or enum as a return type.

#include<iostream>

struct Vector2 {
	float x, y;

	Vector2(float X, float Y)
		: x(X), y(Y) {}

	Vector2 Add(const Vector2& other) const 
	{
		return Vector2(x + other.x, y + other.y);
	}

	Vector2 Multiply(const Vector2& other) const 
	{
		return Vector2(x * other.x, y * other.y);
	}

	Vector2 operator+(const Vector2& other) const 
	{
		return Add(other);
	}

	Vector2 operator*(const Vector2& other) const 
	{
		return Multiply(other);
	}

	bool operator==(const Vector2& other) const 
	{
		return x == other.x && y == other.y;
	}

	bool operator!=(const Vector2& other) const 
	{
		return !operator==(other); // U can also do this
		return !(*this == other); // or also do this
		return x != other.x || y != other.y; // but this is the simple one
	}
};

std::ostream& operator<<(std::ostream& stream, const Vector2& other)
{
	stream << other.x << ":" << other.y;
	return stream;
}

int main() 
{
	// Without operator overloading
	Vector2 position(2.0f, 8.0f);
	Vector2 speed(9.0f, 10.0f);
	Vector2 powerup(2.0f, 2.0f);

	// Lets say we want to powerup our speed and then adding speed to position, So
	Vector2 result = position.Add(speed.Multiply(powerup)); // Now this is what we have done in java
	
	std::cout << result << std::endl; //This will not work coz cout doesn't know how to print Vector2 struct
	
	// With operator overloading
	Vector2 result2 = position + speed * powerup;
	std::cout << result2 << std::endl; // This will work cause we make << overload

	bool isequal = result1 == result2;
	bool isNotequal = result1 != result2;
	std::cout << isequal << std::endl;
}