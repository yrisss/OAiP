#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n_sort = 0;
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
    getchar();
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
    printf("New train was added!\n");
    system("pause");
}

void output_list(Trains *trains)
{
    system("cls");
    printf("N  | Number |     Destination    | Travel Days | Arrival Time | Parking Time |");
    printf("\n");
    for (int i = 0; i < number_of_trains; i++)
    {
        printf("%d. |%-8d|%-20s|%-13d|%-14d|%-14d|", i + 1, trains[i].n_train, trains[i].destination, trains[i].travel_days, trains[i].arrival_time, trains[i].parking_time);
        printf("\n");
    }
}

void searching(Trains *trains, int n, int c, char d[20])
{
    int a, flag = 0;
    system("cls");
    printf("| Number |     Destination    | Travel Days | Arrival Time | Parking Time |\n");
    for (int i = 0; i < number_of_trains + 1; i++)
    {
        switch (n)
        {
        case 1:
            a = (c == trains[i].n_train);
            break;
        case 2:
            a = (!(strcmp(d, trains[i].destination)));
            break;
        case 3:
            a = (c == trains[i].travel_days);
            break;
        case 4:
            a = (c == trains[i].arrival_time);
            break;
        case 5:
            a = (c == trains[i].parking_time);
            break;
        }
        if (a != 0)
        {
            flag = 1;
            printf("|%-8d|%-20s|%-13d|%-14d|%-14d|\n", trains[i].n_train, trains[i].destination, trains[i].travel_days, trains[i].arrival_time, trains[i].parking_time);
        }
        else if (flag == 0 && i == number_of_trains)
            printf("Not found!\n");
    }
    system("pause");
}

void search_list(Trains *trains)
{
    int n, c, flag;
    char d[20];
    while (1)
    {
        flag = 0;
        system("cls");
        printf("1. Search by number of train\n");
        printf("2. Search by destination\n");
        printf("3. Search by travel days\n");
        printf("4. Search by arrival time\n");
        printf("5. Search by parking time\n");
        printf("Select number(0 - exit): ");
        scanf("%d", &n);
        system("cls");
        if (n == 1)
        {
            printf("Enter number of train: ");
            scanf("%d", &c);
            searching(trains, n, c, d);
        }
        else if (n == 2)
        {
            printf("Enter destination: ");
            getchar();
            gets(d);
            fflush(stdin);
            searching(trains, n, c, d);
        }
        else if (n == 3)
        {
            printf("Enter travel days: ");
            scanf("%d", &c);
            searching(trains, n, c, d);
        }
        else if (n == 4)
        {
            printf("Enter arrival time: ");
            scanf("%d", &c);
            searching(trains, n, c, d);
        }
        else if (n == 5)
        {
            printf("Enter parking time: ");
            scanf("%d", &c);
            searching(trains, n, c, d);
        }
        else if (n == 0)
            break;
        else
        {
            system("cls");
            printf("Wrong number selected. Try again\n");
            system("pause");
        }
    }
}

int sort_int(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int sort_char(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int sorting(const void *a, const void *b)
{
    Trains *s1 = (Trains *)a;
    Trains *s2 = (Trains *)b;
    switch (n_sort)
    {
    case 1:
        return sort_int(&s1->n_train, &s2->n_train);
    case 2:
        return sort_char(&s1->destination, &s2->destination);
    case 3:
        return sort_int(&s1->travel_days, &s2->travel_days);
    case 4:
        return sort_int(&s1->arrival_time, &s2->arrival_time);
    case 5:
        return sort_int(&s1->parking_time, &s2->parking_time);
    default:
        return 0;
    }
}

void sort_list(Trains *trains)
{
    int n;
    while (1)
    {
        system("cls");
        printf("1. Sory by number of train\n");
        printf("2. Sort by destination\n");
        printf("3. Sort by travel days\n");
        printf("4. Sort by arrival time\n");
        printf("5. Sort by parking time\n");
        printf("Select number(0 - exit): ");
        scanf("%d", &n);
        n_sort = n;
        system("cls");
        if (n >= 1 && n <= 5)
        {
            qsort(trains, number_of_trains, sizeof(Trains), sorting);
            output_list(trains);
            system("pause");
        }
        else if (n == 0)
            break;
        else
        {
            system("cls");
            printf("Wrong number selected. Try again\n");
            system("pause");
        }
    }
}

void change_train(Trains *trains)
{
    int n, n1;
    while (1)
    {
        system("cls");
        output_list(trains);
        printf("Select number of train in list(0 - exit): ");
        scanf("%d", &n);
        if (n == 0)
            break;
        else if (n > 0 && n < number_of_trains + 1)
        {
            while (1)
            {
                system("cls");
                printf("1. Change number of train\n");
                printf("2. Change destination\n");
                printf("3. Change travel days\n");
                printf("4. Change arrival time\n");
                printf("5. Change parking time\n");
                printf("Select number(0 - exit): ");
                scanf("%d", &n1);
                system("cls");
                if (n1 == 1)
                {
                    printf("Enter new number of train: ");
                    scanf("%d", &trains[n - 1].n_train);
                }
                else if (n1 == 2)
                {
                    printf("Enter new destination: ");
                    getchar();
                    gets(trains[n - 1].destination);
                    fflush(stdin);
                }
                else if (n1 == 3)
                {
                    printf("Enter new travel days: ");
                    scanf("%d", &trains[n - 1].travel_days);
                }
                else if (n1 == 4)
                {
                    printf("Enter new arrival time: ");
                    scanf("%d", &trains[n - 1].arrival_time);
                }
                else if (n1 == 5)
                {
                    printf("Enter new parking time: ");
                    scanf("%d", &trains[n - 1].parking_time);
                }
                else if (n1 == 0)
                {
                    break;
                }
                else
                {
                    system("cls");
                    printf("Wrong number selected. Try again.\n");
                    system("pause");
                }
            }
        }
        else
        {
            system("cls");
            printf("Wrong number selected. Try again\n");
            system("pause");
        }
    }
}

void delete_train(Trains *trains)
{
    int n;
    while (1)
    {
        output_list(trains);
        printf("Select number of train in list: ");
        scanf("%d", &n);
        if (n > 0 && n < number_of_trains + 1)
        {
            for (int i = n - 1; i < number_of_trains; i++)
            {
                trains[i] = trains[i + 1];
            }
            number_of_trains--;
            system("cls");
            printf("Train was deleted!\n");
            system("pause");
        }
        else if (n == 0)
            break;
        else
        {
            system("cls");
            printf("Wrong number selected. Try again\n");
            system("pause");
        }
    }
}

void main_menu()
{
    Trains *trains = NULL;
    trains = (Trains *)malloc((number_of_trains + 1) * sizeof(Trains));
    int n = 0;
    while (1)
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
        {
            add_new_train(trains);
            trains = (Trains *)realloc(trains, (number_of_trains + 1) * (sizeof(Trains)));
        }
        else if (n == 2)
            sort_list(trains);
        else if (n == 3)
            search_list(trains);
        else if (n == 4)
            change_train(trains);
        else if (n == 5)
        {
            delete_train(trains);
            trains = (Trains *)realloc(trains, (number_of_trains + 1) * (sizeof(Trains)));
        }
        else if (n == 6)
        {
            output_list(trains);
            system("pause");
        }
        else if (n == 7)
            break;
        else
        {
            system("cls");
            printf("Wrong number selected. Try again\n");
            system("pause");
        }
    }
}

int main()
{
    main_menu();
}