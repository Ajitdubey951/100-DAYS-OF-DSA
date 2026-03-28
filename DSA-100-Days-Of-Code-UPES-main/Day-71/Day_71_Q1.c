#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
#define EMPTY -1
#define DELETED -2

typedef struct
{
    int *table;
    int m;
} HashTable;

HashTable *createTable(int m)
{
    HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
    ht->m = m;
    ht->table = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++)
        ht->table[i] = EMPTY;
    return ht;
}

int hash(int key, int m)
{
    return key % m;
}

void insert(HashTable *ht, int key)
{
    int h_k = hash(key, ht->m);
    for (int i = 0; i < ht->m; i++)
    {
        int index = (h_k + i * i) % ht->m;
        if (ht->table[index] == EMPTY || ht->table[index] == DELETED)
        {
            ht->table[index] = key;
            return;
        }
    }
    printf("Table Full: Could not insert %d\n", key);
}

bool search(HashTable *ht, int key)
{
    int h_k = hash(key, ht->m);
    for (int i = 0; i < ht->m; i++)
    {
        int index = (h_k + i * i) % ht->m;
        if (ht->table[index] == EMPTY)
            return false;
        if (ht->table[index] == key)
            return true;
    }
    return false;
}

void display(HashTable *ht)
{
    for (int i = 0; i < ht->m; i++)
    {
        if (ht->table[i] == EMPTY)
            printf("[%d]: EMPTY\n", i);
        else if (ht->table[i] == DELETED)
            printf("[%d]: DELETED\n", i);
        else
            printf("[%d]: %d\n", i, ht->table[i]);
    }
}

int main()
{
    HashTable *ht = createTable(SIZE);

    insert(ht, 10);
    insert(ht, 20);
    insert(ht, 30);

    display(ht);

    printf("Search 20: %s\n", search(ht, 20) ? "Found" : "Not Found");

    return 0;
}