#include <stdio.h>
#include <stdlib.h>
#include "pool.h"

void init(pool_t *pool, int size, int n)
{
    node_t *temp_node = pool->head;
    node_t *temp = NULL;
    pool->head = (node_t *)malloc((n)*size);
    printf("temp_head %p\n",pool->head);
    temp = pool->head;
    // if(temp_node!=NULL)
    // {
    //     while(temp_node->next != NULL)
    //         temp_node = temp_node+size;
    //     temp_node->next = temp;
    // }
    pool->depth = 5;
    for (int i = 0; i < n - 1; i++)
    {
        temp->next = temp + size;
        temp = temp->next;
        printf("temp_head %p\n",temp);
    }
}

void *get(pool_t *pool)
{
    if (pool->depth == 0)
    {
        blockalloc(pool,pool->block_size,pool->block_count);    
    }
    node_t *temp = pool->head;
    printf("pool_head %p\n",temp);
    printf("pool_next %p\n",temp->next);
    pool->head = temp->next;
    pool->depth--;
    printf("pool depth %d\n",pool->depth);
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
int blockalloc(pool_t* pool,int size,int n)
{
    printf("hi\n");
    node_t *temp_node = pool->head;
    node_t *temp = NULL;
    pool->head = (node_t *)malloc((n)*size);
    if(!pool->head)
        return (-1);
    for (int i = 0; i < n - 1; i++)
    {
        printf("temp_head %p\n",temp);
        temp->next = temp + size;
        temp = temp->next;
    }
    return (0);
}
