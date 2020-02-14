#include <stdio.h>
#include <stdlib.h>
#include "pool.h"

void init(pool_t *pool, int size, int n)
{
    node_t *temp = NULL;
    pool->head = (node_t *)malloc((n)*size);
    pool->blocks = pool->head;
    temp = pool->head;
    pool->depth = 5;
    for (int i = 0; i < n - 1; i++)
    {
        temp->next = temp + size;
        temp = temp->next;
    }
}

void *get(pool_t *pool)
{
    if (pool->depth == 0)
    {
        return NULL;
    }
    node_t *temp = pool->head;
    pool->head = temp->next;
    pool->depth--;
    return temp;
}
void put(pool_t *pool, void *address)
{
    int i = 0;
    node_t *temp = address;
    if (temp != NULL)
    {
        temp->next = pool->head;
        pool->head = temp;
        pool->depth++;
    }
}

void de_init(pool_t *pool)
{
    if (pool && pool->blocks)
    {
        free(pool->blocks);
    }
    pool->blocks = NULL;
    pool->head = NULL;
    pool->depth = 0;
}

void address_store(void *array_store[], void *address)
{
    int i = 0;
    while (array_store[i] != NULL)
        i++;
    array_store[i] = address;
}
void *return_address(void *array_address[])
{
    int i = 0, flag;
    void *address_push;
    while (array_address[i] == NULL)
    {
        i++;
    }
    if (i < 100)
    {
        address_push = array_address[i];
        array_address[i] = NULL;
        return address_push;
    }
    else
    {
        printf("nothing to return\n");
        return 0;
    }
}
int main()
{
    void *head;
    void *address;
    void *array[100] = {NULL};
    pool_t pool;
    init(&pool, 50, 5);
    head = get(&pool);
    address_store(array, head);
    address = return_address(array);
    head = get(&pool);
    address_store(array, head);
    head = get(&pool);
    address_store(array, head);
    head = get(&pool);
    address_store(array, head);
    head = get(&pool);
    address_store(array, head);
    head = get(&pool);
    address_store(array, head);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    head = get(&pool);
        address_store(array,head);
    head = get(&pool);
        address_store(array,head);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    printf("should not print anything\n");
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    head = get(&pool);
        address_store(array,head);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    // de_init(&pool);
    return 0;
}
