#pragma once
#include "Devices.h"



class Bus
{
public:
	Ram ram;
	IODevice io;

public:
	Bus();
	~Bus();

	uint8_t read(uint16_t, bool);
	uint8_t read(uint16_t, bool, bool);
	void write(uint16_t, uint8_t);
	void write(uint16_t, uint8_t, bool);

};

