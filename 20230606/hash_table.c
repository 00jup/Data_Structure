#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 7

typedef struct
{
    int key;
} element;

struct list
{
    element item;
    struct list *next;
};
struct list *hash_table[TABLE_SIZE];

int hash_function(int key)
{
    return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list *ht[])
{
    int hash_value = hash_function(item.key);
    struct list *ptr;
    struct list *node_before = NULL, *node = ht[hash_value];
    for (; node; node_before = node, node = node->next)
    {
        if (node->item.key == item.key)
        {
            printf("Duplicate key\n");
            return;
        }
    }
    ptr = (struct list *)malloc(sizeof(struct list));
    ptr->item = item;
    ptr->next = NULL;
    if (node_before)
        node_before->next = ptr;
    else
        ht[hash_value] = ptr;
}

void hash_chain_search(element item, struct list *ht[])
{
    int hash_value = hash_function(item.key);
    struct list *node;
    for (node = ht[hash_value]; node; node = node->next)
    {
        if (node->item.key == item.key)
        {
            printf("Search success\n");
            return;
        }
    }
    printf("Search failed\n");
}

void hash_chain_print(struct list *ht[])
{
    struct list *node;
    printf("\n====================\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("[%d] ", i);
        for (node = ht[i]; node; node = node->next)
            printf("%d ", node->item.key);
        printf("\n");
    }
    printf("\n====================\n");
}
#define SIZE 5

int main(void)
{
    int data[SIZE] = {8, 1, 9, 6, 13};
    element e;

    for (int i = 0; i < SIZE; i++)
    {
        e.key = data[i];
        hash_chain_add(e, hash_table);
        hash_chain_print(hash_table);
    }
    for (int i = 0; i < SIZE; i++)
    {
        e.key = data[i];
        hash_chain_search(e, hash_table);
    }
    return 0;
}