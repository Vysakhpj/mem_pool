#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pool.h"

static int block_alloc(pool_t* pool)
{
    node_t *temp = NULL; 
    size_t memcnt = sizeof(node_t)+(pool->block_size * pool->block_count);
    node_t *temp_block = (node_t *)malloc(memcnt); 
    if(!temp_block)
        return (-1);
    memset(temp_block, 0, memcnt);
    temp_block->next = pool->blocks;
    pool->blocks = temp_block;
    pool->head = pool->blocks + 1;
    // if(temp_block!= NULL)
    //     temp_block->next = pool->head;
    pool->free_address = pool->head;
    temp = pool->head;

    pool->depth += pool->block_count;
    for (int i = 0; i < pool->block_count ; i++)
    {
        printf("temp %d\n",temp);
        temp->next = (void*)temp + pool->block_size;
        temp = temp->next;
    }
    printf("\n\n");
    return 0;
}

int init(pool_t *pool, int size, int n)
{
    memset(pool, 0, sizeof(pool_t));
    pool->block_size = size;
    pool->block_count = n;
    block_alloc(pool);
    if(pool->head)
        return(0);
    else
        return(-1);
    
}

void *get(pool_t *pool)
{
    node_t *temp = pool->head;
    if(pool->depth == 0)
    {
        block_alloc(pool);
        temp = pool->head;
    }
    printf("borrowing %d\n",pool->free_address);
    pool->free_address = pool->free_address->next;
    //pool->head = temp->next;
    pool->used_address = pool->head;
    pool->depth--;
    return 0;
}

void put(pool_t *pool)
{
    // node_t *temp = address;
    if (pool->used_address)
    {
        pool->head = pool->head->next;
        printf("returning %d\n",pool->used_address);
        pool->used_address->next = pool->free_address->next;
        pool->free_address->next = pool->used_address;
        pool->used_address = pool->head;
        // temp->next = pool->head;
        // pool->head = temp;
        // printf("returning %d\n",pool->used);
        pool->depth++;
    }
}

void de_init(pool_t *pool)
{
    node_t* temp_node = pool->blocks;
    while (pool && pool->blocks->next)
    {
        free(pool->blocks);
        if(temp_node->next != NULL) 
            pool->blocks = pool->blocks->next;                
    }
}