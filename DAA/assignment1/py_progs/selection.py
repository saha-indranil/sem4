# Write a python program to perform selection sort using dynamic memory 
# allocation. Show the running time complexity w.r.t different input cases.

import random
import time

def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
                arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

if __name__ == "__main__":
    n = 1000
    loops=100
    arr = [[0] * n for _ in range(loops)]

    # Best Case: Array is already sorted
    for j in range(n):
        arr[0][j] = j
    start = time.time()
    for i in range(loops):
        selection_sort(arr[0])
    end = time.time()
    print("Best Case: ", '{:.4f}'.format(end - start), "seconds")

    # Average Case: Array is random
    for i in range(loops):
        for j in range(n):
            arr[i][j] = random.randint(0, n)
    start = time.time()
    for i in range(loops):
        selection_sort(arr[i])
    end = time.time()
    print("Average Case: ", '{:.4f}'.format(end - start), "seconds")

    # Worst Case: Array is sorted in reverse order
    for i in range(loops):
        for j in range(n):
            arr[i][j] = n - j - 1
    start = time.time()
    for i in range(loops):
        selection_sort(arr[i])
    end = time.time()
    print("Worst Case: ", '{:.4f}'.format(end - start), "seconds")

# OUTPUT
# Best Case:  2.4089 seconds
# Average Case:  2.3095 seconds
# Worst Case:  5.0511 seconds