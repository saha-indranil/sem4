# 8. Write a NumPy program to create a 8x8 matrix and fill it with a checkerboard pattern.

import numpy as np

my_matrix = np.zeros((8, 8), dtype=int)
my_matrix[::2, ::2] = 0
my_matrix[1::2, ::2] = 1
my_matrix[::2, 1::2] = 1
my_matrix[1::2, 1::2] = 0

print("Checkerboard pattern:")
print(my_matrix)

# OUTPUT
# Checkerboard pattern:
# [[0 1 0 1 0 1 0 1]
#  [1 0 1 0 1 0 1 0]
#  [0 1 0 1 0 1 0 1]
#  [1 0 1 0 1 0 1 0]
#  [0 1 0 1 0 1 0 1]
#  [1 0 1 0 1 0 1 0]
#  [0 1 0 1 0 1 0 1]
#  [1 0 1 0 1 0 1 0]]
