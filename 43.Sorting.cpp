// Sorting is used to sort data.
// There are many algo for sorting like bubble, selection, merge, ...and many more.
// There also sorting method in c++ library which are best for vector arrays.

#include<iostream>
#include<vector>
#include<algorithm>

int main() 
{
	std::vector<int> values = { 2,3,7,5,4,1 };

	std::sort(values.begin(), values.end()); // default ascending order

	std::sort(values.begin(), values.end(), std::greater<int>); // descending order

	std::sort(values.begin(), values.end(), [](int a, int b) // lambda function
	{
		// always return bool value
		// if true then a gets priority or sorted first
		// if false then b gets priority or sorted first
		
		if (a == 1) return false; // if selected argument is 1 then return false meaning give a least priority
		if (b == 1) return true; // if comparing argument is 1 then return true meaning give a high priority
		return a < b; // if a is smaller than b then return true maining a will be sorted first, similar to ascending order
		// o/p - 2,3,4,5,7,1
	});

	std::cin.get();
}