#include<iostream>

int var = 10; // This will work as it is creating new var not accessing static var of other file.

void Function() {} // This a function of this file not static file function, so work

// This will show error as this gonna look for var in other files with same name to get access but the var is static
// which means static can't be accessed out of the scope of that file.
extern int var; //extern is used to look for same data var in other files.

extern void Function() {}; // Not gonna work


int main() 
{
	std::cout<< var <<std::endl;
}