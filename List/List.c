#include <stdlib.h>
#include "List.h"

#ifdef ARRAY_BASED

void CreateList(List *pl) /*creating a list means initializing its values*/
{
    pl->size = 0;
}

void ClearList(List *pl) /*clearing a list means destroying its entries and make the fields to its initial values*/
{
    pl->size = 0;
}

int ListEmpty(List *pl)
{
    return !pl->size;
}

int ListFull(List *pl)
{
    return pl->size == MAXLIST; /*the list is full if the size is equal to the MAXLIST*/
}

int ListSize(List *pl)
{
    return pl->size;
}

void InsertList(int pos, ListEntry e, List *pl)
{
    for (int i = pl->size - 1; i >= pos; i--)
        pl->entries[i + 1] = pl->entries[i]; /*shifting-up all the entries starting from the index pos to the end of the list*/
    pl->entries[pos] = e;                    /*assign the value*/
    pl->size++;                              /*increment the size*/
}

void DeletList(int pos, ListEntry *pe, List *pl)
{
    *pe = pl->entries[pos]; /*taking the value*/
    for (int i = pos + 1; i <= pl->size - 1; i++)
        pl->entries[i - 1] = pl->entries[i]; /*shifting-down all the entries starting from the index pos + 1 to the end of the list*/
    pl->size--;                              /*dicrement the size*/
}

void GetListNode(int pos, ListEntry *pe, List *pl)
{
    *pe = pl->entries[pos]; /*taking the value*/
}

void TraverseList(List *pl, void (*pf)(ListEntry))
{
    for (int i = 0; i < pl->size; i++)
        (*pf)(pl->entries[i]); /*passing the values of each entry to the by-ref-passed function*/
}

void ReplaceListItem(int pos, ListEntry e, List *pl)
{
    pl->entries[pos] = e; /*assign the neqw value*/
}
#endif

#ifdef LINKED_BASED

void CreateList(List *pl) /*creating a list means initializing its values*/
{
    pl->head = NULL;
    pl->size = 0;
}

void ClearList(List *pl) /*clearing a list means destroying its entries and make the fields to its initial values*/
{
    ListNode *pn;
    while (pl->head) /*stops when the list gets empty*/
    {
        pn = pl->head->next; /*starts from the forst node*/
        free(pl->head);      /*free the first node*/
        pl->head = pn;       /*make the pointer of the head points to the second one*/
    }
    pl->size = 0;
}

int ListEmpty(List *pl)
{
    return !(pl->size);
}

int ListFull(List *pl)
{
    return 0;
}

int ListSize(List *pl)
{
    return pl->size;
}

void InsertList(int pos, ListEntry e, List *pl)
{
    /*crating a new node and assign ist values*/
    ListNode *pn = (ListNode *)malloc(sizeof(ListNode)), *q;
    pn->entry = e;
    pn->next = NULL;

    if (pos == 0) /*inserting at the beginning*/
    {
        pn->next = pl->head; /*link the node to the linked-list*/
        pl->head = pn;       /*the head points to the new head node*/
    }
    else
    {
        q = pl->head;
        for (int i = 0; i < pos - 1; i++)
            q = q->next;    /*reaching the node before the wanted index*/
        pn->next = q->next; /*link the node to the linked-list*/
        q->next = pn;
    }
    pl->size++; /*increment the size*/
}

void DeletList(int pos, ListEntry *pe, List *pl)
{
    ListNode *q, *t;
    if (pos == 0) /*deleting from the beginning*/
    {
        *pe = pl->head->entry; /*taking the value*/
        t = pl->head->next;    /*catch the rest of the linked-list*/
        free(pl->head);        /*free the node*/
        pl->head = t;          /*make the head points to the second one*/
    }
    else
    {
        q = pl->head;
        for (int i = 0; i < pos - 1; i++)
            q = q->next;      /*reaching the node before the wanted index*/
        *pe = q->next->entry; /*taking the value*/
        t = q->next->next;    /*catch the rest of the linked-list*/
        free(q->next);        /*free the node*/
        q->next = t;          /*link the before node with the next node*/
    }
    pl->size--; /*dicrement the size*/
}

void GetListNode(int pos, ListEntry *pe, List *pl)
{
    ListNode *pn = pl->head;
    for (int i = 0; i < pos; i++)
        pn = pn->next; /*reaching the wanted pos*/
    *pe = pn->entry;   /*taking the value*/
}

void ReplaceListItem(int pos, ListEntry e, List *pl)
{
    ListNode *pn = pl->head;
    for (int i = 0; i < pos; i++)
        pn = pn->next; /*reaching the wanted pos*/
    pn->entry = e;     /*assign the new value*/
}

void TraverseList(List *pl, void (*pf)(ListEntry))
{
    ListNode *pn = pl->head;
    while (pn)
    {
        (*pf)(pn->entry); /*passing the values of each entry to the by-ref-passed function*/
        pn = pn->next;
    }
}

#endif
