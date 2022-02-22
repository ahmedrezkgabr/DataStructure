#include <stdio.h>
#include "List.h"

/*to be passed-by-ref to the function TraverseStack*/
void Display(ListEntry e)
{
    printf("the element is: %d\n", e);
}

int main()
{
    ListEntry item; /*the ListEntry data type should be a char*/

    /*creating the queue*/
    List l;
    CreateList(&l);

    /*getting the value from the user*/
    while (!ListFull(&l) && (item = getchar()) != '\n')
        InsertList(0, item, &l);

    /*printing the text in the inversed direction*/
    while (!ListEmpty(&l))
    {
        DeletList(0, &item, &l);
        putchar(item);
    }
    putchar('\n');
}