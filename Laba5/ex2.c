#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
setlocale (LC_ALL, ""); 
 int a[15][15];
 int i,j,total=0;
 int n;
 printf("Введите размер матрицы: ");
scanf("%d", &n);
for (i=0;i<n;i++) 
 for (j=0;j<n;j++)
 {
 printf("Введите элемент [%d][%d]\n", i, j);
 scanf("%d",&a[i][j]);
 printf("a[%d][%d] == %d\n", i, j, a[i][j]);
}
int k=0;
  for (i=0;i<n;i++){
    int flag = 0;
   for (j=0;j<n;j++){
    if (a[i][j] != a[j][i]){
      flag = 1;
}
}
   if (flag == 0){
     k++;
  }
} printf("Количество совпадений: %d\n",k);
  for (i=0;i<n;i++)
  {int  sum=0,was=0;
  for (j=0;j<n;j++)
	 {
    if (a[i][j] < 0)
	{
    was = 1;}
 	sum+= a[i][j];
}
    if (was){
    	total += sum;
		}}
    printf("Сумма элементов матрицы = %d\n",total);
}
