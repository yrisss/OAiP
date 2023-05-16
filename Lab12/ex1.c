#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 10

struct hash_table_entry {
    int key;
    int value;
    struct hash_table_entry* next;
};

struct hash_table {
    struct hash_table_entry* entries[TABLE_SIZE];
};

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(struct hash_table* table, int key, int value) {
    int index = hash(key);
    struct hash_table_entry* entry = malloc(sizeof(struct hash_table_entry));
    entry->key = key;
    entry->value = value;
    entry->next = table->entries[index];
    table->entries[index] = entry;
}

void print_table(struct hash_table* table) {
    struct hash_table_entry* all_entries[TABLE_SIZE];
    int i, j = 0;

    // Сбор всех элементов в один массив
    for (i = 0; i < TABLE_SIZE; i++) {
        struct hash_table_entry* entry = table->entries[i];
        while (entry != NULL) {
            all_entries[j++] = entry;
            entry = entry->next;
        }
    }

    // Сортировка элементов в порядке убывания ключей
    for (i = 0; i < j - 1; i++) {
        for (int k = 0; k < j - i - 1; k++) {
            if (all_entries[k]->key < all_entries[k + 1]->key) {
                struct hash_table_entry* temp = all_entries[k];
                all_entries[k] = all_entries[k + 1];
                all_entries[k + 1] = temp;
            }
        }
    }

    for (i = 0; i < j; i++) {
        printf("%d: %d\n", all_entries[i]->key, all_entries[i]->value);
    }
}

void initialize_table(struct hash_table* table) {
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        table->entries[i] = NULL; // Инициализация всех элементов NULL
    }
}

int main() {
    struct hash_table table;
    int i;
    srand(time(NULL));
    initialize_table(&table); // Инициализация хеш-таблицы перед использованием
    for (i = 0; i < 10; i++) {
        insert(&table, rand(), i);
    }
    print_table(&table);
    getchar();
    return 0;
}