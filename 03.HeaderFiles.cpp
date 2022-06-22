//1. Header Files are used to declare some functions or properties which can be used by multiple files by including it.

//6. Notice here are including header files by <> and ""
//6. So <> means include header file present in include directory and "" means path where header file is exist
//6. if header file is present in other directory then we have to use "../abc.h";
//7. Notice here iostream header file doen't have .h extension becoz it is a c++ header file
//8. Those header file (other then our own) which have .h extension are header files written in c 
#include<iostream> //4. This is a header file having some input / output function declaration
#include "3.HeaderFiles.h"; //4. Header file having declaration for Log , InitLog and other function

//2. If we want to use some other file function then we have to declare that function so that Linker will know
//void Log(const char* message);

//3. But What if we have multiple Functions to use then we have to declare all
//3. So to remove that complexity we use header files
//3. header files can be declared by filename.h

int main() 
{
	//5. Both Functions are defined in other c++ file
	//5. But we are using with the help of header file which have declaration of these function
	//5. So that this file and any other file which include header file dont have to declare these function
	Log("Chl be");
	InitLog();
}