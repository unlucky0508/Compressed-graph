#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#include "functions.h"

int main()
{
    char filename[] = "data.txt"; // Input file with vertices and edges
    int nbNodes;

    FILE *f = fopen(filename, "r"); // Open file
    if(f == NULL) return 0; // Check if file is opened
    fscanf(f, "%d", &nbNodes); // Get number of nodes from file
    fclose(f); // close file

    graph *G = CreateGraph(10);
    InitGraph(G, filename);

    system("clear");
    while (1)
    {
        int choice = 0, parameter;
        printf("Choose:\n  1|Print graph\n  2|DFS Traversal\n  3|Topological sorting\n  4|Quit\n");
        scanf(" %d", &choice);
        system("clear");
        if (choice == 1)
        {
            PrintGraph(G);
        }
        else if (choice == 2)
        {
            printf("Start at which node(1-10)? ");
            scanf(" %d", &parameter);
            printf("DFS traversal: ");
            DFST(G, parameter-1);
            printf("\n\n");
        }
        else if (choice == 3)
        {
            printf("Topological sorting: ");
            topological(G);
            printf("\n\n");
        }
        else if (choice == 4)
        {
            break;
        }
    }
    system("clear");

    FreeGraph(G);
    return 0;
}