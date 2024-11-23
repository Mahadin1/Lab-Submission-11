#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    char gender;
    float quiz1, quiz2;
    float midterm, final;
    float total;
};

void appendfile(struct Student *s) {
    FILE *file = fopen("student.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "id : %d\n", s->id);
    fprintf(file, "name : %s\n", s->name);
    fprintf(file, "gender : %c\n", s->gender);
    fprintf(file, "Quiz1 && Quiz2 : %f && %f\n", s->quiz1, s->quiz2);
    fprintf(file, "midterm && final : %f && %f\n", s->midterm, s->final);
    fprintf(file, "total score : %f\n\n", s->total);

    fclose(file);
}

void studentdetail(struct Student *s) {
    printf("ID : ");
    scanf("%d", &s->id);
    getchar(); // Consume leftover newline character

    printf("Name : ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; // Remove newline from name input

    printf("Gender (m/f) : ");
    scanf(" %c", &(s->gender)); // Notice the space before %c to handle newline

    printf("Quiz1 & Quiz2 : ");
    scanf("%f %f", &s->quiz1, &s->quiz2);

    printf("Midterm & Final : ");
    scanf("%f %f", &s->midterm, &s->final);

    s->total = s->quiz1 + s->quiz2 + s->midterm + s->final;
    appendfile(s);
}

void showAverageScore() {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("No student data available.\n");
        return;
    }

    float total_score = 0;
    int count = 0;
    struct Student s;

    while (fscanf(file, "id : %d\n", &s.id) == 1) {
        fscanf(file, "name : %[^\n]\n", s.name);
        fscanf(file, "gender : %c\n", &s.gender);
        fscanf(file, "Quiz1 && Quiz2 : %f && %f\n", &s.quiz1, &s.quiz2);
        fscanf(file, "midterm && final : %f && %f\n", &s.midterm, &s.final);
        fscanf(file, "total score : %f\n\n", &s.total);

        total_score += s.total;
        count++;
    }

    if (count > 0) {
        printf("Current average score of students: %.2f\n", total_score / count);
    } else {
        printf("No student records found.\n");
    }

    fclose(file);
}

void displayAllStudents() {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("No student data available.\n");
        return;
    }

    struct Student s;
    while (fscanf(file, "id : %d\n", &s.id) == 1) {
        fscanf(file, "name : %[^\n]\n", s.name);
        fscanf(file, "gender : %c\n", &s.gender);
        fscanf(file, "Quiz1 && Quiz2 : %f && %f\n", &s.quiz1, &s.quiz2);
        fscanf(file, "midterm && final : %f && %f\n", &s.midterm, &s.final);
        fscanf(file, "total score : %f\n\n", &s.total);

        printf("ID: %d, Name: %s, Gender: %c, Total Score: %.2f\n",
               s.id, s.name, s.gender, s.total);
    }

    fclose(file);
}

void showStatistics() {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("No student data available.\n");
        return;
    }

    int lessThan50 = 0, lessThan80 = 0, lessThan100 = 0;
    struct Student s;

    while (fscanf(file, "id : %d\n", &s.id) == 1) {
        fscanf(file, "name : %[^\n]\n", s.name);
        fscanf(file, "gender : %c\n", &s.gender);
        fscanf(file, "Quiz1 && Quiz2 : %f && %f\n", &s.quiz1, &s.quiz2);
        fscanf(file, "midterm && final : %f && %f\n", &s.midterm, &s.final);
        fscanf(file, "total score : %f\n\n", &s.total);

        if (s.total < 50) lessThan50++;
        else if (s.total < 80) lessThan80++;
        else lessThan100++;
    }

    printf("Students score < 50: %d\n", lessThan50);
    printf("Students score < 80: %d\n", lessThan80);
    printf("Students score < 100: %d\n", lessThan100);

    fclose(file);
}

int main() {
    while (1) {
        printf("\n1. Enter student details\n");
        printf("2. Show average score of students\n");
        printf("3. Display all students\n");
        printf("4. Show student statistics of mark division\n");
        printf("5. Exit\n");
        printf("Choose an option: ");

        int input;
        scanf("%d", &input);

        switch (input) {
            case 1:
                {
                    struct Student s;
                    studentdetail(&s);
                }
                break;

            case 2:
                showAverageScore();
                break;

            case 3:
                displayAllStudents();
                break;

            case 4:
                showStatistics();
                break;

            case 5:
                printf("Exit program.\n");
                return 0;

            default:
                printf("Invalid option. Please try again.\n");
        }
    }
}
