#pragma once

#include "reference.h"


class module8085:public Reference {
	GDCLASS(module8085, Reference);

protected:
	static void _bind_methods();

public:
	//Godot accessible functions
	void Set_A(uint8_t);
	void Set_B(uint8_t);
	void Set_C(uint8_t);
	void Set_D(uint8_t);
	void Set_E(uint8_t);
	void Set_H(uint8_t);
	void Set_L(uint8_t);
	void Set_OpcodeAt(uint16_t, uint8_t);

	void Set_S(bool);
	void Set_Z(bool);
	void Set_AC(bool);
	void Set_P(bool);
	void Set_CY(bool);





	uint8_t Get_A();
	uint8_t Get_B();
	uint8_t Get_C();
	uint8_t Get_D();
	uint8_t Get_E();
	uint8_t Get_H();
	uint8_t Get_L();

	uint8_t Get_Status();

	bool Get_S();
	bool Get_Z();
	bool Get_AC();
	bool Get_P();
	bool Get_CY();



	uint8_t Get_OpcodeAt(uint16_t);

	uint16_t Get_SP();
	uint16_t Get_PC();


	







	//Sp and pc

	void Set_SP(uint16_t);
	void Set_PC(uint16_t);


	//Opcode Execute
	void RunOpcode(uint8_t);

	std::vector<std::string> Get_Errors();


	

};

