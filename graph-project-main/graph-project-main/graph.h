#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left, *right;
    int matched;
    int nbEdges;
} node;

typedef struct graph
{
    int nbNodes;
    struct node **listNodes;
} graph;

graph* CreateGraph(int nbNodes);
int InsertBST(struct node **B , int e);
int InitGraph(graph* G, char* filename);
void FreeGraph(graph* G);