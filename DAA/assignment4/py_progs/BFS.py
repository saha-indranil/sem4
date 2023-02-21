# Write a Python program to Implement the concept of Breadth First Search algorithm.
# Apply the algorithm on the following graph:
#     A ------- D
#    / \        |\
#   /   \       | \
#  B     C      |  \
#  |     |      |   \
#  |     |      |    \
#  E --- F      G --- H

from collections import deque

def initializeMatrix(n):
    adj_matrix = []
    for i in range(n):
        row = [0] * n
        adj_matrix.append(row)
    return adj_matrix

def addEdge(adj_matrix, u, v):
    u_index = ord(u) - 65
    v_index = ord(v) - 65
    adj_matrix[u_index][v_index] = 1
    adj_matrix[v_index][u_index] = 1

def bfs(adj_matrix, start_node):
    n = len(adj_matrix)
    visited = [False] * n
    queue = deque([start_node])
    while queue:
        node = queue.popleft()
        node_index = ord(node) - 65
        if not visited[node_index]:
            visited[node_index] = True
            print("Visited:",node)
            for neighbor_index in range(n):
                if adj_matrix[node_index][neighbor_index] == 1 and not visited[neighbor_index]:
                    neighbor = chr(neighbor_index + 65)
                    queue.append(neighbor)

adj_matrix = initializeMatrix(8)
addEdge(adj_matrix, 'A', 'B')
addEdge(adj_matrix, 'A', 'C')
addEdge(adj_matrix, 'A', 'D')
addEdge(adj_matrix, 'B', 'E')
addEdge(adj_matrix, 'C', 'F')
addEdge(adj_matrix, 'E', 'F')
addEdge(adj_matrix, 'D', 'G')
addEdge(adj_matrix, 'D', 'H')
addEdge(adj_matrix, 'G', 'H')

print("BFS in Python")
bfs(adj_matrix, 'A')

# OUTPUT
# BFS in Python
# Visited: A
# Visited: B
# Visited: C
# Visited: D
# Visited: E
# Visited: F
# Visited: G
# Visited: H