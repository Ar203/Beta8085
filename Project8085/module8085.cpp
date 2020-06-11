
#include "module8085.h"
#include "Devices.h"
#include "Bus.h"
#include "Cpu.h"

cpu8085 CpuMain;

void module8085::_bind_methods() {
	ClassDB::bind_method(D_METHOD("Set_A"), &module8085::Set_A);
	ClassDB::bind_method(D_METHOD("Set_B"), &module8085::Set_B);
	ClassDB::bind_method(D_METHOD("Set_C"), &module8085::Set_C);
	ClassDB::bind_method(D_METHOD("Set_D"), &module8085::Set_D);
	ClassDB::bind_method(D_METHOD("Set_E"), &module8085::Set_E);
	ClassDB::bind_method(D_METHOD("Set_H"), &module8085::Set_H);
	ClassDB::bind_method(D_METHOD("Set_L"), &module8085::Set_L);

	ClassDB::bind_method(D_METHOD("Set_PC"), &module8085::Set_PC);
	ClassDB::bind_method(D_METHOD("Set_SP"), &module8085::Set_SP);

	ClassDB::bind_method(D_METHOD("Set_OpcodeA"), &module8085::Set_OpcodeAt);


	ClassDB::bind_method(D_METHOD("Get_A"), &module8085::Get_A);
	ClassDB::bind_method(D_METHOD("Get_B"), &module8085::Get_B);
	ClassDB::bind_method(D_METHOD("Get_C"), &module8085::Get_C);
	ClassDB::bind_method(D_METHOD("Get_D"), &module8085::Get_D);
	ClassDB::bind_method(D_METHOD("Get_E"), &module8085::Get_E);
	ClassDB::bind_method(D_METHOD("Get_H"), &module8085::Get_H);
	ClassDB::bind_method(D_METHOD("Get_L"), &module8085::Get_L);

	ClassDB::bind_method(D_METHOD("Get_PC"), &module8085::Get_PC);
	ClassDB::bind_method(D_METHOD("Get_SP"), &module8085::Get_SP);

	ClassDB::bind_method(D_METHOD("Get_Errors"), &module8085::Get_Errors);
	ClassDB::bind_method(D_METHOD("Get_Status"), &module8085::Get_Status);

	ClassDB::bind_method(D_METHOD("Get_S"), &module8085::Set_S);
	ClassDB::bind_method(D_METHOD("Get_Z"), &module8085::Set_Z);
	ClassDB::bind_method(D_METHOD("Get_AC"), &module8085::Set_AC);
	ClassDB::bind_method(D_METHOD("Get_P"), &module8085::Set_P);
	ClassDB::bind_method(D_METHOD("Get_CY"), &module8085::Set_CY);
}






//Setters
void module8085::Set_A(uint8_t x) {
	CpuMain.A = x;
}
void module8085::Set_B(uint8_t x) {
	CpuMain.B = x;
}
void module8085::Set_C(uint8_t x) {
	CpuMain.C = x;
}
void module8085::Set_D(uint8_t x) {
	CpuMain.D = x;
}
void module8085::Set_E(uint8_t x) {
	CpuMain.E = x;
}
void module8085::Set_H(uint8_t x) {
	CpuMain.H = x;
}
void module8085::Set_L(uint8_t x) {
	CpuMain.L = x;
}

void module8085::Set_SP(uint16_t x) {
	CpuMain.sp = x;
}
void module8085::Set_PC(uint16_t x) {
	CpuMain.pc = x;
}

void module8085::Set_CY(bool x) {
	CpuMain.CY = int(x);
}
void module8085::Set_AC(bool x) {
	CpuMain.AC = int(x);
}
void module8085::Set_Z(bool x) {
	CpuMain.Z = int(x);
}
void module8085::Set_P(bool x) {
	CpuMain.P = int(x);
}
void module8085::Set_S(bool x) {
	CpuMain.S = int(x);
}










void module8085::Set_OpcodeAt(uint16_t addr, uint8_t x) {
	CpuMain.cpuWrite(addr, x);
}

uint8_t module8085::Get_OpcodeAt(uint16_t addr) {
	CpuMain.cpuRead(addr, false)
}



//Getters
uint8_t module8085::Get_A() { return CpuMain.A; }
uint8_t module8085::Get_B() { return CpuMain.A; }
uint8_t module8085::Get_C() { return CpuMain.A; }
uint8_t module8085::Get_D() { return CpuMain.A; }
uint8_t module8085::Get_E() { return CpuMain.A; }
uint8_t module8085::Get_H() { return CpuMain.A; }
uint8_t module8085::Get_L() { return CpuMain.A; }
uint16_t module8085::Get_SP() { return CpuMain.sp; }
uint16_t module8085::Get_PC() { return CpuMain.pc; }

uint8_t module8085::Get_Status() { return CpuMain.GetFlags(); }

bool module8085::Get_CY() { return bool(CpuMain.CY);}
bool module8085::Get_AC() { return bool(CpuMain.AC);}
bool module8085::Get_Z() { return bool(CpuMain.Z); }
bool module8085::Get_P() { return bool(CpuMain.P); }
bool module8085::Get_S() { return bool(CpuMain.S); }




std::vector<std::string> module8085::Get_Errors(){
	return CpuMain.GetErrors();
}


void module8085::RunOpcode(uint8_t x) {
	CpuMain.Execute(x, false);
}















