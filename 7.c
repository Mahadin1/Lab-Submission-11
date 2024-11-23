#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void encryptfile() {
    FILE *input = fopen("random.txt", "r");
    FILE *output = fopen("encrypted.txt", "w");
    if (input == NULL || output == NULL) exit(0);
    char ch;
    int vowelCount = 0;
    while ((ch = fgetc(input)) != EOF) {
        if (strchr("aeiouAEIOU", ch)) {
            vowelCount++;
            if (vowelCount % 2 == 0) {
                fprintf(output, "VOW");
            } else {
                fprintf(output, "vow");
            }
        } else if (ch == 's' || ch == 'S') {
            char string[4];
            string[0] = ch;
            string[1] = fgetc(input);
            string[2] = fgetc(input);
            string[3] = '\0';
            if (strlen(string) == 3 && strchr(string, 's')) {
                fprintf(output, "PF-Lab");
            } else {
                fprintf(output, "%s", string);
            }
        } else if (isalpha(ch)) {
            if (ch >= 'A' && ch <= 'Z') {
                ch = 'A' + ((ch - 'A') + 3) % 26;
            } else if (ch >= 'a' && ch <= 'z') {
                ch = 'a' + ((ch - 'a') + 3) % 26;
            }
            fputc(ch, output);
        } else {
            fputc(ch, output);
        }
    }
    fclose(input);
    fclose(output);
    printf("File encrypted\n");
}

int main() {
    encryptfile();
    return 0;
}
