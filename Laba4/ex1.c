#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	int N;
	printf("Enter the size of the array: ");
	scanf("%d", &N);
	int a[N];
	srand(time (NULL));
	
	printf("Initial array: ");
	for(int i=0; i<N; i++) {
	
		a[i] = rand()%21 - 10;
		printf("%d ", a[i]);
	}
	printf("\nArray of negative numbers: ");
	
	int neg [10];
	int pos [10];
	
	for (int i = 0; i<N; i++) {
		if (a[i] < 0) {	
			neg[i] = a[i];
			printf("%d ", neg[i]);
		}
		}
	printf("\nArray of positive numbers: ");
		
	for (int i = 0; i<N; i++) {
		if (a[i] >= 0) {	
			pos[i] = a[i];
			printf("%d ", pos[i]);
		}
		}
		
return 0;
}
	
