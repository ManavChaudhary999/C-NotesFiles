#include<stdio.h>

//int var = 10; This will work as it is creating new var not accessing staic var

// This will show error as this gonna look for var in other files with same name to get access but the var is static
// which means staic can't be accessed out of the scope of that file.
extern int var; //extern is used to look for same data var in other files

void Function() {} // This a function of this file not static file function, so work

int main() 
{
	std::cout<< var <<std::endl;
}