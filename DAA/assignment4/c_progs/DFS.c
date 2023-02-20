#include <stdio.h>
#include <stdbool.h>

#define nodes 8

void addEdge(int adj_matrix[nodes][nodes], char src, char dest)
{
    int src_index = (int)(src - 'A');
    int dest_index = (int)(dest - 'A');
    adj_matrix[src_index][dest_index] = 1;
    adj_matrix[dest_index][src_index] = 1;
}

void dfs(int adj_matrix[nodes][nodes], bool visited[nodes], int current_node)
{
    visited[current_node] = true;
    printf("Visited: %c\n", current_node + 'A');

    for (int i = 0; i < nodes; i++)
    {
        if (adj_matrix[current_node][i] == 1 && !visited[i])
        {
            dfs(adj_matrix, visited, i);
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
    dfs(adj_matrix, visited, 0);

    return 0;
}
