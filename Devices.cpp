#include "Devices.h"

Ram::Ram()
{
	M64k = {};
}
Ram::~Ram() {};

void Ram::Reset() // Reseting the values in the Ram
{
	for (auto& i : M64k)
		i = 0x00;
}
nvbhnvbcv