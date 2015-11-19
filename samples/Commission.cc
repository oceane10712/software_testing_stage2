#include<cstdio>
#include<cstring>
#include "Commission.h"

char *output=NULL;


char *Commission(int locks,int stocks,int barrels){

char the_output[100];
int commission=0;
bool invalid_locks = false;
bool invalid_stocks = false;
bool invalid_barrels = false;

if(locks==-1){
	return "Program terminates";
}


if(locks<1 || locks>70) invalid_locks=true;
if(stocks<1 || stocks>80) invalid_stocks=true;
if(barrels<1 || barrels>90) invalid_barrels=true;

if( invalid_locks || invalid_stocks || invalid_barrels ){
	if( invalid_locks && invalid_stocks && invalid_barrels ){
		return "locks not in 1 ... 70\nstocks not in 1 ... 80\nbarrels not in 1 ... 90\n";
	
	}else if( invalid_locks && invalid_stocks ){
		return "locks not in 1 ... 70\nstocks not in 1 ... 80\n";	
	
	}else if(invalid_locks && invalid_barrels){
		return "locks not in 1 ... 70\nbarrels not in 1 ... 90\n";

	}else if(invalid_stocks && invalid_barrels){
		return "stocks not in 1 ... 80\nbarrels not in 1 ... 90\n";

	}else if(invalid_locks){
		return "locks not in 1 ... 70\n";
	
	}else if(invalid_stocks){
		return "stocks not in 1 ... 80\n";

	}else if(invalid_barrels){
		return "barrels not in 1 ... 90\n";

	}


}


	int sales = locks*45 + stocks*30 + barrels*25;
	
	if(sales >1800){
		commission = 0.10*1000;
		commission = commission + 0.15*800;
		commission = commission + 0.20*(sales-1800);

	}else if(sales>1000){
		commission = 0.10*1000;	
		commission = commission + 0.15*(sales-1000);
		
	}else{
		commission = sales*0.10;	
	
	}	




	int x;
	x=sprintf(the_output,"$%d",commission);

	printf("%s\n",the_output);
	output=the_output;

	return output;


}














