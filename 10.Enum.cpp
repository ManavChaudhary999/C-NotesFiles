// Enum is a short for Enumeration.
// It is a set of name corresponds to int value.
// It is used to give name to integer values.
// Note: U can use unsigned char also as it is of 8-bit size and can store integer values.

enum Example 
{
	// A=0, B=1, C=2
	A,B,C
};
enum Example2 
{
	// A=4, B=5, C=6
	A=4,B,C
};
enum Example3 
{
	A=4,B=6,C=9
};

int main() 
{
	Example var = 5; // show error coz value must be assigned in from enum 
	Example var2 = B;
	std::cin.get();
}