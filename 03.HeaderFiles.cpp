//1. Header Files are used to declare some functions or properties which are written in other files

//6. Notice here are including header files by <> and ""
//6. So <> means include header file present in include directory and "" means path where header file is exist
//6. if header file is present in other directory then we have to use "../abc.h";
//7. Notice here iostream header file doen't have .h extension becoz it is a c++ header file
//8. Those header file (other then our own) which have .h extension are header files written in c 
#include<iostream> //2. This is a header file having some input / output function declaration
#include "3.HeaderFiles.h"; //2. Header file having declaration for Log , InitLog and other function

//3. If we want to use some other file function then we have to declare that function so that compiler will know
//void Log(const char* message); // Function Declaration written in headerfiles.cpp

//4. But What if we have multiple Functions to use then we have to declare all
//4. So to remove that complexity we use header files
//4. header files can be declared by filename.h

int main() 
{
	//5. Both Functions are defined in other c++ file
	//5. But we are using with the help of header file which have declaration of these function
	//5. So that this file and any other file dont have to declare these function
	Log("Chl be");
	InitLog();
}