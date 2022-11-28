#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

int x,a;
printf("Vvedite peremennuy: ");
scanf("%d", &x);
a = 4 * (pow(x,8));
printf("Rezultat: %d", a);
}
