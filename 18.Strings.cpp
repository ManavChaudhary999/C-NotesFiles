//String is just an group of character.
// String are non mutable means cant modified cause we dont want a string of size 5 initialized and then modified into size 7.
// String are just const char*
//String can be used in c++ by two ways: 1. wihout string library(only using char) like C style or 2. using string library

#include<iostream>
#include<string> // using library but not need to require in Current version of c++.

void MainString() 
{
	// 1. C- literal String

	const char* string = "Non Mutable"; // Using const so it follows the string property(i.e. Non Mutable)
	// "Non Mutable" or "Manav" all are const char* meaning char[] (character array)

	char* str1 =  (char*)"Manav"; // so we need casting into char* from const char*
	std::cout << str1 << std::endl; // this will print string not pointer address of str1 coz every char pointer like this have 0(means null) as an address in last place or last index which makes complier to read string untill 0 occured

	const char* str1 = "Manav\0Manav";
	std::cout << str1 << std::endl; // o/p: Manav read untill null value

	char str2[5] = { 'M', 'A', 'N', 'A', 'V' }; // Character array is also called string
	str2[2] = 'L';
	std::cout << str2 << std::endl; // this will print address of array coz it does not have 0(null) as an last address

	char str3[6] = { 'M', 'A', 'N', 'A', 'V', '\0'} // '\0'(char) means 0(int) whose ascii value is null so compiler will read unitll null in last index 
	std::cout << str2 << std::endl; // this will print value of string, coz it have 0 as an last address


	// Methods of c-literal-string
	strlen(str1); // size of char pointer or string
	strcpy(str1); // To copy

	// 2. Standard Library string (String Class)
	
	// A String Class is written in header files or libraries
	// It Takes contructor as const char*
	std::string name = "Manav";
	std::cout << name << std::endl; // Previously u cannot use string in cout as other classes untill include<string> library but now this is depricated so u can use without include.

	//std::string name = "Manav" + " hello"; // this will not work and show error

	// To add string
	//name += "hello"; one way
	std::string name = std::string("Manav") + "hello";
	// There is no contains method so use this...
	bool contains = name.find("Ma") != std::string::npos; // npos is just a empty string
	}