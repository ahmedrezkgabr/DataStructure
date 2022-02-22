#include <stdlib.h>
#include "Stack.h"

#ifdef ARRAY_BASED
void CreateStack(Stack *ps) /*creating a stack means initializing its values*/
{
    ps->top = 0; /*make the first available index to push in is 0*/
}

void ClearStack(Stack *ps) /*clearing a stack means destroying its entries and make the top index starts from 0*/
{
    ps->top = 0;
}

void Push(StackEntry e, Stack *ps)
{
    ps->entry[ps->top++] = e; /*put the element in the index and increase the top index*/
}

void Pop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[--ps->top]; /*decrease the top index and put the value of the entry in the by-ref-bassed variable*/
}

int StackFull(Stack *ps)
{
    return ps->top == MAXSTACK; /*the stack is full if the top index is equal to the MAXSTACK*/
}

int StackEmpty(Stack *ps)
{
    return !ps->top; /*the stack is empty if the top index is equal to 0*/
}

int StackSize(Stack *ps)
{
    return ps->top;
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->entry[ps->top]; /*put the value of the entry in the by-ref-bassed variable without decreasing the top index*/
}

void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    int pos;
    for (pos = ps->top; pos > 0; pos--)
        (*pf)(ps->entry[pos - 1]); /*passing the values of each entry to the by-ref-passed function*/
}
#endif

#ifdef LINKED_BASED
void CreateStack(Stack *ps) /*creating a stack means initializing its values*/
{
    ps->top = NULL; /*make the top pointer points to nothing*/
    ps->size = 0;   /*initialize the size*/
}

void ClearStack(Stack *ps) /*clearing a stack means destroying its entries and make the top index starts from 0*/
{
    StackNode *pn = ps->top; /*make a pointer to node*/

    while (pn) /*the loop stops when the pointer points to NULL*/
    {
        pn = pn->next; /*the poiner starts from the top node and every iteration it will point to the next one*/
        free(ps->top); /*free the memory occupied by the node*/
        ps->top = pn;  /*make the top pointer points to the next of itself*/
    }
    ps->size = 0; /*the size is equal to zero*/
}

void Push(StackEntry e, Stack *ps)
{
    /*creat a node and assigne the passed values*/
    StackNode *pn = (StackNode *)malloc(sizeof(StackNode));
    pn->entry = e;

    pn->next = ps->top; /*the pointer in the new node will point the the old top node*/
    ps->top = pn;       /*the new top node is the created one*/
    ps->size++;         /*the size is incremented*/
}

void Pop(StackEntry *pe, Stack *ps)
{
    StackNode *pn; /*make a pointer to node to point the first node*/
    pn = ps->top;
    *pe = pn->entry;    /*takeing the value*/
    ps->top = pn->next; /*make the new top node is the second one*/
    free(pn);           /*free the memory eccupied with the old top node*/
    ps->size--;         /*the size is dicremented*/
}

int StackFull(Stack *ps)
{
    return 0; /*the stack will never be full except the stack-overflow of the memory*/
}

int StackEmpty(Stack *ps)
{
    return !ps->top; /*the stack is empty when the top pointer points to NULL*/
}

int StackSize(Stack *ps)
{
    return ps->size; /*to make the big-theta of this function is 1 we added the field of size in the type of the stack*/
}

void StackTop(StackEntry *pe, Stack *ps)
{
    *pe = ps->top->entry; /*takeing the value*/
}

void TraverseStack(Stack *ps, void (*pf)(StackEntry))
{
    StackNode *pn = ps->top;
    while (pn) /*passing the values of each entry to the by-ref-passed function*/
    {
        (*pf)(pn->entry);
        pn = pn->next;
    }
}
#endif
