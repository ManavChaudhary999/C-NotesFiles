// When we use include header files like vector(dynamic arrays), memory(smart pointers), glfw(dll) and others then
// Compiler parse and copy that file(code) into our main file where we included , so if we use a library in many other files then
// it will copy that library code and if we change our main file or file which included libraries then it will again copy that
// which will increase compile time.

// So we use precompiler headers, it just parse header files into byte code and only once then any file can use.
// Which reduce compile time.

// NOTE - Only use precompiled header for those libraries which are included in many files(like STL libraries - String, Vector, etc) 
// not for files which are included in only one file because that dosn't make any sense.

// Now here we are including "48.pch.h" then it will take time to compile, So
// We have to precompile it.
// Now There are two ways to do that - 1. In cmd using g++  2. Visula Studio way

// We will use Visual Studio way -
// 1. First create new cpp(lets say pch.cpp) file which include "48.pch.h" header file.
// 2. Then right click on pch.cpp created file then click properties.
// 3. Then in c/c++ section -> Precompiled Headers -> Precompile Header = Create(/Yc)
// 4. Now right click on entire Project -> Properties -> C/C++ Section -> Precompiled Headers -> (i). Precompile Header = Use(/Yc),
																					// (ii). Precompiled Header File = pch.h
// DONE.

#include "48.pch.h";

int main()
{
	std::cout << "hello World";
}