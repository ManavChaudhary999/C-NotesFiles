#pragma once

// Lets Say we have this header file which include these multiple header file which have almost 30000 lines of code combined
// Now If we include this header file in our 48.PrecompiledHeader.cpp or any other file then it will take time to compile, So
// We have to precompile it.
// Now There are two ways to do that - 1. In cmd using g++  2. Visula Studio way

#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <thread>
#include <utility>

// Data Structures
#include <string>
#include <stack>
#include <deque>
#include <array>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

// Windows API
#include <Windows.h>
