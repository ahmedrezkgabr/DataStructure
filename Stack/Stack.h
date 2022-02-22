#ifndef STACK_H
#define STACK_H

#define LINKED_BASED
typedef struct element
{
    int k;
    int d;
} Element;
typedef Element StackEntry; /*this data type of the entries of the stack and can be defined as what ever you want*/

#ifdef ARRAY_BASED

#define MAXSTACK 10 /*in array-based implementation there is a maximum size of the stack*/

typedef struct stack /*this data type of the stack itself*/
{
    int top;                    /*this is the index of the item will be pushed*/
    StackEntry entry[MAXSTACK]; /*this is an arry of the entries of the stack*/
} Stack;

#endif

#ifdef LINKED_BASED

typedef struct stacknode /*this data type of the stack node in the linked-stack*/
{
    StackEntry entry; /*each node consists of an entry to hold the data and a pointer to point the next node int the linked-stack*/
    struct stacknode *next;
} StackNode;

/*why not: typedef StackNode *stack
to make logical distinction between the stack itself and its top
to be consistent with the definitions of outhet DS
for upgradability (int size;)*/
typedef struct stack /*this data type of the stack in the linked-stack*/
{
    int size;
    StackNode *top; /*each stack consists of a pointer to the top node of the linked-stack and a size field*/
} Stack;

#endif

void CreateStack(Stack *);                         /*this function takes the pointer of the stack*/
void ClearStack(Stack *);                          /*this function takes the pointer of the stack*/
int StackFull(Stack *);                            /*this function takes the pointer of the stack*/
int StackEmpty(Stack *);                           /*this function takes the pointer of the stack*/
int StackSize(Stack *);                            /*this function takes the pointer of the stack*/
void Push(StackEntry, Stack *);                    /*this function takes the value to be pushed in the stack and the pointer of the stack*/
void Pop(StackEntry *, Stack *);                   /*this function takes the pointer of the variable to be filled with the value of the entry and the pointer of the stack*/
void StackTop(StackEntry *, Stack *);              /*this function takes the pointer of the variable to be filled with the value of the entry and the pointer of the stack*/
void TraverseStack(Stack *, void (*)(StackEntry)); /*this function takes the pointer of the stack and the pointer of the functoin that will visit the entries*/

#endif