// #pragma once is preprocessor used to make sure this header file can not be used or copied twice in same file.
// lets say we have other header file named - abc.h
/*{
	// This header file include 3.Headerfiles.h
	include "3.Headerfiles.h"
}*/

// And lets say some other cpp file named - manav.cpp
/*{
	// This file inlcude both Headerfiles.h and abc.h
	#include "3.HeaderFiles.h"
	#include "abc.h"
	// But abc.h already include headerfiles.h so this file have
	// 2 copy of headerfile.h, To remove this double copying we use #pragma once
}*/

#pragma once

void Log(const char* message);
void InitLog();