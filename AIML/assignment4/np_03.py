# 3. Write a NumPy program to create a 3x3 matrix with values ranging from 2 to 10.

import numpy as np

my_matrix = np.arange(2, 11).reshape(3, 3)
print(my_matrix)

# OUTPUT
# [[ 2  3  4]
#  [ 5  6  7]
#  [ 8  9 10]]
