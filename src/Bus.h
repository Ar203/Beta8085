#ifndef BUS_H
#define BUS_H


#include "Devices.h"



class Bus
{
public:
	Ram ram;

public:
	Bus();
	~Bus();

	uint8_t read(uint16_t, bool);
	void write(uint16_t, uint8_t);

};

#endif