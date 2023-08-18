#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,a;
    printf("Enter variable: ");
    scanf("%d", &x);
    a= 4 * (pow(x,8));
    printf("Rezultat: %d", a);
}
