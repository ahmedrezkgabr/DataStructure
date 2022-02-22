#include <stdlib.h>
#include "Queue.h"

#ifdef ARRAY_BASED
void CreateQueue(Queue *pq) /*creating a queue means initializing its values*/
{
    /*the rear is less than the front by one in the empty queue*/
    /*front can be 5 and the rear can be 4 but we donnot know the MAXQUEUE*/
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

void ClearQueue(Queue *pq) /*clearing a queue means destroying its entries and make the fields to its initial values*/
{
    pq->front = 0;
    pq->rear = -1;
    pq->size = 0;
}

int QueueFull(Queue *pq)
{
    return pq->size == MAXQUEUE; /*the queue is full if the size is equal to the MAXQUEUE*/
}
int QueueEmpty(Queue *pq)
{
    return !pq->size;
}
int QueueSize(Queue *pq)
{
    return pq->size;
}
void Append(QueueEntry e, Queue *pq)
{
    pq->rear = (pq->rear + 1) % MAXQUEUE; /*increasing the rear index (if it is MAXQUEUE - 1 it will be 0)*/
    pq->entry[pq->rear] = e;              /*put the element in the index*/
    pq->size++;                           /*increment the size*/
}
void Serve(QueueEntry *pe, Queue *pq)
{
    *pe = pq->entry[pq->front];             /*put the value of the entry of the front index in the by-ref-bassed variable*/
    pq->front = (pq->front + 1) % MAXQUEUE; /*increasing the front index (if it is MAXQUEUE - 1 it will be 0)*/
    pq->size--;                             /*dicrement the size*/
}
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    int pos = pq->front, s;
    for (s = 0; s < pq->size; s++)
    {
        (*pf)(pq->entry[pos]);      /*passing the values of each entry to the by-ref-passed function*/
        pos = (pos + 1) % MAXQUEUE; /*the incrementing process should be btween 0 and MAXQUEUE - 1*/
    }
}

#endif

#ifdef LINKED_BASED
void CreateQueue(Queue *pq) /*creating a queue means initializing its values*/
{
    pq->size = 0;
    pq->front = NULL;
    pq->rear = NULL;
}

void ClearQueue(Queue *pq) /*clearing a queue means destroying its entries and make the fields to its initial values*/
{
    while (pq->front) /*the loop stops when the both front and rear points to NULL*/
    {
        pq->rear = pq->front->next; /*make the rear pointer points to the second node in the queue*/
        free(pq->front);            /*free the first node in the queu*/
        pq->front = pq->rear;       /*make the front pointer points to the new first node in the queue*/
    }
    pq->size = 0; /*the size is equal to zero*/
}

int QueueFull(Queue *pq)
{
    return 0; /*the queue will never be full except the stack-overflow of the memory*/
}

int QueueEmpty(Queue *pq)
{
    return !pq->size;
}

int QueueSize(Queue *pq)
{
    return pq->size;
}

void Append(QueueEntry e, Queue *pq)
{
    /*creat a node and assigne the passed values*/
    QueueNode *pn = (QueueNode *)malloc(sizeof(QueueNode));
    pn->entry = e;
    pn->next = NULL;

    if (!pq->rear)
        pq->front = pn;      /*the first node*/
    else                     /*if it is not the first node*/
        pq->rear->next = pn; /*link the node to the end of the liked-queue*/

    pq->rear = pn; /*make the rear points to the last added node*/
    pq->size++;    /*increment the size*/
}

void Serve(QueueEntry *pe, Queue *pq)
{
    QueueNode *pn = pq->front; /*this pointer of a node will point to the first node*/
    *pe = pn->entry;           /*takeing the value*/
    pq->front = pn->next;      /*make the front pointer points to the second node in the queue*/
    free(pn);                  /*free the first node in the queue*/

    if (!pq->front)      /*if the deleted node was the only one in the queue*/
        pq->rear = NULL; /*the queue will be empty*/

    pq->size--; /*dicrement the size*/
}
void TraverseQueue(Queue *pq, void (*pf)(QueueEntry))
{
    QueueNode *pn = pq->front;
    for (int s = pq->size; s > 0; s--)
    {
        (*pf)(pn->entry); /*passing the values of each entry to the by-ref-passed function*/
        pn = pn->next;
    }
}
#endif
