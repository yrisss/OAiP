#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

int number_of_trains = 0;
typedef struct trains {
    size_t n_train;
    char destination[100];
    size_t travel_days;
    size_t arrival_time;
    size_t parking_time;
} Trains;



void main_menu() {
    Trains *trains = NULL;
    trains = (Trains*) malloc(number_of_trains+1*sizeof(Trains));
    int n, stop = 0;
    while(stop == 0) {
    printf("1. Add new train\n");
    printf("2. Sort list\n");
    printf("3. Search in list\n");
    printf("4. Change train\n");
    printf("5. Delete train\n");
    printf("6. Output list\n");
    printf("7. Quit\n");
    printf("\nSelect number: ");
    scanf("%d", &n);
    if (n = 1)
    add_new_train(trains);
    //else if (n = 2)
   // sort_list();
   // else if (n = 3)
   // search_list();
    //else if (n = 4)
   // change_train();
   // else if (n = 5)
  //  delete_train();
  //  else if (n = 6)
   // output_list();
    if (n = 7)
    stop = 1;
    }
}

void add_new_train(Trains *trains) {
    system("cls");
    printf("Enter number of train: ");
    scanf("%d", &trains[number_of_trains].n_train);
    system("cls");
    printf("Enter destination: ");
    gets(trains[number_of_trains].destination);
    fflush;
    system("cls");
    printf("Enter travel days: ");
    scanf("%d", &trains[number_of_trains].travel_days);
    system("cls");
    printf("Enter arrival time: ");
    scanf("%d", &trains[number_of_trains].arrival_time);
    system("cls");
    printf("Enter parking time: ");
    scanf("%d", &trains[number_of_trains].parking_time);
    system("cls");
    number_of_trains++;
    trains = (Trains*) realloc(trains, number_of_trains+1*(sizeof(Trains)));
}
int main() {
    main_menu();
}