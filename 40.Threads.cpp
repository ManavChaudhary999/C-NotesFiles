// Threading is used to do things parallel.
// Used for optimization.

#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() 
{
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	while (!s_Finished) 
	{
		std::cout << "Working....\n";
		std::this_thread::sleep_for(1);
	}
}

int main() 
{
	std::thread worker(DoWork); // this takes function pointer

	std::cin.get();
	s_Finished = true;

	// It will wait untill worker thread will complete meaning untill DoWork Finish
	worker.join(); // It is similar to Wait or WaitForSeconds in C#.
	std::cout << "Finished" << std::endl;
	std::cout << "Started thread id = " << std::this_thread::get_id() << std::endl;

	std::cin.get();
}