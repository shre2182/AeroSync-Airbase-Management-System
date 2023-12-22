#include <stdio.h>
#include <limits.h>

#define MAX_VERTICES 10


void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices);

int main() {
    int vertices;
    printf("Enter the number of vertices (max %d): ", MAX_VERTICES);
    scanf("%d", &vertices);

    if (vertices <= 0 || vertices > MAX_VERTICES) {
        printf("Invalid number of vertices\n");
        return 1;
    }

    

    int graph[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix for the graph:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nMenu:\n");
    printf("1. Find Minimum Spanning Tree\n");
    printf("2. Exit\n");

    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            primMST(graph, vertices);
            break;
        case 2:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Exiting...\n");
            break;
    }

    return 0;
}


int minKey(int key[], int mstSet[], int vertices) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < vertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}


void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}


void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices) {
    int parent[MAX_VERTICES]; 
    int key[MAX_VERTICES];    
    int mstSet[MAX_VERTICES]; 

    for (int i = 0; i < vertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }

    
    key[0] = 0;
    parent[0] = -1; 

    
    for (int count = 0; count < vertices - 1; count++) {
        int u = minKey(key, mstSet, vertices);

        mstSet[u] = 1; 

        
        for (int v = 0; v < vertices; v++) {
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    
    printf("Minimum Spanning Tree using Prim's Algorithm:\n");
    printMST(parent, graph, vertices);
}
