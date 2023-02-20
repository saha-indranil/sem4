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

void bfs(int adj_matrix[nodes][nodes], bool visited[nodes], int start)
{
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

    // Perform breadth-first search
    bool visited[nodes] = {false};
    bfs(adj_matrix, visited, 0);

    return 0;
}
