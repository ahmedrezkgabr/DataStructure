#include <stdio.h>
#include "Graph.h"

/*to be passed-by-ref to the function TraverseStack*/
void Display(GraphEntry e)
{
    printf("the element is: %d\n", e.data);
}

int main()
{
    /*creating a graph*/
    Graph g;
    CreateGraph(&g);

    /*inserting the elements of the graph*/

    TraverseDepthFirst(&g, 0, &Display);
}

// to be continued