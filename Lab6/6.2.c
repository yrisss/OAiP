#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

void main()
{ 
	setlocale(LC_ALL,"Russian");
 int *a;
 int i,j,total=0;
 int n,m;
 printf("Введите количество строк: ");
 scanf("%d", &n);
 printf("Введите количество столбцов: ");
 scanf("%d", &m);
	for (i=0;i<n;i++){
		a = (int*) malloc(n*m*sizeof(int));
 	for(j=0; j<m; j++)
 	{
 		printf("a[%d][%d] = ",i,j);
 		scanf("%d",(a+i*m+j));
	}
 }
int k=0;
  for (i=0;i<n;i++){
    int flag = 0;
   for (j=0;j<m;j++){
    if ( *(a+i*m+j) !=  *(a+i*n+j)){
      flag = 1;
}
}
   if (flag == 0){
     k++;
  }
} printf("Количество совпадений: %d\n",k);
  for (i=0;i<n;i++)
  {int  sum=0,was=0;
  for (j=0;j<m;j++)
	 {
    if ( *(a+i*m+j) < 0)	
	{
    was = 1;}
 	sum+=  *(a+i*m+j) ;
}
    if (was){
    	total += sum;
		}}
    printf("Сумма элементов матрицы = %d\n",total);
getchar();
free(a);
return 0;
}
