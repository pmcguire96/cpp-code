// McGuire Tuple Code Challenge XRTrading.cpp : This file contains the 'main' function. Program execution begins and ends there.

/*
	Author:			Patrick Michael McGuire III
	Creation Date:	8 March 2021
	Version:		C++14
	Description:	Given a tuple of arbitrary length, prints three data points
	Returns:		Prints three data points:
						1. The arithmetic sum of all numeric entries
						2. The concatenation of all objects that can be cast to std::string
						3. The number of entries that were ignored by both (1) and (2)
*/

#include <iostream>
#include <string>
#include <tuple>
#include <typeinfo>

int main()
{
	// set tracking variables
	float tupleSum = 0.0f;
	std::string castObj;
	int ignored = 0;

	// create tuple
	using Tuple = std::tuple<int32_t, bool, std::string, float, const char*>;
	Tuple t{ 10, true, "Modern", 2.3f, "C++" };
	int32_t v = std::get< 0>(t);

	std::cout << "v: " << v << "\n";
	std::cout << "v is numeric: " << std::isdigit(v) << "\n";
	//int numObjects = std::tuple_size<t>;
	//int a[std::tuple_size<t>::value];
	std::cout << "Tuple elements: " << std::tuple_size<decltype(t)>::value << "\n";
	int numObjects = std::tuple_size<decltype(t)>::value;

	auto vType = typeid(v).name();
	std::cout << "V Type: " << vType << "\n";
	// std::cout << "V type is numeric: " << std::isalpha(vType) << "\n";


	// loop through tuple elements
	for (int i = 0; i < numObjects; i++) {

		// auto curIndex = std::get< 0>( t);
		auto curIndex = std::tuple_element();
		// <decltype(t)>::value;

		std::cout << " ======== Index: " << i << " ========\n";
		std::cout << "typeid: " << typeid(curIndex).name() << "\n";
		std::cout << "Sum: " << tupleSum << "\n";
		std::cout << "String: " << castObj << "\n";
		std::cout << "Ignored: " << ignored << "\n";
		std::cout << "----------------------------------------\n";

		if ((typeid(curIndex) == typeid(int32_t)) || std::isdigit(curIndex)) { // numbers - add to sum
			tupleSum += curIndex;
		}
		else if ((typeid(curIndex) == typeid(std::string))) { // string - append
			castObj += curIndex;
		}
		else { ignored++; } // other - track incrementally
	}


	std::cout << tupleSum << ", " << castObj << ", " << ignored << "\n";
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
