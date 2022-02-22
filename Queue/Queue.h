#ifndef QUEUE_H
#define QUEUE_H

#define LINKED_BASED

typedef int QueueEntry; /*this data type of the entries of the queue and can be defined as what ever you want*/

#ifdef ARRAY_BASED

#define MAXQUEUE 10 /*in array-based implementation there is a maximum size of the queue*/

typedef struct queue /*this data type of the queue itself*/
{
    int front;                  /*this is the index of the item will be served*/
    int rear;                   /*this is the index of the item will be appended*/
    int size;                   /*the size of the queue (it is important int the circular-array-based implementation)*/
    QueueEntry entry[MAXQUEUE]; /*this is an arry of the entries of the queue*/
} Queue;

#endif

#ifdef LINKED_BASED

typedef struct queuenode /*this data type of the queue node in the linked-queue*/
{
    QueueEntry entry; /*each node consists of an entry to hold the data and a pointer to point the next node int the linked-queue*/
    struct queuenode *next;
} QueueNode;

typedef struct queue /*this data type of the queue itself*/
{
    QueueNode *front; /*each queue consists of a pointer to the front node of the linked-queue, a pointer to the rear node of the linked-queue and a size field*/
    QueueNode *rear;  /*the front and rear pointers points to NULL at the same time (empty queue) and points to the same node(queue with one node)*/
    int size;
} Queue;

#endif

void CreateQueue(Queue *);                         /*this function takes the pointer of the queue*/
void ClearQueue(Queue *);                          /*this function takes the pointer of the queue*/
int QueueFull(Queue *);                            /*this function takes the pointer of the queue*/
int QueueEmpty(Queue *);                           /*this function takes the pointer of the queue*/
int QueueSize(Queue *);                            /*this function takes the pointer of the queue*/
void Append(QueueEntry, Queue *);                  /*this function takes the value to be added to the queue and the pointer of the queue*/
void Serve(QueueEntry *, Queue *);                 /*this function takes the pointer of the variable to be filled with the value of the entry and the pointer of the queue*/
void TraverseQueue(Queue *, void (*)(QueueEntry)); /*this function takes the pointer of the queue and the pointer of the functoin that will visit the entries*/

#endif