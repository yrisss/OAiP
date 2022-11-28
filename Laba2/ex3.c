#include <stdio.h>
#include <locale.h>

int main() {
	setlocale (LC_ALL, "");
	
	int k;
	printf("Выберите номер страны из списка:\n");
	printf("1. Германия\n2. Китай\n3. Канада\n4. Бразилия\n5. Индия\n6. Франция\n7. Мексика\n8. Колумбия\n\n");
 
 	scanf("%d", &k);
switch (k) {
	
	case 1:
	case 6: printf("Европа\n"); break;
	case 2:
	case 5: printf("Азия\n"); break;
	case 3:
	case 7: printf("Северная Америка\n"); break;
	case 4:
	case 8: printf("Южная Америка\n"); break;
	default: printf("Ошибка. Не выбрана страна из списка\n");
}
	

}