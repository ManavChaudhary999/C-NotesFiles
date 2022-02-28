#include<iostream>
#include<string>

#define LOG(x) std::cout<< x << std::endl

void MainStringTut()
{
    // Initializing
    std::string str1 = "ManavChaudhary";
    std::string str2(5, 'm'); // 5 define size and m will be added 5 times

    // Input

    std::string str3; // User input string can be in two ways
    //std::cin >> str3; // Input takes place untill user hits space
    // getline(cin, str3); // Input takes place untill user hits enter

    // Access
    LOG(str1[2]);
    LOG(str1.size());
    LOG(str2.length());

    // removing
    str3.clear();
    str1.erase(2, 4); // remove char from 2 index to 2 + 4 index

    // comparing
    LOG(str1.compare(str2)); // Subtract str1 ascii value - str2 ascii value (if both same return 0)
    LOG(str1.find("nav")); // return first matching index

    // Appending
    LOG(str1 + str2);
    str1.append(str2); // added in str1(changes str1)
    LOG(str1);
}