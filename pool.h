typedef struct node
{
    struct node *next;
}node_t;

typedef struct   {

    node_t* head;
    node_t* blocks;
    int depth;  
}pool_t;

void init(pool_t *pool,int ,int );
void* get(pool_t *);
void put(pool_t *, void *);
void de_init(pool_t *);
 