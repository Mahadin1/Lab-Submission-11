#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct tool {
	int id;
	char name[100];
	int quantity;
	float cost;
} t;

void addnewtool() {
	FILE *file;
	file = fopen("hardware.txt","a");
	printf("Enter id: ");
	scanf("%d",&t.id);
	getchar();
	fprintf(file,"id :%d\n",t.id);
	printf("Enter toolname: ");
	gets(t.name);
	fprintf(file,"toolname :%s\n",t.name);
	printf("Enter quantity: ");
	scanf("%d",&t.quantity);
	fprintf(file,"quantity :%d\n",t.quantity);
	printf("Enter cost: ");
	scanf("%f",&t.cost);
	fprintf(file,"cost :%.2f\n\n",t.cost);

	fclose(file);
}

void printstruct() {
	printf("id :%d\n",t.id);
	printf("toolname :%s\n",t.name);
	printf("quantity :%d\n",t.quantity);
	printf("cost :%.2f\n",t.cost);
}
void displaytool() {
	FILE *file = fopen("hardware.txt","r");
	if(file == NULL) exit(0);
	char string[1000];
	while(fscanf(file,"id :%d\n",&t.id) == 1) {
		fscanf(file,"toolname :%[^\n]\n",t.name);
		fscanf(file,"quantity :%d\n",&t.quantity);
		fscanf(file,"cost :%f\n\n",&t.cost);
		printstruct();
	}
}

//void updatetool(){
//	FILE *file = fopen("hardware.txt","r");
//	if(file == NULL) exit(0);
//	char string[1000];
//	while(fscanf(file,"id :%d\n",&t.id) == 1){
//	fscanf(file,"toolname :%[^\n]\n",t.name);
//	fscanf(file,"quantity :%d\n",&t.quantity);
//	fscanf(file,"cost :%f\n\n",&t.cost);
//	printstruct();
//	}
//}
void updatetool() {
	FILE *file = fopen("hardware.txt", "r");
	if (file == NULL) {
		printf("Error\n");
		exit(0);
	}

	struct tool tools[100];
	int toolcount = 0;

	while(fscanf(file,"id :%d\n",&tools[toolcount].id) == 1) {
		fscanf(file,"toolname :%[^\n]\n",tools[toolcount].name);
		fscanf(file,"quantity :%d\n",&tools[toolcount].quantity);
		fscanf(file,"cost :%f\n\n",&tools[toolcount].cost);
		toolcount++;
	}
	fclose(file);

	int idupdate;
	printf("Enter the ID of the tool to update: ");
	scanf("%d", &idupdate);

	int found = 0;
	for (int i = 0; i < toolcount; i++) {
		if (tools[i].id == idupdate) {
			found = 1;
			printf("Tool found: %s (Current Quantity: %d)\n", tools[i].name, tools[i].quantity);
			printf("Enter new quantity: ");
			scanf("%d", &tools[i].quantity);
			break;
		}
	}

	if (!found) {
		printf("not found.\n", idupdate);
		return;
	}

	file = fopen("hardware.txt", "w");
	if (file == NULL) {
		printf("Error opening file for writing.\n");
		return;
	}

	for (int i = 0; i < toolcount; i++) {
		fprintf(file, "id: %d\n", tools[i].id);
		fprintf(file, "toolname: %s\n", tools[i].name);
		fprintf(file, "quantity: %d\n", tools[i].quantity);
		fprintf(file, "cost: %.2f\n\n", tools[i].cost);
	}

	fclose(file);
	printf("Tool updated successfully.\n");
}

void removetool() {
	FILE *file = fopen("hardware.txt", "r");
	if (file == NULL) {
		printf("Error\n");
		exit(0);
	}
	printf("Please check the id from display to delete, then enter ID :");
	int idrem;
	scanf("%d",&idrem);
	int flag =0;
	struct tool *toolrem = (struct tool *)malloc(sizeof(struct tool)*100);
	int counter = 0;
	while(fscanf(file,"id :%d\n",&toolrem[counter].id) == 1) {
		fscanf(file,"toolname :%[^\n]\n",toolrem[counter].name);
		fscanf(file,"quantity :%d\n",&toolrem[counter].quantity);
		fscanf(file,"cost :%f\n\n",&toolrem[counter].cost);
		if(toolrem[counter].id == idrem) {
			flag = 1;
		}else{
		counter++;
			
		}
	}
	fclose(file);
	if(flag == 1)printf("deleted");
	else printf("id not found");



	file = fopen("hardware.txt", "w");
	if (file == NULL) {
		printf("Error\n");
		exit(0);
	}
	for(int i=0; i < counter; i++) {
		fprintf(file,"id :%d\n",toolrem[i].id);
		fprintf(file,"toolname :%s\n",toolrem[i].name);
		fprintf(file,"quantity :%d\n",toolrem[i].quantity);
		fprintf(file,"cost :%.2f\n\n",toolrem[i].cost);

	}
	fclose(file);



	free(toolrem);
}

int main() {
	int input;
	while(1) {
		printf("1.Enter new tool\n2.display all tool\n3.update\n4.remove tool\n5.exit\n");
		scanf("%d",&input);
		switch(input) {
			case 1:
				addnewtool();
				break;
			case 2:
				displaytool();
				break;
			case 3:
				updatetool();
				break;
			case 4:
				removetool();
				break;
			case 5:
				break;

		}

	}






	return 0;
}