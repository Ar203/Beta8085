
#include"Cpu.h"
#include<iostream>
#include<string>



int main()
{

	cpu8085 cpu;

	std::array<uint8_t, 50> code;

	code[0] = 0x06;
	code[1] = 0x80;
	code[2] = 0x0E;
	code[3] = 0x00;
	code[4] = 0x0A;
	code[5] = 0xA0;
	code[6] = 0x34;
	code[7] = 0x2F;
	code[8] = 0x76;

	uint16_t Addr = 0x0000;
	for (auto i : code)
	{
		cpu.cpuWrite(Addr, i);
		Addr++;
	}

	uint8_t data = cpu.cpuRead(0x0000, false);

	cpu.Execute(data);

	return 0;
}