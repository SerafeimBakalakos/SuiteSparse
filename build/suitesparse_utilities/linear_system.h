#pragma once
#include <string>

extern "C"
{
	__declspec(dllexport) double* read_double_array(std::string path, int* out_length);
	__declspec(dllexport) int* read_int_array(std::string path, int* out_length);
}
