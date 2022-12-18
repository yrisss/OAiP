#include <stdio.h>
#include <locale.h>

int main() {
	setlocale (LC_ALL, "");
	int x=0,y,i,j,k=0,f;
	while(x<=0 || y<=0) {
		printf("Введите размеры матрицы: \n");
		scanf("%d", &x);
		scanf("%d", &y);
	}
	int a[x][y];
	for(i=0; i<x; i++) {
		for(j=0; j<y; j++) {
			printf("Введите [%d][%d] - ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	for(i=0; i<x; i++) {
		for(j=0; j<y; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	for(j=0; j<y; j++) {
		for(i=0;i<x;i++) {
			if(a[i][j]>0) {
				k++;
			}
		}
		if(k==x) {
			f=j;
			break;
		} 
		k=0;
	}
	if(k==x) {
		for(i=0; i<x; i++) {
			if(f!=0) {
				a[i][f]=-a[i][f];
			} else {
				a[i][x-1]=-a[i][x-1];
			}
		}
	}
	printf("-------------\n");
	for(i=0; i<x; i++) {
		for(j=0; j<y; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
