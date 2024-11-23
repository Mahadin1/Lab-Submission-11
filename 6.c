#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct student {
    int rollno;
    char name[100];
    char dept[50];
    int batch;
    char section[10];
    float cgpa;
} st[100];

void addstudents(int n) {
    FILE *file = fopen("students.txt", "w");
    for (int i = 0; i < n; i++) {
        printf("Enter rollno: ");
        scanf("%d", &st[i].rollno);
        getchar();
        printf("Enter name: ");
        fgets(st[i].name, sizeof(st[i].name), stdin);
        st[i].name[strcspn(st[i].name, "\n")] = '\0';
        printf("Enter department: ");
        fgets(st[i].dept, sizeof(st[i].dept), stdin);
        st[i].dept[strcspn(st[i].dept, "\n")] = '\0';
        printf("Enter batch: ");
        scanf("%d", &st[i].batch);
        getchar();
        printf("Enter section: ");
        fgets(st[i].section, sizeof(st[i].section), stdin);
        st[i].section[strcspn(st[i].section, "\n")] = '\0';
        printf("Enter CGPA: ");
        scanf("%f", &st[i].cgpa);

        fprintf(file, "%d %s %s %d %s %.2f\n", st[i].rollno, st[i].name, st[i].dept, st[i].batch, st[i].section, st[i].cgpa);
    }
    fclose(file);
}

void findrollno(int rollno) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        return;
    }

    int found = 0;
    while (fscanf(file, "%d %s %s %d %s %f", &st[0].rollno, st[0].name, st[0].dept, &st[0].batch, st[0].section, &st[0].cgpa) == 6) {
        if (st[0].rollno == rollno) {
            printf("Rollno: %d\nName: %s\nDept: %s\nBatch: %d\nSection: %s\nCGPA: %.2f\n",
                   st[0].rollno, st[0].name, st[0].dept, st[0].batch, st[0].section, st[0].cgpa);
            found = 1;
            break;
        }
    }
    if (!found) printf("Student with rollno %d not found.\n", rollno);
    fclose(file);
}

void printbatch(int batch) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error reading file.\n");
        return;
    }

    while (fscanf(file, "%d %s %s %d %s %f", &st[0].rollno, st[0].name, st[0].dept, &st[0].batch, st[0].section, &st[0].cgpa) == 6) {
        if (st[0].batch == batch) {
            printf("Rollno: %d\nName: %s\nDept: %s\nBatch: %d\nSection: %s\nCGPA: %.2f\n",
                   st[0].rollno, st[0].name, st[0].dept, st[0].batch, st[0].section, st[0].cgpa);
        }
    }
    fclose(file);
}

int main() {
    int n, choice, rollno, batch;
    printf("Enter number of students: ");
    scanf("%d", &n);
    addstudents(n);
    while (1) {
        printf("1. Find student by rollno\n2. Print students in batch\n3. Exit\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter rollno: ");
            scanf("%d", &rollno);
            findrollno(rollno);
        } else if (choice == 2) {
            printf("Enter batch: ");
            scanf("%d", &batch);
            printbatch(batch);
        } else break;
    }
    return 0;
}
