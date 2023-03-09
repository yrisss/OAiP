#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "");
int i,p=1,s=0,n;
float *b, maxX=0, maxM=0;
 if(!(b=(int*)calloc(15,sizeof(int))))
   { puts("Недостаточно памяти"); 	
   getch(); return; 
   }
do{
printf("Введите количество элементов массива (<30)\n");
scanf("%d",&n); 
} while (n>=30);
for (i=0;i<n;i++)
{
printf("Введите элемент [%d]\n", i+1);
scanf("%f",b+i);
}
for (i=0;i<n;i++)
	if(*(b+i)<0){
		p*=*(b+i);}
printf("Произведение равно: %d",p);
	for (i=0;i<n;i++){
		if (*(b+i)> maxM){
		maxM=*(b+i);
		maxX=i;}
	}
for (i=0;i<maxX;i++){
	if (*(b+i)>0){
 	s+=*(b+i);}}
 	printf("Сумма положительных матриц = %d\n",s);
 	free(b);
}
