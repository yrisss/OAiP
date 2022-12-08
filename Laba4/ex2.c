#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 int main() {
    int n = 10, i, j;
    int a[n];
    srand(time (NULL));

printf("Initial array: ");
    for(i = 0 ; i < n; i++) { 
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }
    printf("\nSorted array: ");
    
    for(i = 0; i < (n - 6) - 1; i++) { 
       for(j = 0; j < (n - 6) - i - 1 ; j++) {  
           if(a[j] > a[j+1]) {           
              int tmp = a[j];
              a[j] = a[j+1] ;
              a[j+1] = tmp; 
           }
        }
    }
    
     for(int i = 6, q = 0; i < n - 1; i++, q++) { 
       for(j = 6; j < n - q - 1 ; j++) {  
           if(a[j] < a[j+1]) {           
              int tmp = a[j];
              a[j] = a[j+1] ;
              a[j+1] = tmp; 
           }
        }
    } 
    
    for (i = 0; i<n; i++)
    printf("%d ", a[i]);
    
    return 0;
 }
