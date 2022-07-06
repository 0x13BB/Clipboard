#pragma once
struct Pocket_builder
{
	uint64_t pocket_type; // 
	uint64_t unique_id;
	uint64_t pocket_number;
	uint64_t pocket_total_numbers;
	std::array<char, 480> arrch;


	static std::vector<std::array<char, 512>> get_single_pocket(
		uint64_t pocket_type,
		uint64_t unique_id,
		uint64_t pocket_number,
		uint64_t pocket_total_numbers,
		std::array<char, 480> data_array);

	 
};

