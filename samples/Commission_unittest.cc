#include<limits.h>
#include"CommissionProblem.h"
#include"gtest/gtest.h"

TEST(CommissionTest, Equivalence){

	//WR
	EXPECT_STREQ("$100",Commission(10,10,10));
	EXPECT_STREQ("Program terminates",Commission(-1,40,45));
	EXPECT_STREQ("locks not in 1 ... 70\n",Commission(-2,40,45));
	EXPECT_STREQ("locks not in 1 ... 70\n",Commission(71,40,45));
	EXPECT_STREQ("stocks not in 1 ... 80\n",Commission(35,-1,45));
	EXPECT_STREQ("stocks not in 1 ... 80\n",Commission(35,81,45));
	EXPECT_STREQ("barrels not in 1 ... 90\n",Commission(35,40,-1));
	EXPECT_STREQ("barrels not in 1 ... 90\n",Commission(35,40,91));

    //SR
    EXPECT_STREQ("locks not in 1 ... 70\n",Commission(-2,40,45));
    EXPECT_STREQ("stocks not in 1 ... 80\n",Commission(35,-1,45));
    EXPECT_STREQ("barrels not in 1 ... 90\n",Commission(35,40,-2));
    EXPECT_STREQ("locks not in 1 ... 70\nstocks not in 1 ... 80\n",Commission(-2,-1,45));
    EXPECT_STREQ("locks not in 1 ... 70\nbarrels not in 1 ... 90\n",Commission(-2,40,-1));
    EXPECT_STREQ("stocks not in 1 ... 80\nbarrels not in 1 ... 90\n",Commission(35,-1,-1));
    EXPECT_STREQ("locks not in 1 ... 70\nstocks not in 1 ... 80\nbarrels not in 1 ... 90\n",Commission(-2,-2,-1));










}





