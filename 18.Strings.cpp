#include<iostream>
#include<string> // using library
//String is just an array of char
//String can be used in c++ by two ways: 1. wihout string library(only using char) like C style or 2. using string library

void MainString() 
{
	// 1. C- literal String

	char* str1 = "Manav"; // other way by using pointer we discused in array lecture
	std::cout << str1 << std::endl; // this will print string not o/p coz every char pointer like this have 0(means null) as an address in last place or index
	// which makes complier to read string untill 0 occured

	char str2[5] = { 'M', 'A', 'N', 'A', 'V' }; // Character array is also called string
	str2[2] = 'L';
	std::cout << str2 << std::endl; // this will print address of array, coz it does not have 0 as an last address

	char str3[6] = { 'M', 'A', 'N', 'A', 'V', '\0'} // '\0'(char) means 0(int) whose ascii value is null so compiler will read unitll null in last index 
	std::cout << str2 << std::endl; // this will print value of string, coz it have 0 as an last address

	const char* str3 = "Non Mutable"; // Non mutable string means can't be modified

	// Methods of c-literal-string
	strlen(str1); // size of char pointer or string
	strcpy(str1); // To copy

	// 2. Standard Library string
	
	std::string name = "Manav";
	std::cout << name << std::endl;

	//std::string name = "Manav" + " hello"; // this will not work and show error

	// To add string
	//name += "hello"; one way
	std::string name = std::string("Manav") + "hello";
	// There is no contains method so use this...
	bool contains = name.find("no") != std::string::npos; // npos is just a empty string
	}