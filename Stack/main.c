#include<stdio.h>
#include"Stack.h"

/*to be passed-by-ref to the function TraverseStack*/
void Display(StackEntry e)
{
    printf("the element is: %d\n", e);
}

int main()
{
    StackEntry item;    /*the StackEntry data type should be a char*/

    /*creating the stack*/
    Stack s;
    CreateStack(&s);

    /*getting the value from the user*/
    while (!StackFull(&s) && (item = getchar()) != '\n')
        Push(item, &s);

    /*printing the text in versed direction*/
    while (!StackEmpty(&s))
    {
        Pop(&item, &s);
        putchar(item);
    }
    putchar('\n');
    
}