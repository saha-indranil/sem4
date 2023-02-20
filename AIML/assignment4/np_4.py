# 4. Write a NumPy program to create a null vector of a size 10 and update sixth value with 11.

import numpy as np

my_vector = np.zeros(10)
print(my_vector)

my_vector[5] = 11
print("Update sixth value to 11")
print(my_vector)


# OUTPUT
# [0. 0. 0. 0. 0. 0. 0. 0. 0. 0.]
# Update sixth value to 11
# [ 0.  0.  0.  0.  0. 11.  0.  0.  0.  0.]
