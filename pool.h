#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *next;
}node_t;

typedef struct   {
    int block_count;
    node_t* head;
    node_t* blocks;
    node_t* free_address;
    node_t* used_address;
    int block_size;
    int depth;  
}pool_t;

int init(pool_t *pool,int ,int );
void* get(pool_t *);
void put(pool_t *);
void de_init(pool_t *);