// Static has two meaning in comparision to outside or inside of the classes or structs.
// 1. Static inside the class or struct means it is gonna share same memory address to all the instances of that class or struct.
// Meaing there is going to be one instance of that static symbol out of all multiple instances of class or struct.
// 2. Static outside the class or struct means the linkage of that static data is going to be internal.
// Internal meaing the it is only be visible to that translation unit or method. 

// 2. Using outside of classes

static int var = 5; // This means this var can't be accessed by other files
static void Function() {}

// 1. Using inside the class
class Player {
	static int otherSpeed = 9;
	static int speed = 5;

	int x = 0;

	static void Print() // Static methods only use static data types
	{
		//std::cout<< x <<std::endl; // x can't be used coz it is non static
		std::cout<< speed << x <<std::endl;
	}

public:
	static int random;
};

int Player::speed; // to get access to speed variable by instances

int main() 
{
	Player player1; // class instance
	player1.speed = 10; // setting static var
	
	Player player2; // Another class instance
	std::cout << player2.speed << std::endl; // player2 speed is also gonna be 10 becoz they share same static variable
	
	// here we are not creating instances, it also the same as above ex.
	Player::otherSpeed = 100; //also a way to get access of private static without creating instances.
}