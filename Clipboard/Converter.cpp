#include "pch.h"
#include "Converter.h"

std::vector<std::array<char, 480>> Converter::string_to_char_arrays(std::string &string)
{
	std::array<char, 480> char_array = {};

	if (string.length() <= 480)
	{
		for (size_t i = 0; i < string.length(); ++i)
		{
			char_array[i] = string[i];
		}

		std::vector<std::array<char, 480>> vector_of_arrays(1, char_array);

		return vector_of_arrays;
	}


	int number_of_arrays = string.length() / 480 + (string.length() % 480 ? 1 : 0);

	std::vector<std::array<char, 480>> vector_of_arrays(number_of_arrays);

	for (size_t i = 0; i < number_of_arrays; ++i)
	{
		for (size_t j = 0; j < 480; ++j)
		{
			if (i * 480 + j > string.length())
			{
				break;
			}
			vector_of_arrays[i][j] = string[i * 480 + j];
		}
	}

	return vector_of_arrays;
}

std::string Converter::char_arrays_to_string(std::vector<std::array<char, 480>> vector_of_arrays)
{

	std::string string(vector_of_arrays.size() * 480, '\n');
	
	

	for (size_t i = 0; i < vector_of_arrays.size(); i++)
	{
		for (size_t j = 0; j < 480; j++)
		{
			string[j + i * 480] = vector_of_arrays[i][j];
		}
	}
	return string;
}
