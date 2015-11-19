#include <limits.h>
#include "Triangle.h"
#include "gtest/gtest.h"

TEST(TriangleBoundaryTest, NormalValue){
/*	int min = 1;
	int min_plus = 2;
	int nom = 100;
	int max_minus = 199;
	int max = 200;
*/
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 100, 1));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 100, 2));
	EXPECT_STREQ("Equilateral", SolveTriangleProblem(100, 100, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 100, 199));
	EXPECT_STREQ("Not a triangle", SolveTriangleProblem(100, 100, 200));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 1, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 2, 100));
	EXPECT_STREQ("Equilateral", SolveTriangleProblem(100, 100, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(100, 199, 100));
	EXPECT_STREQ("Not a triangle", SolveTriangleProblem(100, 200, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(1, 100, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(2, 100, 100));
	EXPECT_STREQ("Equilateral", SolveTriangleProblem(100, 100, 100));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(199, 100, 100));
	EXPECT_STREQ("Not a triangle", SolveTriangleProblem(200, 100, 100));
	
	EXPECT_STREQ("Equilateral",SolveTriangleProblem(1,1,1));
	EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,1,2));
	EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,1,100));
	EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,1,199));
	EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,1,200));
	EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,2,1));
	EXPECT_STREQ("Isosceles",SolveTriangleProblem(1,2,2));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,2,100));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,2,199));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,2,200));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,100,1));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,100,2));
    EXPECT_STREQ("Isosceles",SolveTriangleProblem(1,100,100));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,100,199));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,100,200));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,199,1));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,199,2));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,199,100));
    EXPECT_STREQ("Isosceles",SolveTriangleProblem(1,199,199));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,199,200));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,200,1));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,200,2));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,200,100));
    EXPECT_STREQ("Not a triangle",SolveTriangleProblem(1,200,199));
    EXPECT_STREQ("Isosceles",SolveTriangleProblem(1,200,200));



}

TEST(TriangleEquivalenceClassTest, Equivalence){
	// WN
	EXPECT_STREQ("Equilateral", SolveTriangleProblem(5, 5, 5));
	EXPECT_STREQ("Isosceles", SolveTriangleProblem(2, 2, 3));
	EXPECT_STREQ("Scalene", SolveTriangleProblem(3, 4, 5));
	EXPECT_STREQ("Not a triangle", SolveTriangleProblem(4, 1, 2));
	
	// WR
	EXPECT_STREQ("Value of a is not in the range of permitted values", SolveTriangleProblem(-1, 5, 5));
	EXPECT_STREQ("Value of b is not in the range of permitted values", SolveTriangleProblem(5, -1, 5));
	EXPECT_STREQ("Value of c is not in the range of permitted values", SolveTriangleProblem(5, 5, -1));
	EXPECT_STREQ("Value of a is not in the range of permitted values", SolveTriangleProblem(201, 5, 5));
	EXPECT_STREQ("Value of b is not in the range of permitted values", SolveTriangleProblem(5, 201, 5));
	EXPECT_STREQ("Value of c is not in the range of permitted values", SolveTriangleProblem(5, 5, 201));
	
	// SR
	EXPECT_STREQ("Value of a is not in the range of permitted values", SolveTriangleProblem(-1, 5, 5));
	EXPECT_STREQ("Value of b is not in the range of permitted values", SolveTriangleProblem(5, -1, 5));
	EXPECT_STREQ("Value of c is not in the range of permitted values", SolveTriangleProblem(5, 5, -1));
	EXPECT_STREQ("Value of a, b is not in the range of permitted values", SolveTriangleProblem(-1, -1, 5));
	EXPECT_STREQ("Value of b, c is not in the range of permitted values", SolveTriangleProblem(5, -1, -1));
	EXPECT_STREQ("Value of a, c is not in the range of permitted values", SolveTriangleProblem(-1, 5, -1));
	EXPECT_STREQ("Value of a, b, c is not in the range of permitted values", SolveTriangleProblem(-1, -1, -1));
}
