#include"Cpu.h"
#include<iostream>



cpu8085::cpu8085()
{
	bus = new Bus;
	pc = 0x0000;
	sp = 0x2000;
	//Execute(&pc);
};

cpu8085::~cpu8085()
{
	delete bus;
};


uint8_t cpu8085::cpuRead(uint16_t addr, bool bReadOnly = false)
{
	return (bus->read(addr,bReadOnly));
}

void cpu8085::cpuWrite(uint16_t addr, uint8_t data)
{
	bus->write(addr, data);
}

void cpu8085::Reset()
{
	bus->ram.Reset();
	status = 0x00;
}

void cpu8085::ConnectBus(Bus* ptr)
{
	bus = ptr;
}

uint8_t cpu8085::GetFlag(Flags8085 f)
{
	return ((status & f) > 0) ? 1 : 0;
}

void cpu8085::SetFlag(Flags8085 flag, bool b)
{
	if (b)
		status = status | flag; // OR operation between the bool and status
	else
		status = status & flag;

}


uint8_t cpu8085::AddByte(uint8_t Operand1, uint8_t Operand2, CarryUpdate Cy_check)
{
	return 0;
}

void cpu8085::Execute()
{
	int test=0;
	for(auto opcode = cpuRead(pc,false);;)
	{
		switch (opcode)
		{

		case(NOP):
			//Does nothing
			break;

		case(LXI_B_D16):
			C = cpuRead(pc++, false);
			B = cpuRead(pc++, false);
			// The last 8 bits are stored first
			// in memory
			break;
		case(STAX_B):
			cpuWrite((B << 8 | C), A);
			break;
		case(INX_B):
			C++;
			if (C == 0)
			{
				B++;
				if ((B << 8 | C) > 0xFFFF) { B = 0; C = 0; }
			}
			break;
		case(INR_B):
			//B = AddByte(B, 0x01, setcarry);
			break;
		case(DCR_B):
			//B = SubByte(B, 0x01, setcarry)
			//UnImplemented INSTRUCTION
			break;
		case(MVI_B_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RLC):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_1):
			//UnImplemented INSTRUCTION
			break;
		case(DAD_B):
			exit(0);
			//UnImplemented INSTRUCTION
			break;
		case(LDAX_B):
			//UnImplemented INSTRUCTION
			break;
		case(DCX_B):
			//UnImplemented INSTRUCTION
			break;
		case(INR_C):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_C):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_C_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RRC):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_2):
			//UnImplemented INSTRUCTION
			break;
		case(LXI_D_D16):
			//UnImplemented INSTRUCTION
			break;
		case(STAX_D):
			//UnImplemented INSTRUCTION
			break;
		case(INX_D):
			//UnImplemented INSTRUCTION
			break;
		case(INR_D):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_D):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_D_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RAL):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_3):
			//UnImplemented INSTRUCTION
			break;
		case(DAD_D):
			//UnImplemented INSTRUCTION
			break;
		case(LDAX_D):
			//UnImplemented INSTRUCTION
			break;
		case(DCX_D):
			//UnImplemented INSTRUCTION
			break;
		case(INR_E):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_E):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_E_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RAR):
			//UnImplemented INSTRUCTION
			break;
		case(RIM):
			//UnImplemented INSTRUCTION
			break;
		case(LXI_H_D16):
			//UnImplemented INSTRUCTION
			break;
		case(SHLD_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(INX_H):
			//UnImplemented INSTRUCTION
			break;
		case(INR_H):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_H):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_H_D8):
			//UnImplemented INSTRUCTION
			break;
		case(DAA):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_4):
			//UnImplemented INSTRUCTION
			break;
		case(DAD_H):
			//UnImplemented INSTRUCTION
			break;
		case(LHLD_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(DCX_H):
			//UnImplemented INSTRUCTION
			break;
		case(INR_L):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_L):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_L):
			//UnImplemented INSTRUCTION
			break;
		case(CMA):
			//UnImplemented INSTRUCTION
			break;
		case(SIM):
			//UnImplemented INSTRUCTION
			break;
		case(LXI_SP_D16):
			//UnImplemented INSTRUCTION
			break;
		case(STA_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(INX_SP):
			//UnImplemented INSTRUCTION
			break;
		case(INR_M):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_M):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_M_D8):
			//UnImplemented INSTRUCTION
			break;
		case(STC):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_5):
			//UnImplemented INSTRUCTION
			break;
		case(DAD_SP):
			//UnImplemented INSTRUCTION
			break;
		case(LDA_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(DCX_SP):
			//UnImplemented INSTRUCTION
			break;
		case(INR_A):
			//UnImplemented INSTRUCTION
			break;
		case(DCR_A):
			//UnImplemented INSTRUCTION
			break;
		case(MVI_A_D8):
			//UnImplemented INSTRUCTION
			break;
		case(CMC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_BA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_CA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_DA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_ED):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_EA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_HA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_LA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_MB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_MC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_MD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_ME):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_MH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_ML):
			//UnImplemented INSTRUCTION
			break;
		case(HLT):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_MA):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AB):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AC):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AD):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AE):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AH):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AL):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AM):
			//UnImplemented INSTRUCTION
			break;
		case(MOV_AA):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_B):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_C):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_D):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_E):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_H):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_L):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_M):
			//UnImplemented INSTRUCTION
			break;
		case(ADD_A):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_B):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_C):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_D):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_E):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_H):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_L):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_M):
			//UnImplemented INSTRUCTION
			break;
		case(ADC_A):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_B):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_C):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_D):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_E):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_H):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_L):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_M):
			//UnImplemented INSTRUCTION
			break;
		case(SUB_A):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_B):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_C):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_D):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_E):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_H):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_L):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_M):
			//UnImplemented INSTRUCTION
			break;
		case(SBB_A):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_B):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_C):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_D):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_E):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_H):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_L):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_M):
			//UnImplemented INSTRUCTION
			break;
		case(ANA_A):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_B):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_C):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_D):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_E):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_H):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_L):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_M):
			//UnImplemented INSTRUCTION
			break;
		case(XRA_A):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_B):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_C):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_D):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_E):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_H):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_L):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_M):
			//UnImplemented INSTRUCTION
			break;
		case(ORA_A):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_B):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_C):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_D):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_E):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_H):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_L):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_M):
			//UnImplemented INSTRUCTION
			break;
		case(CMP_A):
			//UnImplemented INSTRUCTION
			break;
		case(RNZ):
			//UnImplemented INSTRUCTION
			break;
		case(POP_B):
			//UnImplemented INSTRUCTION
			break;
		case(JNZ_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(JMP_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(CNZ_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(PUSH_B):
			//UnImplemented INSTRUCTION
			break;
		case(ADR_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_0):
			//UnImplemented INSTRUCTION
			break;
		case(RZ):
			//UnImplemented INSTRUCTION
			break;
		case(RET):
			//UnImplemented INSTRUCTION
			break;
		case(JZ_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_6):
			//UnImplemented INSTRUCTION
			break;
		case(CZ_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(CALL_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(ACI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_1):
			//UnImplemented INSTRUCTION
			break;
		case(RNC):
			//UnImplemented INSTRUCTION
			break;
		case(POP_D):
			//UnImplemented INSTRUCTION
			break;
		case(JNC_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(OUT_D8):
			//UnImplemented INSTRUCTION
			break;
		case(CNC_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(PUSH_D):
			//UnImplemented INSTRUCTION
			break;
		case(SUI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_2):
			//UnImplemented INSTRUCTION
			break;
		case(RC):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_7):
			//UnImplemented INSTRUCTION
			break;
		case(JC_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(IN_D8):
			//UnImplemented INSTRUCTION
			break;
		case(CC_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_8):
			//UnImplemented INSTRUCTION
			break;
		case(SBI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_3):
			//UnImplemented INSTRUCTION
			break;
		case(RPO):
			//UnImplemented INSTRUCTION
			break;
		case(POP_H):
			//UnImplemented INSTRUCTION
			break;
		case(JPO_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XTHL):
			//UnImplemented INSTRUCTION
			break;
		case(CPO_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(PUSH_H):
			//UnImplemented INSTRUCTION
			break;
		case(ANI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_4):
			//UnImplemented INSTRUCTION
			break;
		case(RPE):
			//UnImplemented INSTRUCTION
			break;
		case(PCHL):
			//UnImplemented INSTRUCTION
			break;
		case(JPE_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XCHG):
			//UnImplemented INSTRUCTION
			break;
		case(CPE_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_9):
			//UnImplemented INSTRUCTION
			break;
		case(XRI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_5):
			//UnImplemented INSTRUCTION
			break;
		case(RP):
			//UnImplemented INSTRUCTION
			break;
		case(POP_PSW):
			//UnImplemented INSTRUCTION
			break;
		case(JP_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(DI):
			//UnImplemented INSTRUCTION
			break;
		case(CP_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(PUSH_PSW):
			//UnImplemented INSTRUCTION
			break;
		case(ORI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_6):
			//UnImplemented INSTRUCTION
			break;
		case(RM):
			//UnImplemented INSTRUCTION
			break;
		case(SPHL):
			//UnImplemented INSTRUCTION
			break;
		case(JM_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(EI):
			//UnImplemented INSTRUCTION
			break;
		case(CM_ADR):
			//UnImplemented INSTRUCTION
			break;
		case(XXXX_10):
			//UnImplemented INSTRUCTION
			break;
		case(CPI_D8):
			//UnImplemented INSTRUCTION
			break;
		case(RST_7):
			//UnImplemented INSTRUCTION
			break;
		default:
			break;
		}
	}


}

