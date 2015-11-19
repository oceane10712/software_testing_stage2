#include <cstdio>
#include "NextDate.h"
#include <cstring>

char *NextDateProblem(int month, int day, int year){
	
	char *output=NULL;
	char the_output[1000];
	bool invalid_month = false;
	bool invalid_day = false;
	bool invalid_year = false;
	int tomorrow_day = day;
	int tomorrow_month = month;
	int tomorrow_year = year;
	int x;

	if( month>12 || month<1 ){
		invalid_month = true;
	}
	
	if( day>31 || day<1){
		invalid_day = true;
	}

	if(year>2012||year<1812){
		invalid_year = true;
	}

	if(invalid_month || invalid_day||invalid_year){	
		
		if( invalid_month && invalid_day && invalid_year ){
			return "month not in 1...12\nday not in 1...31\nyear not in 1812...2012\n";
		
		}else if( invalid_month && invalid_day ){
			return "month not in 1...12\nday not in 1...31\n";
		
		}else if( invalid_month && invalid_year ){
			return "month not in 1...12\nyear not in 1812...2012\n";

		}else if( invalid_day && invalid_year ){
			return "day not in 1...31\nyear not in 1812...2012\n";
		
		}else if( invalid_month ){
			return "month not in 1...12\n";

		}else if( invalid_day ){
			return "day not in 1...31\n";

		}else if( invalid_year ){
			return "year not in 1812...2012\n";

		}




	}

	
	if(month==2){
		
		if(day<28){
			tomorrow_day=day+1;
		}else if(day==28){
			if (((year%4 == 0) && (year%100 !=0)) || (year%400==0)){
				//is leap year
				tomorrow_day=29;
			}else{
				//not leap year
				tomorrow_day=1;
				tomorrow_month=3;
			}	
		
		}else if(day==29){
			if(((year%4 == 0) && (year%100 !=0)) || (year%400==0)){
				//is leap year
				tomorrow_day=1;
				tomorrow_month=3;
			}else{
				//not leap year
				//x=sprintf(the_output,"Invalid input date");				
				return "Invalid input date";
			}
		
		
		}else{
			//x=sprintf(the_output,"Invalid input date");
			return "Invalid input date";	
		}
		
	}else if(month==12){
		if(day<31){
			tomorrow_day=day+1;
		}else{
			tomorrow_day=1;
			tomorrow_month=1;
			if (year==2012){
				return "2012 is over";
			
			}else{
				tomorrow_year=year+1;
			}	
			
		}

	}else if(month==4||month==6||month==9||month==11){
		if(day==31){
			return "Invalid input date";
		
		}else if(day<30){
			tomorrow_day=day+1;
		}else{
			tomorrow_day=1;
			tomorrow_month=month+1;
		}
	
	
	}else if(month==1||month==3||month==5||month==7||month==8||month==10){
		if(day<31){
			tomorrow_day=day+1;
		}else{
			tomorrow_month=month+1;
			tomorrow_day=1;
		}	
	
	
	}else{
	
		return "something wrong...";
	}



	
	
	x = sprintf(the_output,"%d/%d/%d",tomorrow_month,tomorrow_day,tomorrow_year);
	

	//return the_output;
	output=the_output;
	return output;






}





