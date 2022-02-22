#ifndef LIST_H
#define LIST_H

#define ARRAY_BASED

typedef int ListEntry; /*this data type of the entries of the list and can be defined as what ever you want*/

#ifdef ARRAY_BASED
#define MAXLIST 10

typedef struct list /*this data type of the list itself*/
{
    int size;                   /*this is a size field*/
    ListEntry entries[MAXLIST]; /*this is an arry of the entries of the list*/
} List;

#endif

#ifdef LINKED_BASED

typedef struct listnode /*this data type of the list node in the linked-list*/
{
    ListEntry entry; /*each node consists of an entry to hold the data and a pointer to point the next node int the linked-list*/
    struct listnode *next;
} ListNode;

typedef struct list /*this data type of the list itself*/
{
    int size;       /*this is a size field*/
    ListNode *head; /*this is the pointer of the head node*/
} List;

#endif

void CreateList(List *);                        /*this function takes the pointer of the list*/
void ClearList(List *);                         /*this function takes the pointer of the list*/
int ListEmpty(List *);                          /*this function takes the pointer of the list*/
int ListFull(List *);                           /*this function takes the pointer of the list*/
int ListSize(List *);                           /*this function takes the pointer of the list*/
void InsertList(int, ListEntry, List *);        /*this function takes the index to be inserted in, the value to be inserted into the list and the pointer of the list*/
void DeletList(int, ListEntry *, List *);       /*this function takes the index to be deleted from, the pointer of the variable to be filled with the value of the entry and the pointer of the list*/
void GetListNode(int, ListEntry *, List *);     /*this function takes the index to get the value of its entry, the pointer of the variable to be filled with the value of the entry and the pointer of the list*/
void TraverseList(List *, void (*)(ListEntry)); /*this function takes the pointer of the list and the pointer of the functoin that will visit the entries*/
void ReplaceListItem(int, ListEntry, List *);   /*this function takes the index of the entry to bo replaced, the value to be take the place of hte last one and the pointer of the list*/
#endif