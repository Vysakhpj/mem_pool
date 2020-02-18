#include <stdio.h>
#include <stdlib.h>
#include"pool.h"

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
        return 0;
    }
}

int main()
{
    void *head;
    void *address;
    void *array[100] = {NULL};
    pool_t pool = {NULL};
    node_t* initial_pool;
    pool.block_size = 5000;
    pool.block_count = 5; 
    init(&pool, pool.block_size, pool.block_count);
    pool.blocks = pool.head;
    initial_pool = pool.head;
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
         put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
         put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
         put(&pool,address);
        address = return_address(array);
    put(&pool,address);
        address = return_address(array);
    de_init(&pool);
    return 0;
}