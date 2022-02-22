#include <stdio.h>
#include "Tree.h"

/*to be passed-by-ref to the function TraverseStack*/
void Display(TreeEntry e)
{
    printf("the element no.: %d is: %d %s\n", e.key, e.data, e.name);
}

int main()
{
    /*creating a tree*/
    Tree t;
    CreatTree(&t);

    Element e3;
    e3.key = 3;
    e3.data = 207;
    e3.name = "Harry";

    Element e4;
    e4.key = 4;
    e4.data = 101;
    e4.name = "Ron";

    /*inserting the two elements*/
    InsertTreeIter(&t, &e4);
    InsertTreeIter(&t, &e3);

    /*traverse the tree in LVR manner*/
    InOrderTree(&t, &Display);
    printf("%d", TreeDepth(&t));
}