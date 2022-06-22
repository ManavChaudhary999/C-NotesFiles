// Compiler Converts Source Files(.cpp files) into Binaries.
// These Binaries can be executable(own files) or external libraries.
// Compiler first preprocess the file meaining preprocessor(like #include, #define) executed first.
// Then from top to bottom of a particular file.
// This compilation process does many diffrent things like parsing converting text language to machine language.
// Compiler converts this english text language into abstract syntax tree.
// This Abstract Syntax tree contains all of our constant data and instructions.
// When we Build our Project by right click on project folder -> build, then Project_Name.exe file(executable file) created.

// Each cpp file gets compiled but header files not compiled, only included.
// In a Project only one main() can be included which we call a Main.cpp file(default)
// Others files are linked together if Main.cpp use there functionailty.
// Every cpp File gets compiled and created in obj file. (like Main.obj, demo.obj)
// These obj file need to be joined together to make our project files work together.
// This joining is done by Linker.
// Files can be compiled by command ctrl+f7.

#include<iostream> // # -> preprocessor , include -> identifier

void Log(const char* message); // declaration - this is a other file function we want to use in this file

int main() 
{
	// If this function exist or not, compiler still trust us and gonna execute the project files in .obj.
	// But when we build (.exe) then it will show error cause of Linker.
	// Linker helps to find the defintion of a method declaraed in this file like Log()
	Log("Hello World"); 

	std::cin.get(); // This stops a program to execute further untill we hit enter.
}