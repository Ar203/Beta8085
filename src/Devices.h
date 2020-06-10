#pragma once

#include<array>
#include<cstdint>




class Ram
{
public:
	std::array<uint8_t, 64 * 1024> M64k;
public:
	Ram();
	~Ram();

	void Reset();
};

class IODevice
{
public:
	std::array<uint8_t, 4> out;
	std::array<uint8_t, 4> in;
public:
	IODevice();
	~IODevice();

	void Reset();
};


