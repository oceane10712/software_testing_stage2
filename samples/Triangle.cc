#include <cstdio>
#include "Triangle.h"

char* SolveTriangleProblem(int a, int b, int c)
{
	char *output=NULL;
	bool invalid_A = false, invalid_B = false, invalid_C = false;
	bool isTriangle = false;


	/** checks each side **/
	if(a < 1 || a > 200){ invalid_A = true; }
	if(b < 1 || b > 200){ invalid_B = true;	}
	if(c < 1 || c > 200){ invalid_C = true;	}

	if(invalid_A || invalid_B || invalid_C){
		if(invalid_A && invalid_B && invalid_C){
			output = "Value of a, b, c is not in the range of permitted values";
		}
		else if(invalid_A && invalid_B){
			output = "Value of a, b is not in the range of permitted values";
		}
		else if(invalid_A && invalid_C){
			output = "Value of a, c is not in the range of permitted values";
		}
		else if(invalid_B && invalid_C){
			output = "Value of b, c is not in the range of permitted values";
		}
		else if(invalid_A){
			output = "Value of a is not in the range of permitted values";
		}
		else if(invalid_B){
			output = "Value of b is not in the range of permitted values";
		}
		else if(invalid_C){
			output = "Value of c is not in the range of permitted values";
		}
		return output;
	}


	/** checks whether it is a triangle**/
	if(a < b+c && b < a+c && c < a+b){
		isTriangle = true;
	}


	/** Determine Triangle Type **/
	if(isTriangle){
		if(a==b && b==c){
			output = "Equilateral";
		}
		else if(a==b||a==c||b==c){
			output = "Isosceles";
		}
		else{
			output = "Scalene";
		}
	}
	else{
		output = "Not a triangle";
	}

	return output;
}
