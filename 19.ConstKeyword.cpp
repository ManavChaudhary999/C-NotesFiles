#include<iostream>

// const - is a keyword use to make a constant or can say make var read only
// It is basically a promise we make to not change the content of var but we can break the promise and can change the value

// mutable - keyword use to make var to be able to modified in const method

// Note: const method can be used only in memeber function not a non-class function

class Entity {
	private:
		int M_X, M_Y;
		mutable int random = 5;
	public:
		int Get_X() const // Make Method const or read only means this method can't change value of this class variable 
		{
			//M_X = 5; // this will not work
			random = 9; // mutable var can be modified
			return M_X;
		}
		int Get_Y() 
		{
			return M_Y;
		}
};

void PrintEntity(const Entity& e) // here we are setting e is constant (like const int e) 
{
	//e = new Entity(); we cant change the value of e this will not work
	//std::cout << e.Get_Y() << endl; Error: coz Get_Y is not const hence we are allowing this function to change the content of entity class members
	std::cout << e.Get_X() << endl; // This will work
}

int MainConst() 
{
	const int a = 5;
	int* p = new int;

	//a = 6; we can't change that
	p = (int*)&a; // int* is used to bypass the const rule
	*p = 10; // changing the const var value

	std::cout << a << std::endl; // hence o/p will be 10

	const int b = 7;
	const int* pointer = new int; // this means we are making var constant not its address
	//int const* pointer = new int; both are same
	
	//*pointer = 3; Can't modify const var value
	pointer = &b; // but we can change refrencing address and hence value of pointer will automatically change

	int* const add = new int; // this means we are making pointer or address constant but not var
	
	*add = 3; // can chnage the value
	//add = &b; can't change the address as it is constant

	const int* const another = new int; // By this we can't change both address and value


	return 0;
}