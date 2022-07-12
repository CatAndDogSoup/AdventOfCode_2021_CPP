// AOV2021_day02_p1.cpp
// AOC 2021 Day 02 part 2 cpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::ifstream input_file("day2_input.txt");  // Read input file to input_file

	if (input_file.good()) {} else { std::cout << "Input File not correct!" << std::endl; return 1; } // Check that input file exists

	auto inputs = std::vector<std::pair<std::string, unsigned int>>();

	for (std::string line; std::getline(input_file, line);)
	{
		unsigned first = line.find(' ') + 1; 
		unsigned last = line.size();
		int num = std::stoi(line.substr(first, last - first));

		std::string movement = line.substr(0, line.find(' '));
		
		inputs.push_back(std::make_pair(movement, num));
	}

	int position = 0;
	int depth = 0;
	int aim = 0;

	for (auto data: inputs)
	{
		if (std::get<0>(data) == "up") { aim = aim - std::get<1>(data); }
		else if(std::get<0>(data) == "down") { aim = aim + std::get<1>(data); }
		else if(std::get<0>(data) == "forward") { 
			position = position + std::get<1>(data);
			depth = depth + (aim * std::get<1>(data)) ;
		}	
	}
	
	int final = position * depth;

	std::cout << "Depth: " << depth << 
		", Position: " << position << 
		", Final: " << final <<
		std::endl;
}