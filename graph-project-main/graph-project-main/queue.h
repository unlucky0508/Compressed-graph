#define N 20

typedef int element;

typedef struct queue
{
    element data[N]; /* queue content */
    int front, length;
} queue;


queue CreateQueue();
int isEmptyQueue(queue q);
int isFullQueue(queue q);
int EnQueue(queue *q, element e);
int DeQueue(queue *q);
int Front(queue q, int *e);