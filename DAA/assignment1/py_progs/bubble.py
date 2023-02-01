# Write a python program to perform bubble sort using dynamic memory 
# allocation. Show the running time complexity w.r.t different input cases.

import random
import time

def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1] :
                arr[j], arr[j+1] = arr[j+1], arr[j]

if __name__ == "__main__":
    n = 1000
    loops=100
    arr = [[0] * n for i in range(loops)]

    # Best Case: Array is already sorted
    for j in range(n):
        arr[0][j] = j
    start = time.time()
    for i in range(loops):
        bubble_sort(arr[0])
    end = time.time()
    print("Best Case: ", '{:.4f}'.format(end - start), "seconds")

    # Average Case: Array is random
    for i in range(loops):
        for j in range(n):
            arr[i][j] = random.randint(0, n)
    start = time.time()
    for i in range(loops):
        bubble_sort(arr[i])
    end = time.time()
    print("Average Case: ", '{:.4f}'.format(end - start), "seconds")

    # Worst Case: Array is sorted in reverse order
    for i in range(loops):
        for j in range(n):
            arr[i][j] = n - j
    start = time.time()
    for i in range(loops):
        bubble_sort(arr[i])
    end = time.time()
    print("Worst Case: ", '{:.4f}'.format(end - start), "seconds")

# OUTPUT
# Best Case:  2.8415 seconds
# Average Case:  5.2462 seconds
# Worst Case:  7.0989 seconds
