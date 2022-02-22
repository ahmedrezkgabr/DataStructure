#include <stdio.h>
#include "Queue.h"

/*to be passed-by-ref to the function TraverseStack*/
void Display(QueueEntry e)
{
    printf("the element is: %d\n", e);
}

int main()
{
    QueueEntry item; /*the QueueEntry data type should be a char*/

    /*creating the queue*/
    Queue q;
    CreateQueue(&q);

    /*getting the value from the user*/
    while (!QueueFull(&q) && (item = getchar()) != '\n')
        Append(item, &q);

    /*printing the text in the same direction*/
    while (!QueueEmpty(&q))
    {
        Serve(&item, &q);
        putchar(item);
    }
    putchar('\n');
}