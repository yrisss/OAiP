#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


int deletingSpace(char* string) {
    int j = 0;
    for(int i = 0; i < strlen(string); i++) {
        if(((*(string+i) == ' ') && (*(string+i+1) == ' ') ) || (i == 0 && (*(string+i) == ' ') && (*(string+i+1)!=' '))) {
            for (int j = i; j < strlen(string); j++)    
        *(string+j) = *(string+j+1);
        i--;
    }
       else if((i+2 == strlen(string) || i+1 == strlen(string)) && *(string+i) == ' ') {
       *(string+i) = *(string+i+1);
       *(string+i+1) = *(string+i+2);
       }
    }
}

int main() {
    char string[100];
    printf("Enter string: \n");
    fgets(string, 100, stdin);
    fflush(stdin);
    system("cls");
    printf("Initial string:\n%s", string);
    //printf("%d\n", strlen(string));
    deletingSpace(string);
   // printf("%d", strlen(string));
    printf("\nChanged string:\n%s", string);
    getch();
}