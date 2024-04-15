#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"

void InOrder(node *B);
void InOrderDFS(node *B, queue* q);
void PreOrder(node *B);
void PostOrder(node *B);
void ReverseQueue(queue* Q, node* root);
void dfs(graph *G, int visited[G->nbNodes], node *root, int n);
void DFST(graph *G, int src);
void PrintGraph(graph* G);
void topological_helper(graph * G, int index, int Visited[], stack *s);
void topological(graph *G);