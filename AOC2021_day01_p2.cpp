// AOC2021_day01.cpp
// AOC 2021 Day 01 cpp
#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <fstream>
#include <vector>

int main()
{
	std::vector<std::string> numbers;
	std::ifstream input_file("day1_input.txt");

	std::string buffer;

	if (input_file.good()) // Ensure file exists 
	{
		while (input_file >> buffer)
		{
			numbers.emplace_back(buffer); // transfer to a string vector
		}
	}

	// read each item in numbers, convert to an int, and print to cout
	//for (std::string str_num : numbers)
	//{
	//	int number = std::stoi(str_num);
	//	std::cout << number << std::endl;
	//}

	// Print the result of numbers[0] + numbers[1] + numbers[2] as ints
	//std::cout << (
	//	std::stoi(numbers.at(0)) + 
	//	std::stoi(numbers.at(1)) +
	//	std::stoi(numbers.at(2))
	//		) << std::endl;
	
	
	int previous_item = 999999999;
	int increase_count = 0;
	for (int i = 1; i < numbers.size()-1; i++)
	{
		// Combine and add i-1, i, and i+1 as ints
		// I should have re-cast this array to ints before but here we are
		int num = 
		std::stoi(numbers.at(i-1)) +
                std::stoi(numbers.at(i)) +
		std::stoi(numbers.at(i+1));
		
		if (num > previous_item)
			increase_count++;
		previous_item = num;

	}
	std::cout << "AOC 2021 Day 1 Part 2 result: " << increase_count << std::endl;
}

