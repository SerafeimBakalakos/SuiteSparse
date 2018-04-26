#include "stdafx.h"
#include <sstream>
#include <fstream>
#include "linear_system.h"

__declspec(dllexport) double* read_double_array(std::string path, int* out_length)
{
	// Open the file
	std::ifstream file{ path };
	if (!file.is_open())
	{
		std::string message = "Could not open file ";
		message.append(path);
		throw std::ios_base::failure(message);
	}

	// Read the array length
	std::stringstream sstream;
	std::string word;
	int length;
	file >> word;
	sstream << word;
	sstream >> length;
	sstream.clear();

	// Allocate the array
	double* arry = new double[length];

	// Read the entries
	for (int i = 0; i < length; ++i)
	{
		double entry;
		file >> word;
		sstream << word;
		sstream >> entry;
		sstream.clear();
		arry[i] = entry;
	}

	// Clean up and return
	file.close();
	*out_length = length;
	return arry;
}

__declspec(dllexport) int* read_int_array(std::string path, int* out_length)
{
	// Open the file
	std::ifstream file{ path };
	if (!file.is_open())
	{
		std::string message = "Could not open file ";
		message.append(path);
		throw std::ios_base::failure(message);
	}

	// Read the array length
	std::stringstream sstream;
	std::string word;
	int length;
	file >> word;
	sstream << word;
	sstream >> length;
	sstream.clear(); 

	// Allocate the array
	int* arry = new int[length];

	// Read the entries
	for (int i = 0; i < length; ++i)
	{
		int entry;
		file >> word;
		sstream << word;
		sstream >> entry;
		sstream.clear();
		arry[i] = entry;
	}

	// Clean up and return
	file.close();
	*out_length = length;
	return arry;
}