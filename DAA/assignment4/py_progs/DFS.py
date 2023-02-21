# Write a Python program to Implement the concept of Depth First Search algorithm.
# Apply the algorithm on the following graph:
#     A ------- D
#    / \        |\
#   /   \       | \
#  B     C      |  \
#  |     |      |   \
#  |     |      |    \
#  E --- F      G --- H

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

def dfs(adj_matrix, start_node, visited=None):
    if visited is None:
        visited = set()
    node_index = ord(start_node) - 65
    visited.add(start_node)
    print("Visited:", start_node)
    for neighbor_index in range(len(adj_matrix[node_index])):
        if adj_matrix[node_index][neighbor_index] == 1:
            neighbor = chr(neighbor_index + 65)
            if neighbor not in visited:
                dfs(adj_matrix, neighbor, visited)


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

print("DFS in Python")
dfs(adj_matrix, 'A')

# OUTPUT
# DFS in Python
# Visited: A
# Visited: B
# Visited: E
# Visited: F
# Visited: C
# Visited: D
# Visited: G
# Visited: H