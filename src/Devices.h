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


