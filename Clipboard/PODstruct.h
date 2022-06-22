#pragma once

struct PODstruct //512 byte struct
{
	uint64_t pocket_type; // 
	int64_t time_id;
	//int64_t count_id;
	uint64_t pocket_number;
	uint64_t pocket_total_numbers;
	std::array<char, 480> arrch;
	
	
	
};
