# 9. Write a NumPy program to convert a list and tuple into arrays.

import numpy as np

my_list = [1, 2, 3, 4, 5, 6, 7, 8]
my_tuple = ((8, 4, 6), (1, 2, 3))
list_array = np.array(my_list)
tuple_array = np.array(my_tuple)
print("List converted to array:")
print(list_array)
print("Tuple converted to array:")
print(tuple_array)

# OUTPUT
# List converted to array:
# [1 2 3 4 5 6 7 8]
# Tuple converted to array:
# [[8 4 6]
#  [1 2 3]]
