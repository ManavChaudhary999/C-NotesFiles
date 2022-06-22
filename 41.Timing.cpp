#include<iostream>
#include<chrono>
#include<thread>

// Useful case
struct Timer {
	std::chrono::time_point<std::chrono::steady_clock> start, end;
	std::chrono::duration<float> duration;

	Timer() 
	{
		start = std::chrono::high_resolution_clock::now();
	}
	~Timer() 
	{
		end = std::chrono::high_resolution_clock::now();
		duration = end - start;

		float ms = duration.count() * 1000; // converting seconds to miliseconds.
		std::cout << "Timer Took " << ms << "ms" << std::endl;
	}
};

void Function() 
{
	Timer timer;

	for (int i = 0; i < 100; i++)
		//std::cout << "hello" << std::endl;
		std::cout << "hello\n"; // more efficient
}
// Here timer object gets destroyed calling destructor
// so o/p for std::endl - 122.114 ms approx
// so o/p for \n - 79.000 ms approx

int main()
{
	using namespace std::literals::chrono_literals;

	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::high_resolution_clock::now(); // return current latest time
	
	// can also use auto
	auto start = std::chrono::high_resolution_clock::now(); // return current latest time
	std::this_thread::sleep_for(1s);
	auto end = std::chrono::high_resolution_clock::now(); // // will return current latest time

	std::chrono::duration<float> duration = end - start; // gives the difference b/w start and end time
	duration.count();// will return duration in seconds.
	
	std::cout << duration.count() << "s" << std::endl; // o/p - 1 sec approx 

	Function();

	std::cin.get();
}