#include <stdio.h>
#include <locale.h>

int main(void)
{
	setlocale (LC_ALL, "");
	float a, b, c;

	printf("%s", "Введите длины сторон треугольника a, b, c: ");
	scanf("%f %f %f", &a, &b, &c);

	if (a == b || b == c || a == c)
	{
		printf("Треугольник равнобедренный");
	}

	else
	{
		printf("Треугольник не равнобедренный");
	}

	return 0;
}
