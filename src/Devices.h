#include<array>
#include<cstdint>


#ifndef DEVICES_H
#define DEVICES_H


class Ram
{
public:
	std::array<uint8_t, 64 * 1024> M64k;
public:
	Ram();
	~Ram();

	void Reset();
};

#endif // !DEVICES_H

