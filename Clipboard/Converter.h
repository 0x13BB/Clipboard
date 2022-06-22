#pragma once
class Converter
{
public:

	static std::vector<std::array<char, 480>> string_to_char_arrays(std::string string);
	static std::string char_arrays_to_string(std::vector<std::array<char, 480>> vector_of_arrays);
};

