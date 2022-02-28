// Copying is just copy of a value of var to another var of same data type (either primitive or non primitive).
// whenever assigned operator(=) is used it always copy except refrences.

// Copy constructor :- used to copy of a class data members to another class
// It is of two types - 
// 1. Shallow Copy - in this a class copies the address of data members of another class hence both pointing same data members.
// 2. Deep Copy - in this a class only copies the value of data members of another class not address hence both have their own data members.

#include<iostream>

struct Vector2 {
	int x, y;
};

class String {
private:
	char* m_Buffer;
	unsigned int m_Size; // using unsigned coz size can't be -ve
public:
	String(const char* string) 
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1]; // +1 for null character
		/*for (int i = 0; i < m_Size; i++) 
		{
			m_Buffer[i] = string[i];
		}*/
		memcpy(m_Buffer, string, m_Size); // use to copy value
		m_Buffer[m_Size] = 0; // adding null char at the end of string
	}

	// Fixes of shallow copy problem
	// Deep Copy by compiler 
	/*String(const String& other)
		: m_Buffer(other.m_Buffer), m_Size(other.m_Size)
	{}*/

	// Not allowing copy
	// String(const String& other) = delete; 

	// Deep copy constructor of our own
	String(const String& other)
		: m_Size(other.m_Size)
	{
		std::cout << "Copied String" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		// m_Buffer[m_Size] = 0; // not doing this becoz other string has already a null value at the end.
	}

	char& operator[](const unsigned int index) 
	{
		return m_Buffer[index];
	}

	// destructor
	~String() 
	{
		delete[] m_Buffer; // deleting m_buffer coz taking heap memory (instantiated using new keyword)
	}

	// friend keyword is used to allow external method to give access private members of this class.
	friend std::ostream& operator<<(std::ostream& stream, const String& string) 
};

std::ostream& operator<<(std::ostream& stream, const String& string) 
{
	stream << string.m_Buffer; // accessing private member of String class because this method is friend
	return stream;
}

// calling without refrence so deep copying the class
void Print(String string) // here copied string will be print
{
	std::cout << string << std::endl;
}
// calling by refrence so not copying
void Print(const String& string)
{
	std::cout << string << std::endl;
}

int main() 
{
	int a = 5;
	int b = a; // Copying a value of a
	b = 8; // not gonna affect a.

	Vector2 a = { 2,3 };
	Vector2 b = a;// Copying a value of a
	b.x = 9; // not gonna affect a.

	Vector2* a = new Vector2();
	Vector2* b = a; // Copying a pointer(where address a pointing) of a

	// Shallow Copy (before deep copy constructor)
	{
		String first = "Manav";
		String second = first; // implicitly convert the object into char*
		second[2] = 't'; // gonna change for both

		std::cout << first << std::endl; // using our own operator overload
		std::cout << second << std::endl; // o/p - Matav for both 
	}
	// here program will crash coz as we are out of scope so the lifetime of String class is over then they automatically call their
	// destructor. What destructor is doing that it is deleting m_Buffer[].
	// But as we are shallow copying first class into second, second class gonna copy first class members inlcuing m_Buffer which is a 
	// pointer so both classes are pointing same memory address of m_Buffer.
	// if first class destructor called first resulting deleting m_Buffer[] and the second class destructor called then it will also try 
	// deleting m_Buffer which is already deleted hence error occured.

	// Deep Copy (to fix above problem we write copy constructor)
	{
		String first = "Manav";
		String second = first; // copied string will be print
		second[2] = 't'; // only change for second class

		std::cout << first << std::endl; // o/p - Manav
		std::cout << second << std::endl; // o/p - Matav 
	}
	// also fix the problem of destructor

	std::cin.get();
}