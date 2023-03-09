#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void inputArray(int sizeOfArray, int* arr) {
    srand(time(NULL));
  for(int i = 0; i < sizeOfArray; i++)
  for(int j = 0; j < sizeOfArray; j++)
  *(arr + i*sizeOfArray+j) = rand()%201-100;
}

void outputArray(int sizeOfArray, int* arr[sizeOfArray]) {
  for(int i = 0; i < sizeOfArray; i++) {
  for(int j = 0; j < sizeOfArray; j++)
  printf("%d ", *(arr+i*sizeOfArray+j));
  printf("\n");
  }
}

void foundString(int sizeOfArray, int* arr, int *count, int *stringNumber, int *flag) {
  int j = 0, i = 0;
  while(1) {
    if(i<sizeOfArray) {
      if(j<sizeOfArray) {
    for(j = 0; j < sizeOfArray; j++) {
      if( (*(arr+i*sizeOfArray+j)) < 0) {
        *count = 0;
        i++;
        break;
}
    else
    *count += *(arr+i*sizeOfArray+j);
    *stringNumber = i + 1;  
  }
      }
      else
      break;
    }
    else {
    flag = 0;
    *stringNumber = 0;
    break; }
  }
}

void changeArray(int sizeOfArray, int* arr, int number) {
for(int i = 0; i < sizeOfArray; i++)
for(int j = 0; j < sizeOfArray; j++)
*(arr+i*sizeOfArray+j) -= number;
}


int main() {
  int sizeOfArray, count = 0, stringNumber = 0, flag = 0;
  printf("Enter size of matrix: ");
  scanf("%d", &sizeOfArray);
  system("cls");
  int array[sizeOfArray][sizeOfArray];
  inputArray(sizeOfArray, array);
  foundString(sizeOfArray, array, &count, &stringNumber, &flag);
  printf("Initial array:\n");
  outputArray(sizeOfArray, array);
  printf("\n");
  printf("String number = %d. Count = %d\n", stringNumber, count);
  changeArray(sizeOfArray, array, count);
  printf("\nChanged array:\n");
  outputArray(sizeOfArray, array);
  system("pause");
  }