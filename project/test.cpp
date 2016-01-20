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
	/*	
		virtual void SetUp(){
			unsigned int I_buffer[] = {
				0x30080000,
				0xFFFFFFFF,
				0x00000000
			};
			unsigned int D_buffer[] = {
				0x12345678,
				0x9ABCDEF0
			};
			sim.setValue(0x0, 0x3, I_buffer, 0x400, 0x2, D_buffer);
		}
	*/	
		// virtual void TearDown() {}

		Simulate sim;

};

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
	NT_MIN*/

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

//My Part

TEST_F(SimulateTest, RtypeInstruction_And_Test){

	Simulate sim_and;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_and.setReg(16, INT_MIN);
	sim_and.And(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_and.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_and.errorList.front());
	sim_and.errorList.pop();
	EXPECT_EQ(0, sim_and.errorList.size());
	sim_and.initialize();

	// {SV min, TV min}
	sim_and.setReg(16, INT_MIN);
	sim_and.And(DonotCare, 16, 16, 16);
	EXPECT_EQ(INT_MIN, sim_and.Reg[1]);
	EXPECT_EQ(0, sim_and.errorList.size());
	sim_and.initialize();

















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
/*
	// {SV max, IMM max-}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0x80007FFD, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
	
	// {SV max, IMM max}
	sim_lw.setReg(16, INT_MAX);
	sim_lw.Lw(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0x80007FFE, sim_lw.Reg[16]);
	EXPECT_STREQ("In cycle 0: Number Overflow\n", sim_lw.errorList.front());
	sim_lw.errorList.pop();
	EXPECT_EQ(0, sim_lw.errorList.size());
	sim_lw.initialize();
*/
}
