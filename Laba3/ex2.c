#include <stdio.h>
#include <locale.h>

int main() {
	setlocale (LC_ALL, "");
	int n, a1, a2 = 0, a3, b1 = 1, b2 = 1, b3 = 1;
	printf("������� �����: ");
	scanf("%d", &n);
	
	for (int k = 1; k <= n; k++)  
	if (k%2 == 0) {
		a1 += k;
		b1 *= k; 
	}
    printf("����� ������ ����� �� 1 �� %d = %d\n", n, a1);
    printf("������������ ������ ����� �� 1 �� %d = %d\n", n, b1);

	
	for (int k = 1; k <= n; k++) 	
		if (k%2 != 0) {
		a2 += k;
		b2 *= k; 
	}
    printf("����� �������� ����� �� 1 �� %d = %d\n", n, a2);
    printf("������������ �������� ����� �� 1 �� %d = %d\n", n, b2);

	
	for (int k = 1; k <= n; k++)	
	if (k%3 == 0) {
		a3 += k;
		b3 *= k;
	}
	printf("����� ����� ������� 3 �� 1 �� %d = %d\n", n, a3);
	printf("������������ ����� ������� 3 �� 1 �� %d = %d\n", n, b3);
	
return 0;
}