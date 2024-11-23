#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(){
	double sum1 = 0;
	double sum2 = 0;
	double sum3 = 0;
	double col1_val = 0;
	double col2_val = 0;
	double col3_val = 0;
	FILE *file = fopen("budge.txt","r");
	if(file == NULL) exit(0);
	
	while(fscanf(file,"%lf %lf %lf",&col1_val,&col2_val,&col3_val) == 3){
		sum1 += col1_val;
		sum2 += col2_val;
		sum3 += col3_val;
	}
	
	fclose(file);
	printf("column sums are : %.2f %.2f %.2f",sum1,sum2,sum3);
	
	
	return 0;
}
