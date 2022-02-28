// Classes are used to group Data and Fucntionailty.
// Classes are used to organize our code and make it easier to read and modify, it doesn't add new functionality or
// there is nothing new which u can't done without classes. 
// Classes are non-primitive datatype so they must be of unique name.
// Objects are the variables made out of classes.

#include<iostream>
#define log(x) std::cout<<x<<std::endl;

class Player{
	int x, y;
	int speed;

	public:
		Player() // Constructor, also a default we dont have to write it.
		{
			x = 0;
			y = 0;
		}
		Player(int newX, int newY) // Constructor 
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

// & is used for passing by refrence so that we can modify actual player object not creating new one.
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