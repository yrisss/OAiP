#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Patient
{
    char name[50];
    char surname[50];
    char patronymic[50];
    char address[100];
    int phone;
    int card;
    int policy;
};

void print_patient(struct Patient p)
{
    printf("Last name: %s\n", p.surname);
    printf("First name: %s\n", p.name);
    printf("Middle name: %s\n", p.patronymic);
    printf("Home address: %s\n", p.address);
    printf("Phone number: %d\n", p.phone);
    printf("Medical card number: %d\n", p.card);
    printf("Insurance policy number: %d\n", p.policy);
}

void print_file(char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    struct Patient p;
    while (fread(&p, sizeof(struct Patient), 1, file))
    {
        print_patient(p);
        printf("\n");
    }
    fclose(file);
}

void add_patient(char *filename)
{
    FILE *file = fopen(filename, "ab");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    struct Patient p;
    printf("Enter patient's surname: ");
    scanf("%s", p.surname);
    printf("Enter patient's name: ");
    scanf("%s", p.name);
    printf("Enter patient's patronymic: ");
    scanf("%s", p.patronymic);
    printf("Enter patient's home address: ");
    scanf("%s", p.address);
    printf("Etner patient's phone: ");
    scanf("%d", &p.phone);
    printf("Enter patient's medical card number: ");
    scanf("%d", &p.card);
    printf("Enter patient's insurance policy number: ");
    scanf("%d", &p.policy);
    fwrite(&p, sizeof(struct Patient), 1, file);
    fclose(file);
}

void search_patient(char *filename, char *surname)
{
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("Error: could not open file %s\n", filename);
        return;
    }
    struct Patient p;
    int found = 0;
    while (fread(&p, sizeof(struct Patient), 1, file))
    {
        if (strcmp(p.surname, surname) == 0)
        {
            print_patient(p);
            printf("\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("Patient with last name %s not found.\n", surname);
    }
    fclose(file);
}

int main()
{
    char *filename = "patients.bin";
    int choice;
    char find_surname[50];
    do
    {
        printf("Menu:\n");
        printf("1. Print file\n");
        printf("2. Add patient\n");
        printf("3. Search patient by last name\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            print_file(filename);
            break;
        case 2:
            add_patient(filename);
            break;
        case 3:
            printf("Enter patient's last name: ");
            scanf("%s", find_surname);
            search_patient(filename, find_surname);
            break;
        case 0:
            break;
        default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 0);
    return 0;
}