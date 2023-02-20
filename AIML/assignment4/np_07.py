# 7. Write a NumPy program to convert an array to a float type.

import numpy as np

my_array = np.array([1, 2, 3, 4])
float_array = my_array.astype('float')

print("Original array:")
print(my_array)
print("Float array:")
print(float_array)

# OUTPUT
# Original array:
# [1 2 3 4]
# Float array:
# [1. 2. 3. 4.]
