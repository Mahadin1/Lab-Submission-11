#include<stdio.h>
#include<string.h>


int main(){
	char counter[256] = {0};
	int total = 0;
	FILE *file = fopen("Q2textfile.txt","r");
	if(file == NULL){
	printf("error");	
	 return 0;
	}
	else{
		
		char string[1000];
		while(fgets(string,sizeof(string),file) != NULL){
	    int len = strlen(string);
		for(int i = 0;i < len;i++){
			if(string[i] != '\n')
			counter[(unsigned char)string[i]]++;
			total++;
		}
			
		}
	}
	fclose(file);
	for(int i = 0;i < 256;i++){
			if(counter[i] > 0){
				if(i != ' ')
				printf("%c : occurence is %d\n",i,counter[i]);
			}
		}
	printf("total characters read  = %d", total);
	
}

