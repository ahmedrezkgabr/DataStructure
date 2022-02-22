#include <stdlib.h>
#include "Graph.h"

void CreateGraph(Graph *pg) /*creating a queue means initializing its values*/
{
    pg->size = 0;
    for (int i = 0; i < pg->size; i++)
        pg->vertices[i].first = NULL; /*make the first pointer of each vertex points to NULL*/
}

void TraverseDepthFirstAux(Graph *pg, int k, void (*pf)(GraphEntry), int visited[]) /*this function takes the pointer of the graph, the index of the vertex starting traversing from, the pointer to the function to be applied over the entries and the array of visited vertices*/
{                                                                                   /*this function is not allowable to the user only to be called in TraverseDepthFirst*/
    (*pf)(pg->vertices[k].entry);                                                   /*pass the entry of the first vertex*/
    visited[k] = 1;                                                                 /*mark the vertex as visited one*/
    for (EdgeNode *pn = pg->vertices[k].first; pn; pn = pn->next)
        TraverseDepthFirstAux(pg, pn->endpoint, pf, visited); /*aplly the traversing over each node(another vertex index)*/
}

void TraverseDepthFirst(Graph *pg, int start, void (*pf)(GraphEntry))
{
    int visited[MAXGRAGH], i;
    for (i = 0; i < pg->size; i++)
        visited[i] = 0; /*initialise the array of visited vertices*/
    TraverseDepthFirstAux(pg, start, pf, visited);

    for (i = 0; i < pg->size; i++)
        if (!visited[i]) /*for isolated  vertices*/
            TraverseDepthFirstAux(pg, i, pf, visited);
}

// to be continued