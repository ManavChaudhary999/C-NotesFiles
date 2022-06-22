// Classes are used to group Data and Functionailty.
// Classes are used to organize our code and make it easier to read and modify, it doesn't add new functionality or
// there is nothing new which u can't done without classes. 
// Classes are non-primitive datatype so they must be of unique name and also they contain address.
// Objects are the variables made out of classes or can say Objects are the class Instance.

// Classes have a size of atleast 1 byte if there is no data type in it because they need atleast 1 byte to be addressed.
// If Classes have multiple data types then they are allocated serially or in stack which is good for performance.
// So we can also access or type cast them into arrays.

#include<iostream>
#define log(x) std::cout<<x<<std::endl;

// So here if we check the address of Player class then x (4 bytes), y(4 bytes), speed(4 bytes) will be allocated stack wise(serially)
class Player{
	int x, y;
	int speed;

	public:
		Player()// Default Constructor, we dont have to write it if x and y are initialized with some default value like int x = 0.
		{
			x = 0;
			y = 0;
		}
		Player(int newX, int newY) // Parameterized Constructor 
		{
			x = newX;
			y = newY;
		}
		int GetPositionX()
		{
			return x;
		}
		int GetPositionY()
		{
			return y;
		}
		void SetSpeed(int speed){
			this.speed = speed;
		}
};

// & is used for passing by refrence so that we can modify actual player object not creating new instance.
void SetMoreSpeed(Player& player, int speed)
{
	player.SetSpeed(speed);
}

int main() 
{
	Player player1; // Object
	player1.SetSpeed(10);
	SetMoreSpeed(player, 10);

	Player player2(5, 10); // Object with some default value

	std::cin.get();
}