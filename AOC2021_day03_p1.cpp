// AOV2021_day02_p1.cpp
// AOC 2021 Day 02 part 2 cpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

// GOALS
// Use multiple functions
// Read and re-distribute data

// TODO
// - [/] Read data from file
// - [/] Parse data to a vec 
// - [/] Rotate array 90 degrees
// - [/] Convert each binary number to decimal for Gamma Rate
// - [ ] Flip binary number and convert to decimal for Epsilon Rate
// - [ ] Multiply the Gamma Rate and Epsilon Rate together
// - [ ] Return result

std::vector<std::string> GetInputValues()
{
	std::ifstream input_file("day3_input.txt");  // Read input file to input_file

	if (input_file.good()) {} else { std::cout << "Input File not correct!" << std::endl;  } // Check that input file exists

	std::vector<std::string> values = std::vector<std::string>();

	for (std::string line; std::getline(input_file, line);)
	{
		values.push_back(line);
	}
	return values;
}

std::vector<std::string> RotateVecString(const std::vector<std::string>& input_data)
{
	// Read through each item in the array as many times as each item's length
	int item_len = input_data.front().length() ;  // Get the length of the first item in the array
	int vec_len = input_data.size();
	// std::cout << "item length: " << item_len << std::endl;
	// std::cout << "vec length: " << vec_len << std::endl;

	std::vector<std::string> formatted_data(item_len);

	for (int i = 0; i < vec_len; i++)
	{
		for (int j = 0; j < item_len; j++)
		{
			std::string new_data;
			new_data = formatted_data.at(j) + input_data.at(i).at(j);
			formatted_data.at(j) = new_data;
		}
	}

	return formatted_data;
}

std::string CalculateBinaryInt(const std::vector<std::string>& formatted_input)
{
	std::string output_binary;
	for (std::string str: formatted_input)
	{
		int num_ones = 0;
		int item_len = str.length();
		for (char num: str)
		{
			if (num == '1') { num_ones++; };
		};
		if (num_ones > (item_len / 2)) { output_binary.append("1"); } else {output_binary.append("0");}
	};
	
	return output_binary;
}

std::string InvertBinaryInt(const std::string& binary_int)
{
	std::string output_inverted_binary;
	std::string input_binary = binary_int;
	for (char num: input_binary) 
	{ 
		if (num == '0') {output_inverted_binary.append("1"); } else {output_inverted_binary.append("0");}
	}
	return output_inverted_binary;
}

int main()
{
	std::vector<std::string> inputs = GetInputValues();
	std::vector<std::string> formatted_inputs = RotateVecString(inputs);
	std::string gamma_binary_int = CalculateBinaryInt(formatted_inputs);
	std::string epsilon_binary_int = InvertBinaryInt(gamma_binary_int);

	std::cout << "Gamma Rate as base 10: " << std::stoi(gamma_binary_int, 0, 2) << std::endl;
	std::cout << "Gamma Rate as binary: " << gamma_binary_int << std::endl;

	std::cout << "Epsilon Rate as base 10: " << std::stoi(epsilon_binary_int, 0, 2) << std::endl;
	std::cout << "Epsilon Rate as binary: " << epsilon_binary_int << std::endl;

	std::cout << "Final result: " << std::stoi(epsilon_binary_int, 0, 2) * std::stoi(gamma_binary_int, 0, 2) << std::endl;

	std::cout << "END" << std::endl;

	return 0;
}
