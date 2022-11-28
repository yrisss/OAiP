#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void main(void) {
float x, y, z, s, a, b, c;
float e=exp(1.0);

printf("Vvedite x: ");
scanf("%f", &x);
	
printf("Vvedite y: ");
scanf("%f", &y);
	
printf("Vvedite z: ");
scanf("%f", &z);


a = pow(2, -x);
b = sqrt(x+pow(abs(y), 1/4));
c = pow((exp(x * 1/sin(z))), 1/8);
s = a * b * c;

printf("Rezultat: %f", c);	

}