
#include"Cpu.h"
#include<iostream>
#include<string>



int main()
{

	cpu8085 cpu;

	uint8_t Ak;
	uint8_t Bk;

	uint16_t Ck;


	Ak = 0xFF;
	Bk = 0xFE;
	
	std::cout << ((Ak << 8) + Bk) << std::endl;
	std::cout << "Arpit" << std::endl;

	
	return 0;
}