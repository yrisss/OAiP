#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(void) {
	setlocale (LC_ALL, "");
	
	float S1, S2;
	
	printf("¬ведите площадь круга: \n");
	scanf("%f", &S1);
	printf("¬ведите площадь квадрата: \n");
	scanf("%f", &S2);
	 
	float diam = 2.0 * sqrt (S1 / 3.142);
	float a = sqrt(S2);
	float diag = sqrt(2.0) * a;
	if (diam >= diag) {
		printf(" вадрат поместитьс€ в круге\n");
		
	}
	
	else 
	{
		printf(" вадрат не поместитьс€ в круге\n");
	}
	
	if ( a >= diam)  
	{
		printf(" руг поместитьс€ в квадрате\n");
	}
	else
	{
		printf(" руг не поместитьс€ в квадрате\n");
	}
}