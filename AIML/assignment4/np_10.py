# 10. Write a NumPy program to append values to the end of an array.

import numpy as np

my_array = np.array([10, 20, 30])
print("Original array:")
print(my_array)

append_arr = np.array([40, 50, 60, 70, 80, 90])
my_array = np.append(my_array, append_arr)
print("Array after appending values:")
print(my_array)


# OUTPUT
# Original array:
# [10 20 30]
# Array after appending values:
# [10 20 30 40 50 60 70 80 90]
