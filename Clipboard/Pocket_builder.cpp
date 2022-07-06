#include "pch.h"
#include "Pocket_builder.h"

#include "PODstruct.h"

std::vector<std::array<char, 512>> get_single_pocket(
	uint64_t pocket_type,
	uint64_t unique_id,
	uint64_t pocket_number,
	uint64_t pocket_total_numbers,
	std::array<char, 480> data_array)
{

	PODstruct data_struct = {};

	switch (pocket_type)
	{
	case 0:
		data_struct.pocket_type = 0;
		data_struct.unique_id = unique_id;
		data_struct.pocket_number = 1;
		data_struct.pocket_total_numbers = 1;
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;

	}




	return std::vector<std::array<char, 512>>();
}
