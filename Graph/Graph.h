#ifndef GRAPH_H
#define GRAPH_H

#define MAXGRAGH 10 /*in mixed implementation there is a maximum size of the graph vertices*/

typedef struct element
{
    int data;
} Element;

typedef Element GraphEntry; /*this data type of the entries of the graph and can be defined as what ever you want*/

typedef struct edgenode /*this data type of the edge node in the liked-list connected to each vertex*/
{
    int endpoint; /*each node consists of an endpoint(the adjacent to the vertex) and a pointer to the next node in the linked-list*/
    struct edgenode *next;
} EdgeNode;

typedef struct vertex /*this data type of the vertex of the graph*/
{
    GraphEntry entry; /*each vertex consists of an entry and a pointer to the first node in the linked-list connected to the vertex*/
    EdgeNode *first;
} Vertex;

typedef struct graph /*this data type of the graph itself*/
{
    int size; /*each graph consists of a size field and an array of vertices of size MAXGRAGH*/
    Vertex vertices[MAXGRAGH];
} Graph;

void CreateGraph(Graph *);                                   /*this function takes the pointer of the graph*/
void TraverseDepthFirst(Graph *, int, void (*)(GraphEntry)); /*this function takes the pointer of the graph and the pointer of the functoin that will visit the entries*/

#endif