#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number_of_trains = 0;
typedef struct trains
{
    int n_train;
    char destination[20];
    int travel_days;
    int arrival_time;
    int parking_time;
} Trains;

void add_new_train(Trains *trains)
{
    system("cls");
    printf("Enter number of train: ");
    scanf("%d", &trains[number_of_trains].n_train);
    system("cls");
    printf("Enter destination: ");
    fflush(stdin);
    gets(trains[number_of_trains].destination);
    fflush(stdin);
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
    trains = (Trains *)realloc(trains, number_of_trains + 1 * (sizeof(Trains)));
    printf("New train was added!\n");
    system("pause");
}

void output_list(Trains *trains)
{
    system("cls");
    printf("N | Number |     Destination    | Travel Days | Arrival Time | Parking Time |");
    printf("\n");
    for (int i = 0; i < number_of_trains; i++)
    {
        printf("%d. |%-8d|%-20s|%-13d|%-14d|%-14d|", i + 1, trains[i].n_train, trains[i].destination, trains[i].travel_days, trains[i].arrival_time, trains[i].parking_time);
        printf("\n");
    }
    system("pause");
}

void delete_train(Trains *trains)
{
    int n;
    output_list(trains);
    printf("Select number of train in list: ");
    scanf("%d", &n);
    for (int i = n - 1; i < number_of_trains; i++)
    {
        trains[i + 1] = trains[i];
    }
    number_of_trains--;
    trains = (Trains *)realloc(trains, number_of_trains + 1 * (sizeof(Trains)));
    system("cls");
    printf("Train was deleted!");
    system("pause");
}

void main_menu(Trains *trains)
{

    int n = 0, stop = 0;
    while (stop == 0)
    {
        system("cls");
        printf("1. Add new train\n");
        printf("2. Sort list\n");
        printf("3. Search in list\n");
        printf("4. Change train\n");
        printf("5. Delete train\n");
        printf("6. Output list\n");
        printf("7. Quit\n");
        printf("\nSelect number: ");
        scanf("%d", &n);
        if (n == 1)
            add_new_train(trains);
        // else if (n == 2)
        // sort_list();
        // else if (n == 3)
        // search_list();
        // else if (n == 4)
        // change_train();
        else if (n == 5)
            delete_train(trains);
        else if (n == 6)
            output_list(trains);
        if (n == 7)
            stop = 1;
    }
}

int main()
{
    Trains *trains = NULL;
    trains = (Trains *)malloc(number_of_trains + 1 * sizeof(Trains));
    main_menu(trains);
}
