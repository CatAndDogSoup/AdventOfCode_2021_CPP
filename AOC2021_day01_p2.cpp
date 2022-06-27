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

