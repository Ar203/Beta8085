
#include"Cpu.h"
#include<iostream>
#include<string>




int main()
{

	cpu8085 cpu;

	printf("**************************Console 8085 simulator*******************************");
	printf("\nList Of Commands:\n");
	printf("<CR> = Enter_Key, Shift+4 = Sh4, Addr = 16 bit Hex");

	printf("L (Starting Addr), (End Addr)");
	printf(" :List A Memory Block\n");

	printf("M (Starting Addr) <CR>");
	printf(" :Examine/Modify Memory\n");

	printf("E (Addr) <CR>");
	printf(" :Enter A Memory Block\n");

	printf("R (Register Identifier) <CR>");
	printf(" :Examine/Modify Register...\n");
	printf("..A,B,C,D,E,F,I,H,L,S,P..\n");
	printf("P = ProgramCounter, S = StackPointer, I = InterruptMask");


	printf("S (Starting Addr) <CR>\n");
	printf("G (Starting Addr) Sh4\n");




	return 0;
}