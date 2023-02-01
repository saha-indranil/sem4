# Write a python program to perform insertion sort using dynamic memory 
# allocation. Show the running time complexity w.r.t different input cases.

import random
import time

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

if __name__ == "__main__":
    n = 1000
    loops=100
    arr = [[0] * n for i in range(loops)]

    # Best Case: Array is already sorted
    for j in range(n):
        arr[0][j] = j
    start = time.time()
    for i in range(loops):
        insertion_sort(arr[0])
    end = time.time()
    print("Best Case: ", '{:.4f}'.format(end - start), "seconds")

    # Average Case: Array is random
    for i in range(loops):
        for j in range(n):
            arr[i][j] = random.randint(0, n)
    start = time.time()
    for i in range(loops):
        insertion_sort(arr[i])
    end = time.time()
    print("Average Case: ", '{:.4f}'.format(end - start), "seconds")

    # Worst Case: Array is sorted in reverse order
    for i in range(loops):
        for j in range(n):
            arr[i][j] = n - j
    start = time.time()
    for i in range(loops):
        insertion_sort(arr[i])
    end = time.time()
    print("Worst Case: ", '{:.4f}'.format(end - start), "seconds")

# OUTPUT
# Best Case:  0.0151 seconds
# Average Case:  2.5529 seconds
# Worst Case:  4.7800 seconds