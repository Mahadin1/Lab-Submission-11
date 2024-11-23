#include<stdio.h>
#include<string.h>
#include<stdlib.h>



int main(){
	
	FILE *file1;
	file1 = fopen("file1.txt","w");
	char string1[100];
	printf("Enter text for file 1 : ");
	fgets(string1,100,stdin);
	fprintf(file1,"%s",string1);
	
	FILE *file2;
	file2 = fopen("file2.txt","w");
	char string2[100];
	printf("Enter text for file 2 :");
	fgets(string2,100,stdin);
	fprintf(file2,"%s",string2);
	fclose(file1);
	fclose(file2);
	file1 = fopen("file1.txt","r");
	file2 = fopen("file2.txt","r");
	FILE *file3;
	file3 = fopen("file3.txt","w");
	char string3[100];
	while(fgets(string3,100,file1) != NULL)
	fprintf(file3,"%s",string3);
	while(fgets(string3,100,file2) != NULL)fprintf(file3,"%s",string3);
	
	fclose(file1);
	fclose(file2);
	fclose(file3);
	
	
}