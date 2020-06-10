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

IODevice::IODevice()
{
	out = {};
	in = {};
}

IODevice::~IODevice() {};

void IODevice::Reset()
{
	for (auto& i : in)
		i = 0x00;
	for (auto& i : in)
		i = 0x00;
}
