#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
// Creates functions in order to use the graph structure (adapted to our special case)

graph* CreateGraph(int nbNodes)
{
    graph* G = NULL;

    G = (graph*)malloc(sizeof(graph));
	if (!G)
		return NULL;

    G->nbNodes = nbNodes;
    G->listNodes = (node**)malloc(nbNodes*sizeof(node*));
	if (!G->listNodes)
	{
		free(G);
		return NULL;
	}
    

	return G;
}

int InsertBST(node **B , int e)
{
    if(!*B) // this is when you reach a leaf node. Here you add the element e
    {
        *B = malloc(sizeof(struct node));
        if(!*B) return 0;
        (*B)->data = e;
        (*B)->left = (*B)->right = NULL;
        return 1;
    }
    else
    {
        if((*B)->data == e) // if you find e in the tree return 0 
            return 0;
        else
            if(e < (*B)->data) // if the lement e is less than the root , go left
            {
                return InsertBST(&((*B)->left), e);
            }
            else // otherwise go right
            {
                return InsertBST(&((*B)->right), e);
            }
    }
    return 1;
}

int InitGraph(graph* G, char* filename)
{
    int nbNodes, nbEdges;
    FILE *f = fopen(filename, "r"); // Open file
    if(f == NULL) return 0; // Check if file is opened

    fscanf(f, "%d", &nbNodes); // Get number of nodes from file
    for (int i = 0; i < nbNodes; i++)
    {
        fscanf(f, "%d", &nbEdges);
        int *temp = malloc(sizeof(temp)*nbEdges);
        int counter = 0;
        for (int j = 0; j < nbEdges; j++)
        {
            fscanf(f, "%d", &temp[j]);
            counter++;
        }
        G->listNodes[i] = malloc(sizeof(node));
        (G->listNodes[i])->nbEdges = counter;
        (G->listNodes[i])->data = i+1;
        (G->listNodes[i])->left = (G->listNodes[i])->right = NULL;
        for (int j = 0; j < nbEdges; j++)
        {
            InsertBST(&(G->listNodes[i]), temp[j]);
        }
    }

    fclose(f); // close file
    return 1;
}

void FreeGraph(graph* G)
{
    if (!G)
		return;
	if (!G->listNodes)
	{
		free(G);
		return;
	}

	free(G->listNodes);
	free(G);
}