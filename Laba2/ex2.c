#include <stdio.h>
#include <locale.h>
#include <math.h>

int main(void) {
	setlocale (LC_ALL, "");
	
	float S1, S2;
	
	printf("������� ������� �����: \n");
	scanf("%f", &S1);
	printf("������� ������� ��������: \n");
	scanf("%f", &S2);
	 
	float diam = 2.0 * sqrt (S1 / 3.142);
	float a = sqrt(S2);
	float diag = sqrt(2.0) * a;
	if (diam >= diag) {
		printf("������� ����������� � �����\n");
		
	}
	
	else 
	{
		printf("������� �� ����������� � �����\n");
	}
	
	if ( a >= diam)  
	{
		printf("���� ����������� � ��������\n");
	}
	else
	{
		printf("���� �� ����������� � ��������\n");
	}
}