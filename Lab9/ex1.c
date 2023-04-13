#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

int main()
{
    int k = 10; // минимальное количество символов в строке
    FILE *f1 = fopen("f1.txt", "a+");
    FILE *f2 = fopen("f2.txt", "w");

    if (f1 == NULL || f2 == NULL)
    {
        printf("Error opening files");
        return 1;
    }

    printf("Enter 10 strings. After each enter string press \"Enter\"\n");

    char line[MAX_LINE_LENGTH];

    for(int i = 0; i<10; i++)
    {
        fgets(line, MAX_LINE_LENGTH, stdin);
        fprintf(f1, "%s", line);
    }

    rewind(f1); // переход в начале файла F1

    while (fgets(line, MAX_LINE_LENGTH, f1) != NULL)
    {
        if(strlen(line) > k)
            fputs(line, f2);
    }

    fclose(f1);
    fclose(f2);

    return 0;
}