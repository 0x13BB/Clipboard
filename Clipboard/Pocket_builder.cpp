#include "pch.h"
#include "Pocket_builder.h"

#include "PODstruct.h"

std::vector<std::array<char, 512>> Pocket_builder::create_single_pocket(
	uint64_t pocket_type,
	uint64_t unique_id,
	uint64_t pocket_number,
	uint64_t pocket_total_numbers,
	const std::array<char, 480> &data_array)

{

	PODstruct data_struct = {};

	std::vector<std::array<char, 512>> return_vector(1);

	std::array<char, 512> return_array = {};

	switch (pocket_type)
	{
	case 0:
		data_struct.pocket_type = 0;
		data_struct.unique_id = unique_id;
		data_struct.pocket_number = 1;
		data_struct.pocket_total_numbers = 1;
		data_struct.arrch = data_array;

		for (size_t i = 0; i < 512; i++)
		{
			return_array[i] = reinterpret_cast<char*>(&data_struct)[i];
		}

		return_vector[0] = return_array;

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

	return return_vector;
}


std::vector<std::array<char, 512>> Pocket_builder::create_single_empty_pocket(
	uint64_t pocket_type,
	uint64_t unique_id,
	uint64_t pocket_number,
	uint64_t pocket_total_numbers)
{
	std::array<char, 480> empty_array = {};

	return Pocket_builder::create_single_pocket(pocket_type,
		unique_id,
		pocket_number,
		pocket_total_numbers,
		empty_array);
}
