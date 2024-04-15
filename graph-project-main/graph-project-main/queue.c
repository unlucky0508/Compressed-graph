#include "queue.h"
// Creates functions in order to use the queue structure

queue CreateQueue()
{
    queue q;
    q.front = 0; q.length=0;
    return q;
}

int isEmptyQueue(queue q)
{
    return q.length == 0;
}

int isFullQueue(queue q)
{
    return q.length == N;
}

int EnQueue(queue *q, element e)
{
    if (isFullQueue(*q)) return 0;
    q->data[(q->front + q->length)%N] = e;
    q->length = q->length + 1;
    return 1;
}

int DeQueue(queue *q)
{
    if (isEmptyQueue(*q)) return 0;
    q->front=(q->front + 1) % N;
    q->length--;
    return 1;
}

int Front(queue q, int *e)
{
    if (isEmptyQueue(q)) return 0;
    *e = q.data[q.front];
    return 1;
}