# 6. Write a NumPy program to reverse an array.

import numpy as np

my_array = np.arange(12, 38)
reversed_array = my_array[::-1]
print("Original array:")
print(my_array)
print("Reversed array:")
print(reversed_array)

# Original array:
# [12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37]
# Reversed array:
# [37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12]
