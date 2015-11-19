#include "gtest/gtest.h"
#include "single_cycle.h"
#include <climits>
#include <queue>
#include <iostream>
using namespace std;

#define SHORT_MIN (int)((short)0x8000)
#define SHORT_MAX (int)((short)0x7FFF)


class SimulateTest2 : public ::testing::Test {
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


TEST_F(SimulateTest2, RtypeInstruction_And_Test){

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
	EXPECT_EQ(INT_MIN, sim_and.Reg[16]);
	EXPECT_EQ(0, sim_and.errorList.size());
	sim_and.initialize();

        // {SV min, TV min+}
        sim_and.setReg(16, INT_MIN);
        sim_and.setReg(31, INT_MIN+1);
        sim_and.And(DonotCare, 16, 31, 16); 
        EXPECT_EQ(INT_MIN, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min, TV normal}
        sim_and.setReg(16, INT_MIN);
        sim_and.And(DonotCare, 16, 0, 16); 
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min, TV max-}
        sim_and.setReg(16, INT_MIN);
        sim_and.setReg(31, INT_MAX-1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min, TV max}
        sim_and.setReg(16, INT_MIN);
        sim_and.setReg(31, INT_MAX);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min+, TV min}
        sim_and.setReg(16, INT_MIN+1);
        sim_and.setReg(31, INT_MIN);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MIN, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();


        // {SV min+, TV min+}
        sim_and.setReg(16, INT_MIN+1);
        sim_and.setReg(31, INT_MIN+1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MIN+1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();


        // {SV min+1, TV normal}
        sim_and.setReg(16, INT_MIN+1);
        sim_and.And(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min+1, TV max-}
        sim_and.setReg(16, INT_MIN+1);
        sim_and.setReg(31, INT_MAX-1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV min+1, TV max}
        sim_and.setReg(16, INT_MIN+1);
        sim_and.setReg(31, INT_MAX);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV normal, TV min}
        sim_and.setReg(16, 0);
        sim_and.setReg(31, INT_MIN);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV normal, TV min+}
        sim_and.setReg(16, 0);
        sim_and.setReg(31, INT_MIN+1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV normal, TV normal}
        sim_and.setReg(16, 0);
        sim_and.And(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV normal, TV max-}
        sim_and.setReg(16, 0);
        sim_and.setReg(31, INT_MAX-1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV normal, TV max}
        sim_and.setReg(16, 0);
        sim_and.setReg(31, INT_MAX);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();


        // {SV max-, TV min}
        sim_and.setReg(16, INT_MAX-1);
        sim_and.setReg(31, INT_MIN);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max-, TV min+}
        sim_and.setReg(16, INT_MAX-1);
        sim_and.setReg(31, INT_MIN+1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();


        // {SV max-1, TV normal}
        sim_and.setReg(16, INT_MAX-1);
        sim_and.And(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max-, TV max-}
        sim_and.setReg(16, INT_MAX-1);
        sim_and.setReg(31, INT_MAX-1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX-1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max-, TV max}
        sim_and.setReg(16, INT_MAX-1);
        sim_and.setReg(31, INT_MAX);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX-1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();


        // {SV max, TV min}
        sim_and.setReg(16, INT_MAX);
        sim_and.setReg(31, INT_MIN);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max, TV min+}
        sim_and.setReg(16, INT_MAX);
        sim_and.setReg(31, INT_MIN+1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max, TV normal}
        sim_and.setReg(16, INT_MAX);
        sim_and.And(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max, TV max-}
        sim_and.setReg(16, INT_MAX);
        sim_and.setReg(31, INT_MAX-1);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX-1, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();

        // {SV max, TV max}
        sim_and.setReg(16, INT_MAX);
        sim_and.setReg(31, INT_MAX);
        sim_and.And(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX, sim_and.Reg[16]);
        EXPECT_EQ(0, sim_and.errorList.size());
        sim_and.initialize();



}


TEST_F(SimulateTest2, RtypeInstruction_Or_Test){

	Simulate sim_or;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_or.setReg(16, INT_MIN);
	sim_or.Or(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_or.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_or.errorList.front());
	sim_or.errorList.pop();
	EXPECT_EQ(0, sim_or.errorList.size());
	sim_or.initialize();

	// {SV min, TV min}
	sim_or.setReg(16, INT_MIN);
	sim_or.Or(DonotCare, 16, 16, 16);
	EXPECT_EQ(INT_MIN, sim_or.Reg[16]);
	EXPECT_EQ(0, sim_or.errorList.size());
	sim_or.initialize();

        // {SV min, TV min+}
        sim_or.setReg(16, INT_MIN);
        sim_or.setReg(31, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 31, 16); 
        EXPECT_EQ(INT_MIN+1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min, TV normal}
        sim_or.setReg(16, INT_MIN);
        sim_or.Or(DonotCare, 16, 0, 16); 
        EXPECT_EQ(INT_MIN, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min, TV max-}
        sim_or.setReg(16, INT_MIN);
        sim_or.setReg(31, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min, TV max}
        sim_or.setReg(16, INT_MIN);
        sim_or.setReg(31, INT_MAX);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min+, TV min}
        sim_or.setReg(16, INT_MIN+1);
        sim_or.setReg(31, INT_MIN);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();


        // {SV min+, TV min+}
        sim_or.setReg(16, INT_MIN+1);
        sim_or.setReg(31, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MIN+1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();


        // {SV min+1, TV normal}
        sim_or.setReg(16, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 0, 16);
        EXPECT_EQ(-2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min+1, TV max-}
        sim_or.setReg(16, INT_MIN+1);
        sim_or.setReg(31, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV min+1, TV max}
        sim_or.setReg(16, INT_MIN+1);
        sim_or.setReg(31, INT_MAX);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV normal, TV min}
        sim_or.setReg(16, 0);
        sim_or.setReg(31, INT_MIN);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV normal, TV min+}
        sim_or.setReg(16, 0);
        sim_or.setReg(31, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV normal, TV normal}
        sim_or.setReg(16, 0);
        sim_or.Or(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV normal, TV max-}
        sim_or.setReg(16, 0);
        sim_or.setReg(31, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV normal, TV max}
        sim_or.setReg(16, 0);
        sim_or.setReg(31, INT_MAX);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();


        // {SV max-, TV min}
        sim_or.setReg(16, INT_MAX-1);
        sim_or.setReg(31, INT_MIN);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max-, TV min+}
        sim_or.setReg(16, INT_MAX-1);
        sim_or.setReg(31, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();


        // {SV max-1, TV normal}
        sim_or.setReg(16, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 0, 16);
        EXPECT_EQ(2147483646, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max-, TV max-}
        sim_or.setReg(16, INT_MAX-1);
        sim_or.setReg(31, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max-, TV max}
        sim_or.setReg(16, INT_MAX-1);
        sim_or.setReg(31, INT_MAX);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();


        // {SV max, TV min}
        sim_or.setReg(16, INT_MAX);
        sim_or.setReg(31, INT_MIN);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max, TV min+}
        sim_or.setReg(16, INT_MAX);
        sim_or.setReg(31, INT_MIN+1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max, TV normal}
        sim_or.setReg(16, INT_MAX);
        sim_or.Or(DonotCare, 16, 0, 16);
        EXPECT_EQ(2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max, TV max-}
        sim_or.setReg(16, INT_MAX);
        sim_or.setReg(31, INT_MAX-1);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();

        // {SV max, TV max}
        sim_or.setReg(16, INT_MAX);
        sim_or.setReg(31, INT_MAX);
        sim_or.Or(DonotCare, 16, 31, 16);
        EXPECT_EQ(INT_MAX, sim_or.Reg[16]);
        EXPECT_EQ(0, sim_or.errorList.size());
        sim_or.initialize();



}




TEST_F(SimulateTest2, RtypeInstruction_Xor_Test){

	Simulate sim_xor;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_xor.setReg(16, INT_MIN);
	sim_xor.Xor(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_xor.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_xor.errorList.front());
	sim_xor.errorList.pop();
	EXPECT_EQ(0, sim_xor.errorList.size());
	sim_xor.initialize();

	// {SV min, TV min}
	sim_xor.setReg(16, INT_MIN);
	sim_xor.Xor(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_xor.Reg[16]);
	EXPECT_EQ(0, sim_xor.errorList.size());
	sim_xor.initialize();

        // {SV min, TV min+}
        sim_xor.setReg(16, INT_MIN);
        sim_xor.setReg(31, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 31, 16); 
        EXPECT_EQ(1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min, TV normal}
        sim_xor.setReg(16, INT_MIN);
        sim_xor.Xor(DonotCare, 16, 0, 16); 
        EXPECT_EQ(-2147483648, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min, TV max-}
        sim_xor.setReg(16, INT_MIN);
        sim_xor.setReg(31, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min, TV max}
        sim_xor.setReg(16, INT_MIN);
        sim_xor.setReg(31, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min+, TV min}
        sim_xor.setReg(16, INT_MIN+1);
        sim_xor.setReg(31, INT_MIN);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();


        // {SV min+, TV min+}
        sim_xor.setReg(16, INT_MIN+1);
        sim_xor.setReg(31, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();


        // {SV min+1, TV normal}
        sim_xor.setReg(16, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 0, 16);
        EXPECT_EQ(-2147483647, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min+1, TV max-}
        sim_xor.setReg(16, INT_MIN+1);
        sim_xor.setReg(31, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV min+1, TV max}
        sim_xor.setReg(16, INT_MIN+1);
        sim_xor.setReg(31, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV normal, TV min}
        sim_xor.setReg(16, 0);
        sim_xor.setReg(31, INT_MIN);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV normal, TV min+}
        sim_xor.setReg(16, 0);
        sim_xor.setReg(31, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV normal, TV normal}
        sim_xor.setReg(16, 0);
        sim_xor.Xor(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV normal, TV max-}
        sim_xor.setReg(16, 0);
        sim_xor.setReg(31, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV normal, TV max}
        sim_xor.setReg(16, 0);
        sim_xor.setReg(31, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();


        // {SV max-, TV min}
        sim_xor.setReg(16, INT_MAX-1);
        sim_xor.setReg(31, INT_MIN);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max-, TV min+}
        sim_xor.setReg(16, INT_MAX-1);
        sim_xor.setReg(31, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();


        // {SV max-1, TV normal}
        sim_xor.setReg(16, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 0, 16);
        EXPECT_EQ(2147483646, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max-, TV max-}
        sim_xor.setReg(16, INT_MAX-1);
        sim_xor.setReg(31, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ( 0, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max-, TV max}
        sim_xor.setReg(16, INT_MAX-1);
        sim_xor.setReg(31, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();


        // {SV max, TV min}
        sim_xor.setReg(16, INT_MAX);
        sim_xor.setReg(31, INT_MIN);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ( -1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max, TV min+}
        sim_xor.setReg(16, INT_MAX);
        sim_xor.setReg(31, INT_MIN+1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max, TV normal}
        sim_xor.setReg(16, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 0, 16);
        EXPECT_EQ(2147483647, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max, TV max-}
        sim_xor.setReg(16, INT_MAX);
        sim_xor.setReg(31, INT_MAX-1);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();

        // {SV max, TV max}
        sim_xor.setReg(16, INT_MAX);
        sim_xor.setReg(31, INT_MAX);
        sim_xor.Xor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_xor.Reg[16]);
        EXPECT_EQ(0, sim_xor.errorList.size());
        sim_xor.initialize();



}


TEST_F(SimulateTest2, RtypeInstruction_Nor_Test){

	Simulate sim_nor;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_nor.setReg(16, INT_MIN);
	sim_nor.Nor(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_nor.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_nor.errorList.front());
	sim_nor.errorList.pop();
	EXPECT_EQ(0, sim_nor.errorList.size());
	sim_nor.initialize();

	// {SV min, TV min}
	sim_nor.setReg(16, INT_MIN);
	sim_nor.Nor(DonotCare, 16, 16, 16);
	EXPECT_EQ(2147483647, sim_nor.Reg[16]);
	EXPECT_EQ(0, sim_nor.errorList.size());
	sim_nor.initialize();

        // {SV min, TV min+}
        sim_nor.setReg(16, INT_MIN);
        sim_nor.setReg(31, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 31, 16); 
        EXPECT_EQ(2147483646, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min, TV normal}
        sim_nor.setReg(16, INT_MIN);
        sim_nor.Nor(DonotCare, 16, 0, 16); 
        EXPECT_EQ(2147483647, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min, TV max-}
        sim_nor.setReg(16, INT_MIN);
        sim_nor.setReg(31, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min, TV max}
        sim_nor.setReg(16, INT_MIN);
        sim_nor.setReg(31, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min+, TV min}
        sim_nor.setReg(16, INT_MIN+1);
        sim_nor.setReg(31, INT_MIN);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();


        // {SV min+, TV min+}
        sim_nor.setReg(16, INT_MIN+1);
        sim_nor.setReg(31, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();


        // {SV min+1, TV normal}
        sim_nor.setReg(16, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 0, 16);
        EXPECT_EQ(2147483646, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min+1, TV max-}
        sim_nor.setReg(16, INT_MIN+1);
        sim_nor.setReg(31, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV min+1, TV max}
        sim_nor.setReg(16, INT_MIN+1);
        sim_nor.setReg(31, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV normal, TV min}
        sim_nor.setReg(16, 0);
        sim_nor.setReg(31, INT_MIN);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV normal, TV min+}
        sim_nor.setReg(16, 0);
        sim_nor.setReg(31, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV normal, TV normal}
        sim_nor.setReg(16, 0);
        sim_nor.Nor(DonotCare, 16, 0, 16);
        EXPECT_EQ(-1, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV normal, TV max-}
        sim_nor.setReg(16, 0);
        sim_nor.setReg(31, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV normal, TV max}
        sim_nor.setReg(16, 0);
        sim_nor.setReg(31, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();


        // {SV max-, TV min}
        sim_nor.setReg(16, INT_MAX-1);
        sim_nor.setReg(31, INT_MIN);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max-, TV min+}
        sim_nor.setReg(16, INT_MAX-1);
        sim_nor.setReg(31, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();


        // {SV max-1, TV normal}
        sim_nor.setReg(16, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 0, 16);
        EXPECT_EQ(-2147483647, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max-, TV max-}
        sim_nor.setReg(16, INT_MAX-1);
        sim_nor.setReg(31, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max-, TV max}
        sim_nor.setReg(16, INT_MAX-1);
        sim_nor.setReg(31, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();


        // {SV max, TV min}
        sim_nor.setReg(16, INT_MAX);
        sim_nor.setReg(31, INT_MIN);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max, TV min+}
        sim_nor.setReg(16, INT_MAX);
        sim_nor.setReg(31, INT_MIN+1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max, TV normal}
        sim_nor.setReg(16, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 0, 16);
        EXPECT_EQ(-2147483648, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max, TV max-}
        sim_nor.setReg(16, INT_MAX);
        sim_nor.setReg(31, INT_MAX-1);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();

        // {SV max, TV max}
        sim_nor.setReg(16, INT_MAX);
        sim_nor.setReg(31, INT_MAX);
        sim_nor.Nor(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_nor.Reg[16]);
        EXPECT_EQ(0, sim_nor.errorList.size());
        sim_nor.initialize();



}




TEST_F(SimulateTest2, RtypeInstruction_Nand_Test){

	Simulate sim_nand;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_nand.setReg(16, INT_MIN);
	sim_nand.Nand(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_nand.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_nand.errorList.front());
	sim_nand.errorList.pop();
	EXPECT_EQ(0, sim_nand.errorList.size());
	sim_nand.initialize();

	// {SV min, TV min}
	sim_nand.setReg(16, INT_MIN);
	sim_nand.Nand(DonotCare, 16, 16, 16);
	EXPECT_EQ(2147483647, sim_nand.Reg[16]);
	EXPECT_EQ(0, sim_nand.errorList.size());
	sim_nand.initialize();

        // {SV min, TV min+}
        sim_nand.setReg(16, INT_MIN);
        sim_nand.setReg(31, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 31, 16); 
        EXPECT_EQ(2147483647, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min, TV normal}
        sim_nand.setReg(16, INT_MIN);
        sim_nand.Nand(DonotCare, 16, 0, 16); 
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min, TV max-}
        sim_nand.setReg(16, INT_MIN);
        sim_nand.setReg(31, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min, TV max}
        sim_nand.setReg(16, INT_MIN);
        sim_nand.setReg(31, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min+, TV min}
        sim_nand.setReg(16, INT_MIN+1);
        sim_nand.setReg(31, INT_MIN);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483647, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();


        // {SV min+, TV min+}
        sim_nand.setReg(16, INT_MIN+1);
        sim_nand.setReg(31, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(2147483646, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();


        // {SV min+1, TV normal}
        sim_nand.setReg(16, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 0, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min+1, TV max-}
        sim_nand.setReg(16, INT_MIN+1);
        sim_nand.setReg(31, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV min+1, TV max}
        sim_nand.setReg(16, INT_MIN+1);
        sim_nand.setReg(31, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV normal, TV min}
        sim_nand.setReg(16, 0);
        sim_nand.setReg(31, INT_MIN);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV normal, TV min+}
        sim_nand.setReg(16, 0);
        sim_nand.setReg(31, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV normal, TV normal}
        sim_nand.setReg(16, 0);
        sim_nand.Nand(DonotCare, 16, 0, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV normal, TV max-}
        sim_nand.setReg(16, 0);
        sim_nand.setReg(31, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV normal, TV max}
        sim_nand.setReg(16, 0);
        sim_nand.setReg(31, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();


        // {SV max-, TV min}
        sim_nand.setReg(16, INT_MAX-1);
        sim_nand.setReg(31, INT_MIN);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max-, TV min+}
        sim_nand.setReg(16, INT_MAX-1);
        sim_nand.setReg(31, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();


        // {SV max-1, TV normal}
        sim_nand.setReg(16, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 0, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max-, TV max-}
        sim_nand.setReg(16, INT_MAX-1);
        sim_nand.setReg(31, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max-, TV max}
        sim_nand.setReg(16, INT_MAX-1);
        sim_nand.setReg(31, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();


        // {SV max, TV min}
        sim_nand.setReg(16, INT_MAX);
        sim_nand.setReg(31, INT_MIN);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max, TV min+}
        sim_nand.setReg(16, INT_MAX);
        sim_nand.setReg(31, INT_MIN+1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max, TV normal}
        sim_nand.setReg(16, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 0, 16);
        EXPECT_EQ(-1, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max, TV max-}
        sim_nand.setReg(16, INT_MAX);
        sim_nand.setReg(31, INT_MAX-1);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483647, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();

        // {SV max, TV max}
        sim_nand.setReg(16, INT_MAX);
        sim_nand.setReg(31, INT_MAX);
        sim_nand.Nand(DonotCare, 16, 31, 16);
        EXPECT_EQ(-2147483648, sim_nand.Reg[16]);
        EXPECT_EQ(0, sim_nand.errorList.size());
        sim_nand.initialize();



}



TEST_F(SimulateTest2, RtypeInstruction_Slt_Test){

	Simulate sim_slt;
	int DonotCare = -1;

	// {SV min, TV min}
	sim_slt.setReg(16, INT_MIN);
	sim_slt.Slt(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_slt.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_slt.errorList.front());
	sim_slt.errorList.pop();
	EXPECT_EQ(0, sim_slt.errorList.size());
	sim_slt.initialize();

	// {SV min, TV min}
	sim_slt.setReg(16, INT_MIN);
	sim_slt.Slt(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_slt.Reg[16]);
	EXPECT_EQ(0, sim_slt.errorList.size());
	sim_slt.initialize();

        // {SV min, TV min+}
        sim_slt.setReg(16, INT_MIN);
        sim_slt.setReg(31, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 31, 16); 
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min, TV normal}
        sim_slt.setReg(16, INT_MIN);
        sim_slt.Slt(DonotCare, 16, 0, 16); 
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min, TV max-}
        sim_slt.setReg(16, INT_MIN);
        sim_slt.setReg(31, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min, TV max}
        sim_slt.setReg(16, INT_MIN);
        sim_slt.setReg(31, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min+, TV min}
        sim_slt.setReg(16, INT_MIN+1);
        sim_slt.setReg(31, INT_MIN);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();


        // {SV min+, TV min+}
        sim_slt.setReg(16, INT_MIN+1);
        sim_slt.setReg(31, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();


        // {SV min+1, TV normal}
        sim_slt.setReg(16, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 0, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min+1, TV max-}
        sim_slt.setReg(16, INT_MIN+1);
        sim_slt.setReg(31, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV min+1, TV max}
        sim_slt.setReg(16, INT_MIN+1);
        sim_slt.setReg(31, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV normal, TV min}
        sim_slt.setReg(16, 0);
        sim_slt.setReg(31, INT_MIN);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV normal, TV min+}
        sim_slt.setReg(16, 0);
        sim_slt.setReg(31, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV normal, TV normal}
        sim_slt.setReg(16, 0);
        sim_slt.Slt(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV normal, TV max-}
        sim_slt.setReg(16, 0);
        sim_slt.setReg(31, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV normal, TV max}
        sim_slt.setReg(16, 0);
        sim_slt.setReg(31, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();


        // {SV max-, TV min}
        sim_slt.setReg(16, INT_MAX-1);
        sim_slt.setReg(31, INT_MIN);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max-, TV min+}
        sim_slt.setReg(16, INT_MAX-1);
        sim_slt.setReg(31, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();


        // {SV max-1, TV normal}
        sim_slt.setReg(16, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max-, TV max-}
        sim_slt.setReg(16, INT_MAX-1);
        sim_slt.setReg(31, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max-, TV max}
        sim_slt.setReg(16, INT_MAX-1);
        sim_slt.setReg(31, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(1, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();


        // {SV max, TV min}
        sim_slt.setReg(16, INT_MAX);
        sim_slt.setReg(31, INT_MIN);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max, TV min+}
        sim_slt.setReg(16, INT_MAX);
        sim_slt.setReg(31, INT_MIN+1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max, TV normal}
        sim_slt.setReg(16, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 0, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max, TV max-}
        sim_slt.setReg(16, INT_MAX);
        sim_slt.setReg(31, INT_MAX-1);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();

        // {SV max, TV max}
        sim_slt.setReg(16, INT_MAX);
        sim_slt.setReg(31, INT_MAX);
        sim_slt.Slt(DonotCare, 16, 31, 16);
        EXPECT_EQ(0, sim_slt.Reg[16]);
        EXPECT_EQ(0, sim_slt.errorList.size());
        sim_slt.initialize();



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


TEST_F(SimulateTest2, RtypeInstruction_Srl_Test)
{
	Simulate sim_srl;
	int DonotCare = -1;

	// {TV min, shamt min}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 0, 0);
	EXPECT_EQ(0, sim_srl.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_srl.errorList.front());
	sim_srl.errorList.pop();
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min, shamt min}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min, shamt min+}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741824, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min, shamt normal}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 16, 16);
	EXPECT_EQ(32768, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min, shamt max-}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 16, 30);
	EXPECT_EQ(2, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min, shamt max}
	sim_srl.setReg(16, INT_MIN);
	sim_srl.Srl(DonotCare, 16, 16, 31);
	EXPECT_EQ(1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min+, shamt min}
	sim_srl.setReg(16, INT_MIN+1);
	sim_srl.Srl(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN+1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min+, shamt min+}
	sim_srl.setReg(16, INT_MIN+1);
	sim_srl.Srl(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741824, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min+1, shamt normal}
	sim_srl.setReg(16, INT_MIN+1);
	sim_srl.Srl(DonotCare, 16, 16, 16);
	EXPECT_EQ(32768, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min+1, shamt max-}
	sim_srl.setReg(16, INT_MIN+1);
	sim_srl.Srl(DonotCare, 16, 16, 30);
	EXPECT_EQ(2, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV min+1, shamt max}
	sim_srl.setReg(16, INT_MIN+1);
	sim_srl.Srl(DonotCare, 16, 16, 31);
	EXPECT_EQ(1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV normal, shamt min}
	sim_srl.setReg(16, 0);
	sim_srl.Srl(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV normal, shamt min+}
	sim_srl.setReg(16, 0);
	sim_srl.Srl(DonotCare, 16, 16, 1);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV normal, shamt normal}
	sim_srl.setReg(16, 0);
	sim_srl.Srl(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV normal, shamt max-}
	sim_srl.setReg(16, 0);
	sim_srl.Srl(DonotCare, 16, 16, 30);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV normal, shamt max}
	sim_srl.setReg(16, 0);
	sim_srl.Srl(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max-, shamt min}
	sim_srl.setReg(16, INT_MAX-1);
	sim_srl.Srl(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX-1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max-, shamt min+}
	sim_srl.setReg(16, INT_MAX-1);
	sim_srl.Srl(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741823, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max-1, shamt normal}
	sim_srl.setReg(16, INT_MAX-1);
	sim_srl.Srl(DonotCare, 16, 16, 16);
	EXPECT_EQ(32767, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max-, shamt max-}
	sim_srl.setReg(16, INT_MAX-1);
	sim_srl.Srl(DonotCare, 16, 16, 30);
	EXPECT_EQ(1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();
	
	// {TV max-, shamt max}
	sim_srl.setReg(16, INT_MAX-1);
	sim_srl.Srl(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();
	
	// {TV max, shamt min}
	sim_srl.setReg(16, INT_MAX);
	sim_srl.Srl(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max, shamt min+}
	sim_srl.setReg(16, INT_MAX);
	sim_srl.Srl(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741823, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max, shamt normal}
	sim_srl.setReg(16, INT_MAX);
	sim_srl.Srl(DonotCare, 16, 16, 16);
	EXPECT_EQ(32767, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();

	// {TV max, shamt max-}
	sim_srl.setReg(16, INT_MAX);
	sim_srl.Srl(DonotCare, 16, 16, 30);
	EXPECT_EQ(1, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();
	
	// {TV max, shamt max}
	sim_srl.setReg(16, INT_MAX);
	sim_srl.Srl(DonotCare, 16, 16, 31);
	EXPECT_EQ( 0, sim_srl.Reg[16]);
	EXPECT_EQ(0, sim_srl.errorList.size());
	sim_srl.initialize();
}


TEST_F(SimulateTest2, RtypeInstruction_Sra_Test)
{
	Simulate sim_sra;
	int DonotCare = -1;

	// {TV min, shamt min}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 0, 0);
	EXPECT_EQ(0, sim_sra.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_sra.errorList.front());
	sim_sra.errorList.pop();
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min, shamt min}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min, shamt min+}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 16, 1);
	EXPECT_EQ(-1073741824, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min, shamt normal}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 16, 16);
	EXPECT_EQ(-32768, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min, shamt max-}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 16, 30);
	EXPECT_EQ(-2, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min, shamt max}
	sim_sra.setReg(16, INT_MIN);
	sim_sra.Sra(DonotCare, 16, 16, 31);
	EXPECT_EQ(-1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min+, shamt min}
	sim_sra.setReg(16, INT_MIN+1);
	sim_sra.Sra(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MIN+1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min+, shamt min+}
	sim_sra.setReg(16, INT_MIN+1);
	sim_sra.Sra(DonotCare, 16, 16, 1);
	EXPECT_EQ(-1073741824, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min+1, shamt normal}
	sim_sra.setReg(16, INT_MIN+1);
	sim_sra.Sra(DonotCare, 16, 16, 16);
	EXPECT_EQ(-32768, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min+1, shamt max-}
	sim_sra.setReg(16, INT_MIN+1);
	sim_sra.Sra(DonotCare, 16, 16, 30);
	EXPECT_EQ(-2, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV min+1, shamt max}
	sim_sra.setReg(16, INT_MIN+1);
	sim_sra.Sra(DonotCare, 16, 16, 31);
	EXPECT_EQ( -1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV normal, shamt min}
	sim_sra.setReg(16, 0);
	sim_sra.Sra(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV normal, shamt min+}
	sim_sra.setReg(16, 0);
	sim_sra.Sra(DonotCare, 16, 16, 1);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV normal, shamt normal}
	sim_sra.setReg(16, 0);
	sim_sra.Sra(DonotCare, 16, 16, 16);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV normal, shamt max-}
	sim_sra.setReg(16, 0);
	sim_sra.Sra(DonotCare, 16, 16, 30);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV normal, shamt max}
	sim_sra.setReg(16, 0);
	sim_sra.Sra(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max-, shamt min}
	sim_sra.setReg(16, INT_MAX-1);
	sim_sra.Sra(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX-1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max-, shamt min+}
	sim_sra.setReg(16, INT_MAX-1);
	sim_sra.Sra(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741823, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max-1, shamt normal}
	sim_sra.setReg(16, INT_MAX-1);
	sim_sra.Sra(DonotCare, 16, 16, 16);
	EXPECT_EQ(32767, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max-, shamt max-}
	sim_sra.setReg(16, INT_MAX-1);
	sim_sra.Sra(DonotCare, 16, 16, 30);
	EXPECT_EQ(1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();
	
	// {TV max-, shamt max}
	sim_sra.setReg(16, INT_MAX-1);
	sim_sra.Sra(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();
	
	// {TV max, shamt min}
	sim_sra.setReg(16, INT_MAX);
	sim_sra.Sra(DonotCare, 16, 16, 0);
	EXPECT_EQ(INT_MAX, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max, shamt min+}
	sim_sra.setReg(16, INT_MAX);
	sim_sra.Sra(DonotCare, 16, 16, 1);
	EXPECT_EQ(1073741823, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max, shamt normal}
	sim_sra.setReg(16, INT_MAX);
	sim_sra.Sra(DonotCare, 16, 16, 16);
	EXPECT_EQ(32767, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();

	// {TV max, shamt max-}
	sim_sra.setReg(16, INT_MAX);
	sim_sra.Sra(DonotCare, 16, 16, 30);
	EXPECT_EQ(1, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();
	
	// {TV max, shamt max}
	sim_sra.setReg(16, INT_MAX);
	sim_sra.Sra(DonotCare, 16, 16, 31);
	EXPECT_EQ(0, sim_sra.Reg[16]);
	EXPECT_EQ(0, sim_sra.errorList.size());
	sim_sra.initialize();
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



TEST_F(SimulateTest2, ItypeInstruction_Andi_Test)
{
	Simulate sim_andi;
	int DonotCare = -1;

	// {SV min, IMM min}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_andi.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_andi.errorList.front());
	sim_andi.errorList.pop();
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min, IMM min}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min, IMM min+}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min, IMM normal}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min, IMM max-}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min, IMM max}
	sim_andi.setReg(16, INT_MIN);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min+, IMM min}
	sim_andi.setReg(16, INT_MIN+1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min+, IMM min+}
	sim_andi.setReg(16, INT_MIN+1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(1, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min+1, IMM normal}
	sim_andi.setReg(16, INT_MIN+1);
	sim_andi.Andi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min+1, IMM max-}
	sim_andi.setReg(16, INT_MIN+1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV min+1, IMM max}
	sim_andi.setReg(16, INT_MIN+1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV normal, IMM min}
	sim_andi.setReg(16, 0);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV normal, IMM min+}
	sim_andi.setReg(16, 0);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV normal, IMM normal}
	sim_andi.setReg(16, 0);
	sim_andi.Andi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV normal, IMM max-}
	sim_andi.setReg(16, 0);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV normal, IMM max}
	sim_andi.setReg(16, 0);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max-, IMM min}
	sim_andi.setReg(16, INT_MAX-1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(32768, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max-, IMM min+}
	sim_andi.setReg(16, INT_MAX-1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(32768, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max-1, IMM normal}
	sim_andi.setReg(16, INT_MAX-1);
	sim_andi.Andi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max-, IMM max-}
	sim_andi.setReg(16, INT_MAX-1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(32766, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();
	
	// {SV max-, IMM max}
	sim_andi.setReg(16, INT_MAX-1);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(32766, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();
	
	// {SV max, IMM min}
	sim_andi.setReg(16, INT_MAX);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(32768, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max, IMM min+}
	sim_andi.setReg(16, INT_MAX);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(32769, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max, IMM normal}
	sim_andi.setReg(16, INT_MAX);
	sim_andi.Andi(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();

	// {SV max, IMM max-}
	sim_andi.setReg(16, INT_MAX);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(32766, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();
	
	// {SV max, IMM max}
	sim_andi.setReg(16, INT_MAX);
	sim_andi.Andi(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(32767, sim_andi.Reg[16]);
	EXPECT_EQ(0, sim_andi.errorList.size());
	sim_andi.initialize();
}



TEST_F(SimulateTest2, ItypeInstruction_Ori_Test)
{
	Simulate sim_ori;
	int DonotCare = -1;

	// {SV min, IMM min}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_ori.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_ori.errorList.front());
	sim_ori.errorList.pop();
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min, IMM min}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-2147450880, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min, IMM min+}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(-2147450879, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min, IMM normal}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 16, 0);
	EXPECT_EQ(-2147483648, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min, IMM max-}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(-2147450882, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min, IMM max}
	sim_ori.setReg(16, INT_MIN);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-2147450881, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min+, IMM min}
	sim_ori.setReg(16, INT_MIN+1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-2147450879, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min+, IMM min+}
	sim_ori.setReg(16, INT_MIN+1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(-2147450879, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min+1, IMM normal}
	sim_ori.setReg(16, INT_MIN+1);
	sim_ori.Ori(DonotCare, 16, 16, 0);
	EXPECT_EQ(-2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min+1, IMM max-}
	sim_ori.setReg(16, INT_MIN+1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(-2147450881, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV min+1, IMM max}
	sim_ori.setReg(16, INT_MIN+1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-2147450881, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV normal, IMM min}
	sim_ori.setReg(16, 0);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(32768, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV normal, IMM min+}
	sim_ori.setReg(16, 0);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(32769, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV normal, IMM normal}
	sim_ori.setReg(16, 0);
	sim_ori.Ori(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV normal, IMM max-}
	sim_ori.setReg(16, 0);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(32766, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV normal, IMM max}
	sim_ori.setReg(16, 0);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(32767, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max-, IMM min}
	sim_ori.setReg(16, INT_MAX-1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(2147483646, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max-, IMM min+}
	sim_ori.setReg(16, INT_MAX-1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ( 2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max-1, IMM normal}
	sim_ori.setReg(16, INT_MAX-1);
	sim_ori.Ori(DonotCare, 16, 16, 0);
	EXPECT_EQ(2147483646, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max-, IMM max-}
	sim_ori.setReg(16, INT_MAX-1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(2147483646, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();
	
	// {SV max-, IMM max}
	sim_ori.setReg(16, INT_MAX-1);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();
	
	// {SV max, IMM min}
	sim_ori.setReg(16, INT_MAX);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max, IMM min+}
	sim_ori.setReg(16, INT_MAX);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max, IMM normal}
	sim_ori.setReg(16, INT_MAX);
	sim_ori.Ori(DonotCare, 16, 16, 0);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();

	// {SV max, IMM max-}
	sim_ori.setReg(16, INT_MAX);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();
	
	// {SV max, IMM max}
	sim_ori.setReg(16, INT_MAX);
	sim_ori.Ori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(2147483647, sim_ori.Reg[16]);
	EXPECT_EQ(0, sim_ori.errorList.size());
	sim_ori.initialize();
}


TEST_F(SimulateTest2, ItypeInstruction_Nori_Test)
{
	Simulate sim_nori;
	int DonotCare = -1;

	// {SV min, IMM min}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_nori.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_nori.errorList.front());
	sim_nori.errorList.pop();
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min, IMM min}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(2147450879, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min, IMM min+}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(2147450878, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min, IMM normal}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 16, 0);
	EXPECT_EQ(2147483647, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min, IMM max-}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(2147450881, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min, IMM max}
	sim_nori.setReg(16, INT_MIN);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(2147450880, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min+, IMM min}
	sim_nori.setReg(16, INT_MIN+1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(2147450878, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min+, IMM min+}
	sim_nori.setReg(16, INT_MIN+1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(2147450878, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min+1, IMM normal}
	sim_nori.setReg(16, INT_MIN+1);
	sim_nori.Nori(DonotCare, 16, 16, 0);
	EXPECT_EQ(2147483646, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min+1, IMM max-}
	sim_nori.setReg(16, INT_MIN+1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(2147450880, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV min+1, IMM max}
	sim_nori.setReg(16, INT_MIN+1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(2147450880, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV normal, IMM min}
	sim_nori.setReg(16, 0);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-32769, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV normal, IMM min+}
	sim_nori.setReg(16, 0);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(-32770, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV normal, IMM normal}
	sim_nori.setReg(16, 0);
	sim_nori.Nori(DonotCare, 16, 16, 0);
	EXPECT_EQ(-1, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV normal, IMM max-}
	sim_nori.setReg(16, 0);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(-32767, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV normal, IMM max}
	sim_nori.setReg(16, 0);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-32768, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max-, IMM min}
	sim_nori.setReg(16, INT_MAX-1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-2147483647, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max-, IMM min+}
	sim_nori.setReg(16, INT_MAX-1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max-1, IMM normal}
	sim_nori.setReg(16, INT_MAX-1);
	sim_nori.Nori(DonotCare, 16, 16, 0);
	EXPECT_EQ(-2147483647, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max-, IMM max-}
	sim_nori.setReg(16, INT_MAX-1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(-2147483647, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();
	
	// {SV max-, IMM max}
	sim_nori.setReg(16, INT_MAX-1);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();
	
	// {SV max, IMM min}
	sim_nori.setReg(16, INT_MAX);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max, IMM min+}
	sim_nori.setReg(16, INT_MAX);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max, IMM normal}
	sim_nori.setReg(16, INT_MAX);
	sim_nori.Nori(DonotCare, 16, 16, 0);
	EXPECT_EQ( -2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();

	// {SV max, IMM max-}
	sim_nori.setReg(16, INT_MAX);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();
	
	// {SV max, IMM max}
	sim_nori.setReg(16, INT_MAX);
	sim_nori.Nori(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(-2147483648, sim_nori.Reg[16]);
	EXPECT_EQ(0, sim_nori.errorList.size());
	sim_nori.initialize();
}


TEST_F(SimulateTest2, ItypeInstruction_Slti_Test)
{
	Simulate sim_slti;
	int DonotCare = -1;

	// {SV min, IMM min}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 0, SHORT_MIN);
	EXPECT_EQ(0, sim_slti.Reg[0]);
	EXPECT_STREQ("In cycle 0: Write $0 Error\n", sim_slti.errorList.front());
	sim_slti.errorList.pop();
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min, IMM min}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min, IMM min+}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min, IMM normal}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 16, 0);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min, IMM max-}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min, IMM max}
	sim_slti.setReg(16, INT_MIN);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min+, IMM min}
	sim_slti.setReg(16, INT_MIN+1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min+, IMM min+}
	sim_slti.setReg(16, INT_MIN+1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min+1, IMM normal}
	sim_slti.setReg(16, INT_MIN+1);
	sim_slti.Slti(DonotCare, 16, 16, 0);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min+1, IMM max-}
	sim_slti.setReg(16, INT_MIN+1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV min+1, IMM max}
	sim_slti.setReg(16, INT_MIN+1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV normal, IMM min}
	sim_slti.setReg(16, 0);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV normal, IMM min+}
	sim_slti.setReg(16, 0);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV normal, IMM normal}
	sim_slti.setReg(16, 0);
	sim_slti.Slti(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV normal, IMM max-}
	sim_slti.setReg(16, 0);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV normal, IMM max}
	sim_slti.setReg(16, 0);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(1, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max-, IMM min}
	sim_slti.setReg(16, INT_MAX-1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max-, IMM min+}
	sim_slti.setReg(16, INT_MAX-1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max-1, IMM normal}
	sim_slti.setReg(16, INT_MAX-1);
	sim_slti.Slti(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max-, IMM max-}
	sim_slti.setReg(16, INT_MAX-1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();
	
	// {SV max-, IMM max}
	sim_slti.setReg(16, INT_MAX-1);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();
	
	// {SV max, IMM min}
	sim_slti.setReg(16, INT_MAX);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max, IMM min+}
	sim_slti.setReg(16, INT_MAX);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MIN+1);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max, IMM normal}
	sim_slti.setReg(16, INT_MAX);
	sim_slti.Slti(DonotCare, 16, 16, 0);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();

	// {SV max, IMM max-}
	sim_slti.setReg(16, INT_MAX);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX-1);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();
	
	// {SV max, IMM max}
	sim_slti.setReg(16, INT_MAX);
	sim_slti.Slti(DonotCare, 16, 16, SHORT_MAX);
	EXPECT_EQ(0, sim_slti.Reg[16]);
	EXPECT_EQ(0, sim_slti.errorList.size());
	sim_slti.initialize();
}

