#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "queue.h"
#include "stack.h"

void InOrder(node *B)
{
    if(B == NULL)
        return;
    
    InOrder(B->left);
    printf("%d ", B->data);
    InOrder(B->right);
}

void InOrderDFS(node *B, queue* q) // Inorder that returns a queue rather than printing the data
{
    if(B == NULL)
        return;
    
    InOrderDFS(B->left, q);
    EnQueue(q, B->data);
    InOrderDFS(B->right, q);
}

void PreOrder(node *B)
{
	if(B == NULL)
        return;

	printf("%d ", B->data);
	PreOrder(B->left);
	PreOrder(B->right);
}

void PostOrder(node *B)
{
	if(B == NULL)
        return;

	PostOrder(B->left);
	PostOrder(B->right);
	printf("%d ", B->data);
}

void ReverseQueue(queue* Q, node* root) // Reverse a queue using DFS
{
    queue q = CreateQueue();
    InOrderDFS(root, &q);
    for (int i = 0; i < q.length; i++)
    {
        EnQueue(Q, q.data[i]);
    }
}

void dfs(graph *G, int visited[G->nbNodes], node *root, int n)
{
    int i;

    // mark the current vertex as visited and print it
    if (visited[root->data-1] != 1)
    {
        visited[root->data-1] = 1;
        printf("%d ", root->data);
    }

    // recursively traverse all adjacent vertices of the current vertex
    if (root->left != NULL)
    {
        node *head = root->left;
        for (i = 0; i < n; i++) {
            if (head->data == i+1 && !visited[i]) {
                if (G->listNodes[head->data-1]->left || G->listNodes[head->data-1]->right)
                    dfs(G, visited, G->listNodes[head->data-1], n); // Traverse the neigbouring nodes' BST
                dfs(G, visited, head, n); // Traverse the current BST
            }
        }
    }
    if (root->right != NULL)
    {
        node *head = root->right;
        for (i = 0; i < n; i++) {
            if (head->data == i+1 && !visited[i]) {
                if (G->listNodes[head->data-1]->left || G->listNodes[head->data-1]->right)
                    dfs(G, visited, G->listNodes[head->data-1], n);
                dfs(G, visited, head, n);
            }
        }
    }
}

void DFST(graph *G, int src)
{
    int used[G->nbNodes];
    for(int i = 0; i < G->nbNodes; i++) // Initialize the used list to 0
        used[i] = 0;
    node *root = G->listNodes[src]; // Define the starting node
    dfs(G, used, root, G->nbNodes);
}

void PrintGraph(graph* G)
{
    for (int i = 0; i < G->nbNodes; i++)
    {
        InOrder(G->listNodes[i]);
        printf("\n");
    }
    printf("\n");
}

void topological_helper(graph * G, int index, int Visited[], stack *s)
{
	node * head;

    head = G->listNodes[index]->left;
	while(head != NULL)
	{
		if(!Visited[head->data])
	    {
	        Visited[head->data] = 1;
	        topological_helper(G, head->data, Visited, s);
	    }
	    head = head->left;
	}

    // Functions doubled since it is not a list but rather a BST with a left and right child
    head = G->listNodes[index]->right;
	while(head != NULL)
	{
		if(!Visited[head->data])
	    {
	        Visited[head->data] = 1;
	        topological_helper(G, head->data, Visited, s);
	    }
	    head = head->right;
	}
	Push(s, index);
}

void topological(graph *G)
{
	stack s;	
	int i;
	int *Visited;
	element e;

	s = CreateStack();
	Visited = (int *)malloc(G->nbNodes * sizeof(int));
	for (i = 0; i < G->nbNodes; i++)
		Visited[i] = 0;

	// this loop is required if the graph has more than one component
	for (i = 0; i < G->nbNodes; i++)
    {
		if (!Visited[i])
		{
			Visited[i] = 0;
			topological_helper(G, i, Visited, &s);
		}
    }
	while(Top(s, &e) && Pop(&s) && printf("%d ", e+1));
}