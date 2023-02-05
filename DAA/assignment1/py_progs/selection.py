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
    
if __name__ == "__main__":
    n = 5000
    arr = []
    print("Selection Sort in Python")
    print("Input size:", n)

    # Best Case: Array is already sorted
    for i in range(n):
        arr.append(i) 
    start = time.time()
    selection_sort(arr)
    end = time.time()
    print("Best Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Average Case: Array is random
    for i in range(n):
        arr.append(random.randint(0, n))
    start = time.time()
    selection_sort(arr)
    end = time.time()
    print("Average Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

    # Worst Case: Array is sorted in reverse order
    for i in range(n):
        arr.append(n-i)
    start = time.time()
    selection_sort(arr)
    end = time.time()
    print("Worst Case:", '{:.4f}'.format(end - start), "seconds")
    arr.clear()

# OUTPUT
# Selection Sort in Python
# Input size: 5000
# Best Case: 0.5356 seconds
# Average Case: 0.5583 seconds
# Worst Case: 0.5813 seconds