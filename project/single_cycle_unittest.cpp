#include "gtest/gtest.h"
#include "single_cycle.h"
#include <climits>
#include <queue>
#include <iostream>
using namespace std;

#define SHORT_MIN (int)((short)0x8000)
#define SHORT_MAX (int)((short)0x7FFF)

   
class SimulateTest : public ::testing::Test {
	protected:
		Simulate sim;
};


TEST_F(SimulateTest, type_Test)
{
	Simulate sim_type;

	// add
	sim_type.instruction(0xC20);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sub
	sim_type.instruction(0xC22);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// and
	sim_type.instruction(0xC24);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// or
	sim_type.instruction(0xC25);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// xor
	sim_type.instruction(0xC26);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// nor
	sim_type.instruction(0xC27);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// nand
	sim_type.instruction(0xC28);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// slt
	sim_type.instruction(0xC2A);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sll
	sim_type.instruction(0xC00);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// srl
	sim_type.instruction(0xC02);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sra
	sim_type.instruction(0xC03);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// jr
	sim_type.instruction(0xC08);
	EXPECT_STREQ("Rtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// addi
	sim_type.instruction(0x200100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lw
	sim_type.instruction(0x8C0100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lh
	sim_type.instruction(0x840100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lhu
	sim_type.instruction(0x940100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lb
	sim_type.instruction(0x800100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lbu
	sim_type.instruction(0x900100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lbu
	sim_type.instruction(0x900100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sw
	sim_type.instruction(0xAC0100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sh
	sim_type.instruction(0xA40100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// sb
	sim_type.instruction(0xA00100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// lui
	sim_type.instruction(0x3C0100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// andi
	sim_type.instruction(0x300100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// ori
	sim_type.instruction(0x340100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// nori
	sim_type.instruction(0x380100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// slti
	sim_type.instruction(0x280100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// beq
	sim_type.instruction(0x100100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// bne
	sim_type.instruction(0x140100F0);
	EXPECT_STREQ("Itype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// j
	sim_type.instruction(0x80100F0);
	EXPECT_STREQ("Jtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// jal
	sim_type.instruction(0xC0100F0);
	EXPECT_STREQ("Jtype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

	// halt
	sim_type.instruction(0xFC0100F0);
	EXPECT_STREQ("Stype\n", sim_type.snapshotList.front());
	sim_type.snapshotList.pop();
	EXPECT_EQ(0, sim_type.snapshotList.size());
	sim_type.initialize();

}

	/*
		value of register from 0x80000000 to 0x7FFFFFFF are valid
		ID of register from 1 to 31 are valid

		SV min : Reg[rs] = INT_MIN
		SV min+ : Reg[rs] = INT_MIN + 1
		SV normal : Reg[rs] = 0
		SV max- : Reg[rs] = INT_MAX - 1
		SV max : Reg[rs] = INT_MAX
		
		TV min : Reg[rt] = INT_MIN
		TV min+ : Reg[rt] = INT_MIN + 1
		TV normal : Reg[rt] = 0
		TV max- : Reg[rt] = INT_MAX - 1
		TV max : Reg[rt] = INT_MAX
	
		26 SN test case for add, sub, and, or, xor, nor, nand, slt
	*/

TEST_F(SimulateTest, RtypeInstruction_Add_Test)
{
	Simulate sim_add;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_add.setReg(16, INT_MIN);
	sim_add.Add(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_add.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min, TV min}
	sim_add.setReg(16, INT_MIN);
	sim_add.Add(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min, TV min+}
	sim_add.setReg(16, INT_MIN);
	sim_add.setReg(31, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(1, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min, TV normal}
	sim_add.setReg(16, INT_MIN);
	sim_add.Add(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MIN, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min, TV max-}
	sim_add.setReg(16, INT_MIN);
	sim_add.setReg(31, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-2, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min, TV max}
	sim_add.setReg(16, INT_MIN);
	sim_add.setReg(31, INT_MAX);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min+, TV min}
	sim_add.setReg(16, INT_MIN+1);
	sim_add.setReg(31, INT_MIN);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(1, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min+, TV min+}
	sim_add.setReg(16, INT_MIN+1);
	sim_add.setReg(31, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(2, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min+1, TV normal}
	sim_add.setReg(16, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MIN+1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min+1, TV max-}
	sim_add.setReg(16, INT_MIN+1);
	sim_add.setReg(31, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV min+1, TV max}
	sim_add.setReg(16, INT_MIN+1);
	sim_add.setReg(31, INT_MAX);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(0, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV normal, TV min}
	sim_add.setReg(16, 0);
	sim_add.setReg(31, INT_MIN);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MIN, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV normal, TV min+}
	sim_add.setReg(16, 0);
	sim_add.setReg(31, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MIN+1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV normal, TV normal}
	sim_add.setReg(16, 0);
	sim_add.Add(DonotCare, 16, 0, 16);
	EXPECT_EQ(0, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV normal, TV max-}
	sim_add.setReg(16, 0);
	sim_add.setReg(31, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MAX-1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV normal, TV max}
	sim_add.setReg(16, 0);
	sim_add.setReg(31, INT_MAX);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MAX, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max-, TV min}
	sim_add.setReg(16, INT_MAX-1);
	sim_add.setReg(31, INT_MIN);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-2, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max-, TV min+}
	sim_add.setReg(16, INT_MAX-1);
	sim_add.setReg(31, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max-1, TV normal}
	sim_add.setReg(16, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MAX-1, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max-, TV max-}
	sim_add.setReg(16, INT_MAX-1);
	sim_add.setReg(31, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-4, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();
	
	// {SV max-, TV max}
	sim_add.setReg(16, INT_MAX-1);
	sim_add.setReg(31, INT_MAX);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-3, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();
	
	// {SV max, TV min}
	sim_add.setReg(16, INT_MAX);
	sim_add.setReg(31, INT_MIN);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_add.Reg[16]);
	sim_add.initialize();

	// {SV max, TV min+}
	sim_add.setReg(16, INT_MAX);
	sim_add.setReg(31, INT_MIN+1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(0, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max, TV normal}
	sim_add.setReg(16, INT_MAX);
	sim_add.Add(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MAX, sim_add.Reg[16]);
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();

	// {SV max, TV max-}
	sim_add.setReg(16, INT_MAX);
	sim_add.setReg(31, INT_MAX-1);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-3, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();
	
	// {SV max, TV max}
	sim_add.setReg(16, INT_MAX);
	sim_add.setReg(31, INT_MAX);
	sim_add.Add(DonotCare, 16, 31, 16);
	EXPECT_EQ(-2, sim_add.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_add.errorList.front());
	sim_add.errorList.pop();
	EXPECT_EQ(0, sim_add.errorList.size());
	sim_add.initialize();
}

TEST_F(SimulateTest, RtypeInstruction_Sub_Test)
{
	Simulate sim_sub;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_sub.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min, TV min}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min, TV min+}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.setReg(31, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min, TV normal}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MIN, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min, TV max-}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.setReg(31, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(2, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min, TV max}
	sim_sub.setReg(16, INT_MIN);
	sim_sub.setReg(31, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(1, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min+, TV min}
	sim_sub.setReg(16, INT_MIN+1);
	sim_sub.setReg(31, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(1, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min+, TV min+}
	sim_sub.setReg(16, INT_MIN+1);
	sim_sub.setReg(31, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(0, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min+1, TV normal}
	sim_sub.setReg(16, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MIN+1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min+1, TV max-}
	sim_sub.setReg(16, INT_MIN+1);
	sim_sub.setReg(31, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(3, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV min+1, TV max}
	sim_sub.setReg(16, INT_MIN+1);
	sim_sub.setReg(31, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(2, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV normal, TV min}
	sim_sub.setReg(16, 0);
	sim_sub.setReg(31, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MIN, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV normal, TV min+}
	sim_sub.setReg(16, 0);
	sim_sub.setReg(31, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MAX, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV normal, TV normal}
	sim_sub.setReg(16, 0);
	sim_sub.Sub(DonotCare, 16, 0, 16);
	EXPECT_EQ(0, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV normal, TV max-}
	sim_sub.setReg(16, 0);
	sim_sub.setReg(31, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MIN+2, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV normal, TV max}
	sim_sub.setReg(16, 0);
	sim_sub.setReg(31, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(INT_MIN+1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max-, TV min}
	sim_sub.setReg(16, INT_MAX-1);
	sim_sub.setReg(31, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-2, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max-, TV min+}
	sim_sub.setReg(16, INT_MAX-1);
	sim_sub.setReg(31, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-3, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max-1, TV normal}
	sim_sub.setReg(16, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MAX-1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max-, TV max-}
	sim_sub.setReg(16, INT_MAX-1);
	sim_sub.setReg(31, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(0, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();
	
	// {SV max-, TV max}
	sim_sub.setReg(16, INT_MAX-1);
	sim_sub.setReg(31, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();
	
	// {SV max, TV min}
	sim_sub.setReg(16, INT_MAX);
	sim_sub.setReg(31, INT_MIN);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max, TV min+}
	sim_sub.setReg(16, INT_MAX);
	sim_sub.setReg(31, INT_MIN+1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(-2, sim_sub.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sub.errorList.front());
	sim_sub.errorList.pop();
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max, TV normal}
	sim_sub.setReg(16, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 0, 16);
	EXPECT_EQ(INT_MAX, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();

	// {SV max, TV max-}
	sim_sub.setReg(16, INT_MAX);
	sim_sub.setReg(31, INT_MAX-1);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(1, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();
	
	// {SV max, TV max}
	sim_sub.setReg(16, INT_MAX);
	sim_sub.setReg(31, INT_MAX);
	sim_sub.Sub(DonotCare, 16, 31, 16);
	EXPECT_EQ(0, sim_sub.Reg[16]);
	EXPECT_EQ(0, sim_sub.errorList.size());
	sim_sub.initialize();
}

	/*
		value of register from 0x80000000 to 0x7FFFFFFF are valid
		ID of register from 1 to 31 are valid
		shamt from 0 to 31 are valid

		TV min : Reg[rt] = INT_MIN
		TV min+ : Reg[rt] = INT_MIN + 1
		TV normal : Reg[rt] = 0
		TV max- : Reg[rt] = INT_MAX - 1
		TV max : Reg[rt] = INT_MAX

		shamt min : 0
		shamt min+ : 1
		shamt normal : 16
		shamt max- : 30
		shamt max : 31
	
		26 SN test case for sll, srl, sra
	*/

TEST_F(SimulateTest, RtypeInstruction_Sll_Test)
{
	Simulate sim_sll;
	int DonotCare = -1;

	// {TV min, shamt min}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 0, 0);
	EXPECT_EQ(0, sim_sll.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_sll.errorList.front());
	sim_sll.errorList.pop();
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min, shamt min}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min, shamt min+}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 16, 1);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min, shamt normal}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min, shamt max-}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 16, 30);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min, shamt max}
	sim_sll.setReg(16, INT_MIN);
	sim_sll.Sll(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min+, shamt min}
	sim_sll.setReg(16, INT_MIN+1);
	sim_sll.Sll(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN+1, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min+, shamt min+}
	sim_sll.setReg(16, INT_MIN+1);
	sim_sll.Sll(DonotCare, 16, 16, 1);
	EXPECT_EQ(2, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min+1, shamt normal}
	sim_sll.setReg(16, INT_MIN+1);
	sim_sll.Sll(DonotCare, 16, 16, 16);
	EXPECT_EQ(0x10000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min+1, shamt max-}
	sim_sll.setReg(16, INT_MIN+1);
	sim_sll.Sll(DonotCare, 16, 16, 30);
	EXPECT_EQ(0x40000000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV min+1, shamt max}
	sim_sll.setReg(16, INT_MIN+1);
	sim_sll.Sll(DonotCare, 16, 16, 31);
	EXPECT_EQ(0x80000000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV normal, shamt min}
	sim_sll.setReg(16, 0);
	sim_sll.Sll(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV normal, shamt min+}
	sim_sll.setReg(16, 0);
	sim_sll.Sll(DonotCare, 16, 16, 1);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV normal, shamt normal}
	sim_sll.setReg(16, 0);
	sim_sll.Sll(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV normal, shamt max-}
	sim_sll.setReg(16, 0);
	sim_sll.Sll(DonotCare, 16, 16, 30);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV normal, shamt max}
	sim_sll.setReg(16, 0);
	sim_sll.Sll(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max-, shamt min}
	sim_sll.setReg(16, INT_MAX-1);
	sim_sll.Sll(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX-1, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max-, shamt min+}
	sim_sll.setReg(16, INT_MAX-1);
	sim_sll.Sll(DonotCare, 16, 16, 1);
	EXPECT_EQ(0xFFFFFFFC, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max-1, shamt normal}
	sim_sll.setReg(16, INT_MAX-1);
	sim_sll.Sll(DonotCare, 16, 16, 16);
	EXPECT_EQ(0xFFFE0000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max-, shamt max-}
	sim_sll.setReg(16, INT_MAX-1);
	sim_sll.Sll(DonotCare, 16, 16, 30);
	EXPECT_EQ(INT_MIN, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();
	
	// {TV max-, shamt max}
	sim_sll.setReg(16, INT_MAX-1);
	sim_sll.Sll(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();
	
	// {TV max, shamt min}
	sim_sll.setReg(16, INT_MAX);
	sim_sll.Sll(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max, shamt min+}
	sim_sll.setReg(16, INT_MAX);
	sim_sll.Sll(DonotCare, 16, 16, 1);
	EXPECT_EQ(0xFFFFFFFE, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max, shamt normal}
	sim_sll.setReg(16, INT_MAX);
	sim_sll.Sll(DonotCare, 16, 16, 16);
	EXPECT_EQ(0xFFFF0000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();

	// {TV max, shamt max-}
	sim_sll.setReg(16, INT_MAX);
	sim_sll.Sll(DonotCare, 16, 16, 30);
	EXPECT_EQ(0xC0000000, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();
	
	// {TV max, shamt max}
	sim_sll.setReg(16, INT_MAX);
	sim_sll.Sll(DonotCare, 16, 16, 31);
	EXPECT_EQ(INT_MIN, sim_sll.Reg[16]);
	EXPECT_EQ(0, sim_sll.errorList.size());
	sim_sll.initialize();
}

	/*
		value of register which is from 0 to 1024 and is divisible by 4 are valid
		ID of register from 1 to 31 are valid

		SV min : Reg[rs] = 0
		SV min+ : Reg[rs] = 4
		SV normal : Reg[rs] = 512
		SV max- : Reg[rs] = 1000
		SV max : Reg[rs] = 1024
		
		5 SN test case for jr
	*/


TEST_F(SimulateTest, RtypeInstruction_JR_Test)
{
	Simulate sim_jr;
	int DonotCare = -1;

	// {SV min }
	sim_jr.setReg(16, 0);
	sim_jr.Jr(DonotCare, 16);
	EXPECT_EQ(0, sim_jr.PC);
	EXPECT_EQ(0, sim_jr.errorList.size());
	sim_jr.initialize();

	// {SV min+}
	sim_jr.setReg(16, 4);
	sim_jr.Jr(DonotCare, 16);
	EXPECT_EQ(4, sim_jr.PC);
	EXPECT_EQ(0, sim_jr.errorList.size());
	sim_jr.initialize();

	// {SV normal}
	sim_jr.setReg(16, 512);
	sim_jr.Jr(DonotCare, 16);
	EXPECT_EQ(512, sim_jr.PC);
	EXPECT_EQ(0, sim_jr.errorList.size());
	sim_jr.initialize();

	// {SV max-}
	sim_jr.setReg(16, 1000);
	sim_jr.Jr(DonotCare, 16);
	EXPECT_EQ(1000, sim_jr.PC);
	EXPECT_EQ(0, sim_jr.errorList.size());
	sim_jr.initialize();

	// {SV max}
	sim_jr.setReg(16, 1024);
	sim_jr.Jr(DonotCare, 16);
	EXPECT_EQ(1024, sim_jr.PC);
	EXPECT_EQ(0, sim_jr.errorList.size());
	sim_jr.initialize();
}
	/*
		value of register from 0x80000000 ato 0x7FFFFFF are valid
		value of immediate from -32768(0x8000) to 32767(0x7FFF) are valid
		ID of register from 1 to 31 are valid

		SV min : Reg[rs] = INT_MIN
		SV min+ : Reg[rs] = INT_MIN+1
		SV normal : Reg[rs] = 0
		SV max- : Reg[rs] = INT_MAX-
		SV max : Reg[rs] = INT_MAX
		
		IMM min : immediate = -32768(SHORT_MIN)
		IMM min+ : immediate = -32768+1
		IMM normal : immediate = 0
		IMM max- : immediate = 32767-1
		IMM max : immediate = 32767(SHORT_MAX)
		
		26 SN test case for addi
	*/

TEST_F(SimulateTest, ItypeInstruction_Addi_Test)
{
	Simulate sim_addi;
	int DonotCare = -1;

	// {SV min, IMM min}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_addi.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min, IMM min}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0x7FFF8000, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min, IMM min+}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0x7FFF8001, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min, IMM normal}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min, IMM max-}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x80007FFE, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min, IMM max}
	sim_addi.setReg(16, INT_MIN);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x80007FFF, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min+, IMM min}
	sim_addi.setReg(16, INT_MIN+1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0x7FFF8001, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min+, IMM min+}
	sim_addi.setReg(16, INT_MIN+1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0x7FFF8002, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min+1, IMM normal}
	sim_addi.setReg(16, INT_MIN+1);
	sim_addi.Addi(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN+1, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min+1, IMM max-}
	sim_addi.setReg(16, INT_MIN+1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x80007FFF, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV min+1, IMM max}
	sim_addi.setReg(16, INT_MIN+1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x80008000, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV normal, IMM min}
	sim_addi.setReg(16, 0);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0xFFFF8000, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV normal, IMM min+}
	sim_addi.setReg(16, 0);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0xFFFF8001, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV normal, IMM normal}
	sim_addi.setReg(16, 0);
	sim_addi.Addi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV normal, IMM max-}
	sim_addi.setReg(16, 0);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x7FFE, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV normal, IMM max}
	sim_addi.setReg(16, 0);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x7FFF, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max-, IMM min}
	sim_addi.setReg(16, INT_MAX-1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0x7FFF7FFE, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max-, IMM min+}
	sim_addi.setReg(16, INT_MAX-1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0x7FFF7FFF, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max-1, IMM normal}
	sim_addi.setReg(16, INT_MAX-1);
	sim_addi.Addi(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX-1, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max-, IMM max-}
	sim_addi.setReg(16, INT_MAX-1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x80007FFC, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();
	
	// {SV max-, IMM max}
	sim_addi.setReg(16, INT_MAX-1);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x80007FFD, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();
	
	// {SV max, IMM min}
	sim_addi.setReg(16, INT_MAX);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0x7FFF7FFF, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max, IMM min+}
	sim_addi.setReg(16, INT_MAX);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0x7FFF8000, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max, IMM normal}
	sim_addi.setReg(16, INT_MAX);
	sim_addi.Addi(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_addi.Reg[16]);
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();

	// {SV max, IMM max-}
	sim_addi.setReg(16, INT_MAX);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x80007FFD, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();
	
	// {SV max, IMM max}
	sim_addi.setReg(16, INT_MAX);
	sim_addi.Addi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x80007FFE, sim_addi.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_addi.errorList.front());
	sim_addi.errorList.pop();
	EXPECT_EQ(0, sim_addi.errorList.size());
	sim_addi.initialize();
}
	/*
		value of register from 0x80000000 ato 0x7FFFFFF are valid
		value of immediate from -32768(0x8000) to 32767(0x7FFF) are valid
		ID of register from 1 to 31 are valid
		value of address which is from 0 to 1024 and is divisible by 4 are valid
		
		SV1: {SV = INT_MIN}
		SV2: {INT_MIN < SV < 0}
		SV3: {SV = 0}
		SV4: {0 < SV < 1024}
		SV5: {SV = 1024}
		SV6: {1024 < SV <= INT_MAX}

		IMM1: {IMM = SHORT_MIN}
		IMM2: {SHORT_MIN < IMM < 0}
		IMM3: {IMM = 0}
		IMM4: {0 < IMM < 1024 }
		IMM5: {IMM = 1024}
		IMM6: {1024 < IMM <= SHORT_MAX}

		37 SN test case for lw, lh, lhu, lb, lbu, sw, sh,sb
	*/

TEST_F(SimulateTest, ItypeInstruction_Lw_Test)
{
	Simulate sim_lw;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.Lw(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lw.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 1, IMM 1}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 1, IMM 2}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 1, IMM 3}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 1, IMM 4}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 1, IMM 5}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 1, IMM 6}
	sim_lw.setReg(16, INT_MIN);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MIN, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IMM 1}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IMM 2}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(-4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IMM 3}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(-4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IMM 4}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x89ABCDEF, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IMM 5}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 2, IM 6}
	sim_lw.setReg(16, -4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 1}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 2}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 3}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x89ABCDEF, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 4}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x01234567, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 5}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 3, IMM 6}
	sim_lw.setReg(16, 0);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 4, IMM 1}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 4, IMM 2}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x89ABCDEF, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 4, IMM 3}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x01234567, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 4, IMM 4}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x1, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 4, IMM 5}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 4, IMM 6}
	sim_lw.setReg(16, 4);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(4, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 5, IMM 1}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1024, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 5, IMM 2}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lw.Reg[16]);
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 5, IMM 3}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(1024, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 5, IMM 4}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(1024, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 5, IMM 5}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(1024, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 5, IMM 6}
	sim_lw.setReg(16, 1024);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1024, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 6, IMM 1}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 6, IMM 2}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 6, IMM 3}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 6, IMM 4}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();

	// {SV 6, IMM 5}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.setDmemory(D_buffer1_length, D_buffer1);
	sim_lw.Lw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV 5, IMM 2}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MAX, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Lh_Test)
{
	Simulate sim_lh;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.Lh(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lh.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 1, IMM 1}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 1, IMM 2}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 1, IMM 3}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 1, IMM 4}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 1, IMM 5}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 1, IMM 6}
	sim_lh.setReg(16, INT_MIN);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MIN, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IMM 1}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IMM 2}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(-4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IMM 3}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(-4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IMM 4}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0xFFFF89AB, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IMM 5}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 2, IM 6}
	sim_lh.setReg(16, -4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 1}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 2}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 3}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(0xFFFF89AB, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 4}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x0123, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 5}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 3, IMM 6}
	sim_lh.setReg(16, 0);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 4, IMM 1}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 4, IMM 2}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(0xFFFF89AB, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 4, IMM 3}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x0123, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 4, IMM 4}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 4, IMM 5}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 4, IMM 6}
	sim_lh.setReg(16, 4);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(4, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 5, IMM 1}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1024, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 5, IMM 2}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lh.Reg[16]);
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 5, IMM 3}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(1024, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 5, IMM 4}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(1024, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 5, IMM 5}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(1024, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 5, IMM 6}
	sim_lh.setReg(16, 1024);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1024, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 6, IMM 1}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 6, IMM 2}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 6, IMM 3}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 6, IMM 4}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();

	// {SV 6, IMM 5}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.setDmemory(D_buffer1_length, D_buffer1);
	sim_lh.Lh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
	
	// {SV 5, IMM 2}
	sim_lh.setReg(16, INT_MAX);
	sim_lh.Lh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MAX, sim_lh.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lh.errorList.front());
	sim_lh.errorList.pop();
	EXPECT_EQ(0, sim_lh.errorList.size());
	sim_lh.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Lhu_Test)
{
	Simulate sim_lhu;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.Lhu(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lhu.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 1, IMM 1}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 1, IMM 2}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 1, IMM 3}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 1, IMM 4}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 1, IMM 5}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 1, IMM 6}
	sim_lhu.setReg(16, INT_MIN);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MIN, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IMM 1}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IMM 2}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(-4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IMM 3}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(-4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IMM 4}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x89AB, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IMM 5}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 2, IM 6}
	sim_lhu.setReg(16, -4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 1}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 2}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 3}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x89AB, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 4}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x0123, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 5}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 3, IMM 6}
	sim_lhu.setReg(16, 0);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 4, IMM 1}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 4, IMM 2}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x89AB, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 4, IMM 3}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x0123, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 4, IMM 4}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 4, IMM 5}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 4, IMM 6}
	sim_lhu.setReg(16, 4);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(4, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 5, IMM 1}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1024, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 5, IMM 2}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lhu.Reg[16]);
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 5, IMM 3}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(1024, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 5, IMM 4}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(1024, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 5, IMM 5}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(1024, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 5, IMM 6}
	sim_lhu.setReg(16, 1024);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1024, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 6, IMM 1}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 6, IMM 2}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 6, IMM 3}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 6, IMM 4}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();

	// {SV 6, IMM 5}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lhu.Lhu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
	
	// {SV 5, IMM 2}
	sim_lhu.setReg(16, INT_MAX);
	sim_lhu.Lhu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MAX, sim_lhu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lhu.errorList.front());
	sim_lhu.errorList.pop();
	EXPECT_EQ(0, sim_lhu.errorList.size());
	sim_lhu.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Lb_Test)
{
	Simulate sim_lb;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.Lb(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lb.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 1, IMM 1}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 1, IMM 2}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 1, IMM 3}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 1, IMM 4}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 1, IMM 5}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 1, IMM 6}
	sim_lb.setReg(16, INT_MIN);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MIN, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IMM 1}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IMM 2}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(-4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IMM 3}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(-4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IMM 4}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0xFFFFFF89, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IMM 5}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 2, IM 6}
	sim_lb.setReg(16, -4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 1}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 2}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 3}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(0xFFFFFF89, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 4}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x01, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 5}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 3, IMM 6}
	sim_lb.setReg(16, 0);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 4, IMM 1}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 4, IMM 2}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(0xFFFFFF89, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 4, IMM 3}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x01, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 4, IMM 4}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 4, IMM 5}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 4, IMM 6}
	sim_lb.setReg(16, 4);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(4, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 5, IMM 1}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1024, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 5, IMM 2}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lb.Reg[16]);
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 5, IMM 3}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(1024, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 5, IMM 4}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(1024, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 5, IMM 5}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(1024, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 5, IMM 6}
	sim_lb.setReg(16, 1024);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1024, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 6, IMM 1}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 6, IMM 2}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 6, IMM 3}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 6, IMM 4}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();

	// {SV 6, IMM 5}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.setDmemory(D_buffer1_length, D_buffer1);
	sim_lb.Lb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
	
	// {SV 6, IMM 6}
	sim_lb.setReg(16, INT_MAX);
	sim_lb.Lb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MAX, sim_lb.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lb.errorList.front());
	sim_lb.errorList.pop();
	EXPECT_EQ(0, sim_lb.errorList.size());
	sim_lb.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Lbu_Test)
{
	Simulate sim_lbu;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.Lbu(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lbu.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 1, IMM 1}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 1, IMM 2}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 1, IMM 3}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 1, IMM 4}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 1, IMM 5}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 1, IMM 6}
	sim_lbu.setReg(16, INT_MIN);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MIN, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IMM 1}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IMM 2}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(-4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IMM 3}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(-4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IMM 4}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x89, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IMM 5}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 2, IM 6}
	sim_lbu.setReg(16, -4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 1}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 2}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 3}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x89, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 4}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x01, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 5}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 3, IMM 6}
	sim_lbu.setReg(16, 0);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 4, IMM 1}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 4, IMM 2}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x89, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 4, IMM 3}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x01, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 4, IMM 4}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 4, IMM 5}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 4, IMM 6}
	sim_lbu.setReg(16, 4);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(4, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 5, IMM 1}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1024, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 5, IMM 2}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_lbu.Reg[16]);
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 5, IMM 3}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(1024, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 5, IMM 4}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(1024, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 5, IMM 5}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(1024, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 5, IMM 6}
	sim_lbu.setReg(16, 1024);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1024, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 6, IMM 1}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 6, IMM 2}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, -4);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 6, IMM 3}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 6, IMM 4}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 4);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();

	// {SV 6, IMM 5}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.setDmemory(D_buffer1_length, D_buffer1);
	sim_lbu.Lbu(DonotCare, 16, 16, 1024);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
	
	// {SV 6, IMM 6}
	sim_lbu.setReg(16, INT_MAX);
	sim_lbu.Lbu(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(INT_MAX, sim_lbu.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_lbu.errorList.front());
	sim_lbu.errorList.pop();
	EXPECT_EQ(0, sim_lbu.errorList.size());
	sim_lbu.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Sw_Test)
{
	Simulate sim_sw;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 1, IMM 2}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 1, IMM 3}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 1, IMM 4}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 1, IMM 5}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 1, IMM 6}
	sim_sw.setReg(16, INT_MIN);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IMM 1}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IMM 2}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IMM 3}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IMM 4}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_EQ(-4, sim_sw.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IMM 5}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_EQ(-4, sim_sw.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 2, IM 6}
	sim_sw.setReg(16, -4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 1}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 2}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 3}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_sw.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 4}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_EQ(0, sim_sw.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 5}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 3, IMM 6}
	sim_sw.setReg(16, 0);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 4, IMM 1}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 4, IMM 2}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_EQ(4, sim_sw.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 4, IMM 3}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_EQ(4, sim_sw.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 4, IMM 4}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_EQ(4, sim_sw.getDmemoryByAddr(8));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 4, IMM 5}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 4, IMM 6}
	sim_sw.setReg(16, 4);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 5, IMM 1}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 5, IMM 2}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_EQ(1024, sim_sw.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 5, IMM 3}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 5, IMM 4}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 5, IMM 5}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 5, IMM 6}
	sim_sw.setReg(16, 1024);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 6, IMM 1}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 6, IMM 2}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 6, IMM 3}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 6, IMM 4}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();

	// {SV 6, IMM 5}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
	
	// {SV 5, IMM 2}
	sim_sw.setReg(16, INT_MAX);
	sim_sw.setDmemory(D_buffer1_length, D_buffer1);
	sim_sw.Sw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sw.errorList.front());
	sim_sw.errorList.pop();
	EXPECT_EQ(0, sim_sw.errorList.size());
	sim_sw.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Sh_Test)
{
	Simulate sim_sh;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 1, IMM 2}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 1, IMM 3}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 1, IMM 4}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 1, IMM 5}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 1, IMM 6}
	sim_sh.setReg(16, INT_MIN);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IMM 1}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IMM 2}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IMM 3}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IMM 4}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0xFFFCCDEF, sim_sh.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IMM 5}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0xFFFC0000, sim_sh.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 2, IM 6}
	sim_sh.setReg(16, -4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 1}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 2}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 3}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_EQ(0xCDEF, sim_sh.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 4}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x4567, sim_sh.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 5}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 3, IMM 6}
	sim_sh.setReg(16, 0);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 4, IMM 1}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 4, IMM 2}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x4CDEF, sim_sh.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 4, IMM 3}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x44567, sim_sh.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 4, IMM 4}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x40001, sim_sh.getDmemoryByAddr(8));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 4, IMM 5}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 4, IMM 6}
	sim_sh.setReg(16, 4);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 5, IMM 1}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 5, IMM 2}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x4000000, sim_sh.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 5, IMM 3}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 5, IMM 4}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 5, IMM 5}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 5, IMM 6}
	sim_sh.setReg(16, 1024);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 6, IMM 1}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 6, IMM 2}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 6, IMM 3}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 6, IMM 4}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();

	// {SV 6, IMM 5}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Misalignment Error\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
	
	// {SV 5, IMM 2}
	sim_sh.setReg(16, INT_MAX);
	sim_sh.setDmemory(D_buffer1_length, D_buffer1);
	sim_sh.Sh(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sh.errorList.front());
	sim_sh.errorList.pop();
	EXPECT_EQ(0, sim_sh.errorList.size());
	sim_sh.initialize();
}

TEST_F(SimulateTest, ItypeInstruction_Sb_Test)
{
	Simulate sim_sb;
	int DonotCare = -1;
	int D_buffer1_length = 3;
	unsigned int D_buffer1[] = {
		0x89ABCDEF, 0x01234567, 0x1
	};

	// {SV 1, IMM 1}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 1, IMM 2}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 1, IMM 3}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 1, IMM 4}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 1, IMM 5}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 1, IMM 6}
	sim_sb.setReg(16, INT_MIN);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IMM 1}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IMM 2}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IMM 3}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IMM 4}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0xFCABCDEF, sim_sb.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IMM 5}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_EQ(0xFC000000, sim_sb.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 2, IM 6}
	sim_sb.setReg(16, -4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 1}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 2}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 3}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_EQ(0xABCDEF, sim_sb.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 4}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x234567, sim_sb.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 5}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 3, IMM 6}
	sim_sb.setReg(16, 0);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 4, IMM 1}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 4, IMM 2}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_EQ(0x4ABCDEF, sim_sb.getDmemoryByAddr(0));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 4, IMM 3}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_EQ(0x4234567, sim_sb.getDmemoryByAddr(4));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 4, IMM 4}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_EQ(0x4000001, sim_sb.getDmemoryByAddr(8));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 4, IMM 5}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 4, IMM 6}
	sim_sb.setReg(16, 4);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 5, IMM 1}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 5, IMM 2}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_EQ(0, sim_sb.getDmemoryByAddr(1020));
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 5, IMM 3}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 5, IMM 4}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 5, IMM 5}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 5, IMM 6}
	sim_sb.setReg(16, 1024);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 6, IMM 1}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 6, IMM 2}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, -4);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 6, IMM 3}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 0);
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();

	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 6, IMM 4}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 4);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();

	// {SV 6, IMM 5}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, 1024);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
	
	// {SV 6, IMM 6}
	sim_sb.setReg(16, INT_MAX);
	sim_sb.setDmemory(D_buffer1_length, D_buffer1);
	sim_sb.Sb(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_STREQ("In cycle 0: Address Overflow\n", sim_sb.errorList.front());
	sim_sb.errorList.pop();
	EXPECT_EQ(0, sim_sb.errorList.size());
	sim_sb.initialize();
}
	/*
		value of immediate from -32768 to 32767 are valid
		ID of register from 0 to 31 are valid

		IMM min : SHORT_MIN
		IMM min+ : SHORT_MIN+1
		IMM normal : 0
		IMM max- : SHORT_MAX-1
		IMM max : SHORT_MAX+1

		6 SR test case for lui
	*/

TEST_F(SimulateTest, ItypeInstruction_Lui_Test)
{
	Simulate sim_lui;
	int DonotCare = -1;

	// {IMM min}
	sim_lui.Lui(DonotCare, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_lui.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_lui.errorList.front());
	sim_lui.errorList.pop();
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();

	// {IMM min}
	sim_lui.Lui(DonotCare, 16, SHORT_MIN);
	EXPECT_EQ(INT_MIN, sim_lui.Reg[16]);
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();

	// {IMM min+}
	sim_lui.Lui(DonotCare, 16, SHORT_MIN+1);
	EXPECT_EQ(0x80010000, sim_lui.Reg[16]);
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();

	// {IMM normal}
	sim_lui.Lui(DonotCare, 16, 0);
	EXPECT_EQ(0, sim_lui.Reg[16]);
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();

	// {IMM max-}
	sim_lui.Lui(DonotCare, 16, SHORT_MAX-1);
	EXPECT_EQ(0x7FFE0000, sim_lui.Reg[16]);
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();

	// {IMM max}
	sim_lui.Lui(DonotCare, 16, SHORT_MAX);
	EXPECT_EQ(0x7FFF0000, sim_lui.Reg[16]);
	EXPECT_EQ(0, sim_lui.errorList.size());
	sim_lui.initialize();
}
	/*
		value of register from 0x80000000 ato 0x7FFFFFF are valid
		value of immediate from -256 to 254 are valid
		ID of register from 0 to 31 are valid
		value of PC which is from 0 to 1020 and is divisible by 4 are valid

		IMM min : -256
		IMM min+ : -255
		IMM normal : 0
		IMM max- : 253
		IMM max : 254

		PC min : 0
		PC min+ : 4
		PC normal : 512
		PC max- : 1016
		PC max : 1020

		25 SR test case for beq, bne
	*/

TEST_F(SimulateTest, ItypeInstruction_Beq_Test)
{
	Simulate sim_beq;
	int DonotCare = -1;
	
	// {IMM min, PC min}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(0);
	sim_beq.Beq(DonotCare, 16, 16, -256);
	ASSERT_GT(0, sim_beq.PC); // invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM min, PC min+}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(4);
	sim_beq.Beq(DonotCare, 16, 16, -256);
	ASSERT_GT(0, sim_beq.PC);	// invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min, PC normal}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(512);
	sim_beq.Beq(DonotCare, 16, 16, -256);
	ASSERT_GT(0, sim_beq.PC);	// invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min, PC max-}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1016);
	sim_beq.Beq(DonotCare, 16, 16, -256);
	ASSERT_GT(0, sim_beq.PC);	// invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min, PC max}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1020);
	sim_beq.Beq(DonotCare, 16, 16, -256);
	EXPECT_EQ(0, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM min+, PC min}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(0);
	sim_beq.Beq(DonotCare, 16, 16, -255);
	ASSERT_GT(0, sim_beq.PC); // invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM min+, PC min+}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(4);
	sim_beq.Beq(DonotCare, 16, 16, -255);
	ASSERT_GT(0, sim_beq.PC);	// invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min+, PC normal}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(512);
	sim_beq.Beq(DonotCare, 16, 16, -255);
	ASSERT_GT(0, sim_beq.PC);	// invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min+, PC max-}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1016);
	sim_beq.Beq(DonotCare, 16, 16, -255);
	EXPECT_EQ(0, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM min+, PC max}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1020);
	sim_beq.Beq(DonotCare, 16, 16, -255);
	EXPECT_EQ(4, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM normal, PC min}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(0);
	sim_beq.Beq(DonotCare, 16, 16, 0);
	EXPECT_EQ(4, sim_beq.PC); 
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM normal, PC min+}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(4);
	sim_beq.Beq(DonotCare, 16, 16, 0);
	EXPECT_EQ(8, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM normal, PC normal}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(512);
	sim_beq.Beq(DonotCare, 16, 16, 0);
	EXPECT_EQ(516, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM normal, PC max-}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1016);
	sim_beq.Beq(DonotCare, 16, 16, 0);
	EXPECT_EQ(1020, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM normal, PC max}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1020);
	sim_beq.Beq(DonotCare, 16, 16, 0);
	ASSERT_LE(1024, sim_beq.PC); // invalid	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM max-, PC min}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(0);
	sim_beq.Beq(DonotCare, 16, 16, 253);
	EXPECT_EQ(1016, sim_beq.PC); 
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM max-, PC min+}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(4);
	sim_beq.Beq(DonotCare, 16, 16, 253);
	EXPECT_EQ(1020, sim_beq.PC);	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM max-, PC normal}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(512);
	sim_beq.Beq(DonotCare, 16, 16, 253);
	ASSERT_LE(1024, sim_beq.PC); //	invlid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM max-, PC max-}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1016);
	sim_beq.Beq(DonotCare, 16, 16, 253);
	ASSERT_LE(1024, sim_beq.PC); //	invlid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM max-, PC max}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1020);
	sim_beq.Beq(DonotCare, 16, 16, 253);
	ASSERT_LE(1024, sim_beq.PC); // invalid	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM max, PC min}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(0);
	sim_beq.Beq(DonotCare, 16, 16, 254);
	EXPECT_EQ(1020, sim_beq.PC); 
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
	
	// {IMM max, PC min+}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(4);
	sim_beq.Beq(DonotCare, 16, 16, 254);
	EXPECT_LE(1024, sim_beq.PC); // invalid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM max, PC normal}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(512);
	sim_beq.Beq(DonotCare, 16, 16, 254);
	ASSERT_LE(1024, sim_beq.PC); //	invlid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM max, PC max-}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1016);
	sim_beq.Beq(DonotCare, 16, 16, 254);
	ASSERT_LE(1024, sim_beq.PC); //	invlid
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();

	// {IMM normal, PC max}
	sim_beq.setReg(16, INT_MIN);
	sim_beq.setPC(1020);
	sim_beq.Beq(DonotCare, 16, 16, 254);
	ASSERT_LE(1024, sim_beq.PC); // invalid	
	EXPECT_EQ(0, sim_beq.errorList.size());
	sim_beq.initialize();
}
	/*
		value of immediate from 0 to 255 are valid
		value of PC which is from 0 to 1020 and is divisible by 4 are valid

		IMM min : 0
		IMM min+ : 1
		IMM normal : 128
		IMM max- : 254
		IMM max : 255

		PC min : 0
		PC min+ : 4
		PC normal : 512
		PC max- : 1016
		PC max : 1020

		25 SR test case for j, jal
	*/

TEST_F(SimulateTest, JtypeInstruction_J_Test)
{
	Simulate sim_j;

	// {IMM min, PC min}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(0);
	sim_j.J(0);
	EXPECT_EQ(0, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM min, PC min+}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(4);
	sim_j.J(0);
	EXPECT_EQ(0, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min, PC normal}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(512);
	sim_j.J(0);
	EXPECT_EQ(0, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min, PC max-}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1016);
	sim_j.J(0);
	EXPECT_EQ(0, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min, PC max}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1020);
	sim_j.J(0);
	EXPECT_EQ(0, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM min+, PC min}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(0);
	sim_j.J(1);
	EXPECT_EQ(4, sim_j.PC);
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM min+, PC min+}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(4);
	sim_j.J(1);
	EXPECT_EQ(4, sim_j.PC);
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min+, PC normal}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(512);
	sim_j.J(1);
	EXPECT_EQ(4, sim_j.PC);
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min+, PC max-}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1016);
	sim_j.J(1);
	EXPECT_EQ(4, sim_j.PC);
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM min+, PC max}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1020);
	sim_j.J(1);
	EXPECT_EQ(4, sim_j.PC);
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM normal, PC min}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(0);
	sim_j.J(128);
	EXPECT_EQ(512, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM normal, PC min+}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(4);
	sim_j.J(128);
	EXPECT_EQ(512, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM normal, PC normal}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(512);
	sim_j.J(128);
	EXPECT_EQ(512, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM normal, PC max-}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1016);
	sim_j.J(128);
	EXPECT_EQ(512, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM normal, PC max}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1020);
	sim_j.J(128);
	EXPECT_EQ(512, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM max-, PC min}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(0);
	sim_j.J(254);
	EXPECT_EQ(1016, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM max-, PC min+}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(4);
	sim_j.J(254);
	EXPECT_EQ(1016, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM max-, PC normal}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(512);
	sim_j.J(254);
	EXPECT_EQ(1016, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM max-, PC max-}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1016);
	sim_j.J(254);
	EXPECT_EQ(1016, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM max-, PC max}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1020);
	sim_j.J(254);
	EXPECT_EQ(1016, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM max, PC min}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(0);
	sim_j.J(255);
	EXPECT_EQ(1020, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
	
	// {IMM max, PC min+}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(4);
	sim_j.J(255);
	EXPECT_EQ(1020, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM max, PC normal}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(512);
	sim_j.J(255);
	EXPECT_EQ(1020, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM max, PC max-}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1016);
	sim_j.J(255);
	EXPECT_EQ(1020, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();

	// {IMM normal, PC max}
	sim_j.setReg(16, INT_MIN);
	sim_j.setPC(1020);
	sim_j.J(255);
	EXPECT_EQ(1020, sim_j.PC); 
	EXPECT_EQ(0, sim_j.errorList.size());
	sim_j.initialize();
}

TEST_F(SimulateTest, JaltypeInstruction_Jal_Test)
{
	Simulate sim_jal;

	// {IMM min, PC min}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(0);
	sim_jal.Jal(0);
	EXPECT_EQ(0, sim_jal.PC);
	EXPECT_EQ(4, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM min, PC min+}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(4);
	sim_jal.Jal(0);
	EXPECT_EQ(0, sim_jal.PC); 
	EXPECT_EQ(8, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min, PC normal}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(512);
	sim_jal.Jal(0);
	EXPECT_EQ(0, sim_jal.PC); 
	EXPECT_EQ(516, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min, PC max-}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1016);
	sim_jal.Jal(0);
	EXPECT_EQ(0, sim_jal.PC); 
	EXPECT_EQ(1020, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min, PC max}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1020);
	sim_jal.Jal(0);
	EXPECT_EQ(0, sim_jal.PC); 
	ASSERT_LE(1024, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM min+, PC min}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(0);
	sim_jal.Jal(1);
	EXPECT_EQ(4, sim_jal.PC);
	EXPECT_EQ(4, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM min+, PC min+}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(4);
	sim_jal.Jal(1);
	EXPECT_EQ(4, sim_jal.PC);
	EXPECT_EQ(8, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min+, PC normal}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(512);
	sim_jal.Jal(1);
	EXPECT_EQ(4, sim_jal.PC);
	EXPECT_EQ(516, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min+, PC max-}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1016);
	sim_jal.Jal(1);
	EXPECT_EQ(4, sim_jal.PC);
	EXPECT_EQ(1020, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM min+, PC max}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1020);
	sim_jal.Jal(1);
	EXPECT_EQ(4, sim_jal.PC);
	ASSERT_LE(1024, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM normal, PC min}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(0);
	sim_jal.Jal(128);
	EXPECT_EQ(512, sim_jal.PC); 
	EXPECT_EQ(4, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM normal, PC min+}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(4);
	sim_jal.Jal(128);
	EXPECT_EQ(512, sim_jal.PC); 
	EXPECT_EQ(8, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM normal, PC normal}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(512);
	sim_jal.Jal(128);
	EXPECT_EQ(512, sim_jal.PC); 
	EXPECT_EQ(516, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM normal, PC max-}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1016);
	sim_jal.Jal(128);
	EXPECT_EQ(512, sim_jal.PC); 
	EXPECT_EQ(1020, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM normal, PC max}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1020);
	sim_jal.Jal(128);
	EXPECT_EQ(512, sim_jal.PC); 
	ASSERT_LE(1024, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM max-, PC min}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(0);
	sim_jal.Jal(254);
	EXPECT_EQ(1016, sim_jal.PC); 
	EXPECT_EQ(4, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM max-, PC min+}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(4);
	sim_jal.Jal(254);
	EXPECT_EQ(1016, sim_jal.PC); 
	EXPECT_EQ(8, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM max-, PC normal}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(512);
	sim_jal.Jal(254);
	EXPECT_EQ(1016, sim_jal.PC); 
	EXPECT_EQ(516, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM max-, PC max-}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1016);
	sim_jal.Jal(254);
	EXPECT_EQ(1016, sim_jal.PC); 
	EXPECT_EQ(1020, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM max-, PC max}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1020);
	sim_jal.Jal(254);
	EXPECT_EQ(1016, sim_jal.PC); 
	ASSERT_LE(1024, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM max, PC min}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(0);
	sim_jal.Jal(255);
	EXPECT_EQ(1020, sim_jal.PC); 
	EXPECT_EQ(4, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
	
	// {IMM max, PC min+}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(4);
	sim_jal.Jal(255);
	EXPECT_EQ(1020, sim_jal.PC); 
	EXPECT_EQ(8, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM max, PC normal}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(512);
	sim_jal.Jal(255);
	EXPECT_EQ(1020, sim_jal.PC); 
	EXPECT_EQ(516, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM max, PC max-}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1016);
	sim_jal.Jal(255);
	EXPECT_EQ(1020, sim_jal.PC); 
	EXPECT_EQ(1020, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();

	// {IMM normal, PC max}
	sim_jal.setReg(16, INT_MIN);
	sim_jal.setPC(1020);
	sim_jal.Jal(255);
	EXPECT_EQ(1020, sim_jal.PC); 
	ASSERT_LE(1024, sim_jal.Reg[31]);
	EXPECT_EQ(0, sim_jal.errorList.size());
	sim_jal.initialize();
}
