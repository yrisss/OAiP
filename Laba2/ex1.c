#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale (LC_ALL, "");
	float a, b, c;

	printf("%s", "������� ����� ������ ������������ a, b, c: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a == b || b == c || a == c)
	{
		printf("����������� ��������������");
	}

	else
	{
		printf("����������� �� ��������������");
	}

	return 0;
}