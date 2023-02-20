# 2. Write a Numpy program to convert a list of numeric value into a one-dimensional Numpy array.

import numpy as np

my_list = [12.23, 13.32, 100, 36.32]
my_array = np.array(my_list)

print("Original list:", my_list)
print("NumPy array:", my_array)


# OUTPUT
# Original list: [12.23, 13.32, 100, 36.32]
# NumPy array: [ 12.23  13.32 100.    36.32]
