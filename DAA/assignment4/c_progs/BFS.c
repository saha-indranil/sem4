// Write a C program to Implement the concept of Breadth First Search algorithm.
// Apply the algorithm on the following graph:
//     A ------- D
//    / \        |\
//   /   \       | \
//  B     C      |  \
//  |     |      |   \
//  |     |      |    \
//  E --- F      G --- H

#include <stdio.h>
#include <stdbool.h>

#define nodes 8

void addEdge(int adj_matrix[nodes][nodes], char u, char v)
{
    int u_index = (int)(u - 'A');
    int v_index = (int)(v - 'A');
    adj_matrix[u_index][v_index] = 1;
    adj_matrix[v_index][u_index] = 1;
}

void bfs(int adj_matrix[nodes][nodes], bool visited[nodes], char start_node)
{
    int start = (int)(start_node - 'A');
    int queue[nodes];
    int front = -1, rear = -1;
    visited[start] = true;
    queue[++rear] = start;
    while (front != rear)
    {
        int current_node = queue[++front];
        printf("Visited: %c\n", current_node + 'A');
        for (int i = 0; i < nodes; i++)
        {
            if (adj_matrix[current_node][i] == 1 && !visited[i])
            {
                visited[i] = true;
                queue[++rear] = i;
            }
        }
    }
}

int main()
{
    printf("BFS in C\n");
    int adj_matrix[nodes][nodes] = {0};

    addEdge(adj_matrix, 'A', 'B');
    addEdge(adj_matrix, 'A', 'C');
    addEdge(adj_matrix, 'A', 'D');
    addEdge(adj_matrix, 'B', 'E');
    addEdge(adj_matrix, 'C', 'F');
    addEdge(adj_matrix, 'E', 'F');
    addEdge(adj_matrix, 'D', 'G');
    addEdge(adj_matrix, 'D', 'H');
    addEdge(adj_matrix, 'G', 'H');

    bool visited[nodes] = {false};
    bfs(adj_matrix, visited, 'A');

    return 0;
}

// OUTPUT
// BFS in C
// Visited: A
// Visited: B
// Visited: C
// Visited: D
// Visited: E
// Visited: F
// Visited: G
// Visited: H