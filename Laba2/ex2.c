#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(void) {
	setlocale (LC_ALL, "");
	
	float S1, S2;
	
	printf("Введите площадь круга: \n");
	scanf("%f", &S1);
	printf("Введите площадь квадрата: \n");
	scanf("%f", &S2);
	 
	float diam = 2.0 * sqrt (S1 / 3.142);
	float a = sqrt(S2);
	float diag = sqrt(2.0) * a;
	if (diam >= diag) {
		printf("Квадрат поместится в круге\n");
		
	}
	
	else 
	{
		printf("Квадрат не поместится в круге\n");
	}
	
	if ( a >= diam)  
	{
		printf("Круг поместится в квадрате\n");
	}
	else
	{
		printf("Круг не поместится в квадрате\n");
	}
}
