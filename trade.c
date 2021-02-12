
// A.M.M.S.Attanayake.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "trade2.h"

#define DATAFILE "trade-during-covid.csv"

int main(int argc, char **argv)
{

	  if(argc != 3) {
		printf("One commandline argument\n");
		return -1;
	  }
	  
	  FILE *fp = fopen(DATAFILE, "r");
	  if(!fp) {
		printf("Can't open data file\n");
		return -1;
	  }
	  

	  char line[300];
	  fgets(line, 300, fp);
	  int countryIndex = getFieldIndex(line, "Country");
	  int DirectionIndex = getFieldIndex(line, "Direction");
	  int ValueIndex   = getFieldIndex(line, "Value");
	  int DateIndex    = getFieldIndex(line, "Date");
	  
	  if(countryIndex == -1||
		 DirectionIndex   == -1 ||
		 DateIndex == -1 ) {
		printf("Can't file field\n");
		return -1;
	  }
	  int country_name=0;
	  long long  current = 0, max = 0;
	  char maxDate[11];
	  while(fgets(line, 300, fp) != NULL) {
		
		char countryName[40];
		char DirectionName[40];
		getFieldString(line, countryIndex, countryName);
		getFieldString(line, DirectionIndex, DirectionName);
		if(strcmp(argv[2], countryName) == 0){
			country_name=1;
		
			if(strcmp(argv[1], DirectionName) == 0){
				
			
				current = getFieldValue(line,ValueIndex);
				
				if(current > max) {
				  max =current;
				  getFieldString(line, DateIndex, maxDate);
				}
			}
		}	
			 
	  }
	if(country_name!=1){
		printf("error in country name\n");
	}
	
				 
	  printf("In %s max %s was %lld $ and was reported on %s\n",argv[2],argv[1] , max, maxDate);
	  

fclose(fp);
return 0;
}

//A.M.M.S.Attanayake