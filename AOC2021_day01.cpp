// AOC2021_day01.cpp
// AOC 2021 Day 01 cpp
#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <fstream>

// I'm sure a lot of this is pretty jank code, 
// but it's my first from-scratch c++ script, 
// so I'll give myself a bit of leeway

std::ifstream readFileAndSetToArray(const std::string& filename);

int main()
{

	auto input_data = readFileAndSetToArray("day1_input.txt");

	int increase_count = 0;
	int previous_item = 999999999;

	std::string str;

	while (std::getline(input_data, str))
	{
		int item = std::stoi(str);
		std::cout << "item: " << item << std::endl;
		if (item > previous_item) { 
			increase_count++;
			std::cout << "higher :)" << std::endl;
		}	
		previous_item = item;
	};

	std::cout << "increases: " << increase_count << std::endl;
}

std::ifstream readFileAndSetToArray(const std::string& filename)
{
        std::ifstream fh(filename);
        return fh;
}

