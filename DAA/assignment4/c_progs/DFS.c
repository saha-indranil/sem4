// Write a C program to Implement the concept of Depth First Search algorithm.
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

void dfs(int adj_matrix[nodes][nodes], bool visited[nodes], char current_node)
{
    int current = (int)(current_node - 'A');
    visited[current] = true;
    printf("Visited: %c\n", current_node);

    for (int i = 0; i < nodes; i++)
    {
        if (adj_matrix[current][i] == 1 && !visited[i])
        {
            dfs(adj_matrix, visited, (char)('A' + i));
        }
    }
}

int main()
{
    printf("DFS in C\n");
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

    // Perform depth-first search
    bool visited[nodes] = {false};
    dfs(adj_matrix, visited, 'A');

    return 0;
}

// OUTPUT
// DFS in C
// Visited: A
// Visited: B
// Visited: E
// Visited: F
// Visited: C
// Visited: D
// Visited: G
// Visited: H